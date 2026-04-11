Lab 4 - Interrupts and Modal Behavior


Prelab

1. Which NVIC interrupt trigger type should I pick to respond exactly once when button A is pressed, with the lowest latency?

I'd use falling edge. Button A ties GPIO 25 to ground through the switch and the pin has a pull-up, so when you press the button the line goes from high to low. Falling edge fires the instant that transition happens, so latency is basically one cycle. If I picked low-level instead the handler would keep firing the whole time the button is held down, which is the opposite of "exactly once". Rising edge would only trigger on release which still works but feels a cycle late since the press already happened a while ago. High-level doesnt make sense here because the resting state is high so the interrupt would just constantly be firing whenever nothing is happening.

2. What do you call it when one interrupt preempts another, and whats needed for it to happen?

Thats called nested interrupts (or preemption). For it to happen the new interrupt has to have a higher priority than the one currently running, and nesting has to actually be allowed by the NVIC (on Cortex-M0+ its based on priority levels). If every interrupt has the same priority none of them can preempt each other.

3. What affects latency when the processor gets a low-priority external interrupt?

A bunch of things. If something higher priority is already running you have to wait for it to finish. The CPU also has to finish the current instruction (some take more cycles than others), then push state to the stack, then vector to the handler. Memory wait states or flash access can add cycles. And if interrupts were temporarily disabled in a critical section you have to wait for them to be re-enabled. Pipeline flushing on the Cortex-M matters too.

4. Is this send_to_radio() function reentrant (the one with the static buffer)?

No its not reentrant. The problem is the static buffer, because its shared between all calls. If the function is in the middle of writing to that buffer and then an interrupt fires and calls send_to_radio again, the second call will clobber whatever the first one was doing. When control comes back to the first call its working on corrupted data.

The fix is to not use a static buffer. Either make it a local variable on the stack so each call has its own copy, or if the buffer has to be big enough that you cant put it on the stack, disable interrupts around the critical section (or use a mutex on a threaded system). Local stack buffer is the cleaner option.


6.2 ISR Implementation

I made two versions. ButtonCallback.lf uses gpio_set_irq_enabled_with_callback directly and prints from inside the ISR. It works but printing from inside an ISR is sketchy because stdio isnt really ISR safe.

The better version is ButtonAction.lf. The callback is dead simple, all it does is call lf_schedule on a physical action. The real work happens in the reaction that fires on that action, which runs at normal program time instead of in the interrupt context. I keep the action pointer in a static global so the plain C callback can get to it. Inside the reaction I grab the logical elapsed time and print the gap since the last press, which shows how LF timestamps physical actions based on when the event actually arrived.


6.3 Debouncing

ButtonDebounced.lf adds a timestamp check. Every time the callback fires it checks lf_time_physical() against the last edge time and ignores anything within 200ms. If I didnt do this, one physical button press would log as 3-5 separate presses because the switch contacts bounce for a few ms. 200ms is longer than any real bounce but still short enough that you cant tell as a human, and it stops a fast double-tap from merging.


6.4 Modal Counter

ModalCounter.lf has a Counter reactor with two modes, UP and DOWN. UP has a 250ms timer that increments the state, DOWN has a 500ms timer (half the rate like the spec said) that decrements. The toggle input switches between modes using lf_set_mode with reset so the mode starts fresh each time. The main reactor wires the debounced button press into toggle and pipes the count plus a label to the Display reactor. Pressing button A flips between counting up and counting down, and the LCD shows both the direction and current value.


Lab 4 Additional Tasks

1. What interrupts does the RP2040 support?

The RP2040 has a Cortex-M0+ with an NVIC that supports 32 interrupt lines (IRQ 0-31). The main ones are the GPIO bank interrupts (IO_IRQ_BANK0, IO_IRQ_QSPI) which cover level-high, level-low, rising-edge, and falling-edge triggers on any of the 30 GPIO pins. Theres also interrupts for each of the timers (TIMER_IRQ_0 through 3), the two UARTs, both SPIs, both I2Cs, DMA (two channels worth), PIO (each of the 4 state machines per PIO block), USB, RTC, ADC FIFO, watchdog, XIP flash, PWM wrap, and the clocks. Plus the standard ARM exceptions like SysTick, PendSV, SVC, HardFault and NMI that arent really "peripheral" interrupts but still go through the NVIC.

Priority on M0+ has 4 levels (2 bits) which is less than M3/M4. Doesnt support true vectored priority with subpriorities, just the 4 preemption levels.

2. Accelerometer wake interrupt

AccelWakeup.lf samples the accelerometer at 50ms. First it runs 20 samples of calibration while the robot is sitting still to figure out baseline x/y/z (should be roughly (0, 0, 1g) if the robot is flat but calibrating lets it work at any orientation). After that its calibrated and every sample computes the delta from baseline. If the delta magnitude is over 0.1g it flags the robot as "awake", turns on the LED, and prints a message. A second timer clears the LED after ~150ms so its a quick flash instead of staying on.

I put the threshold at exactly 0.1g like the prompt said. In practice that catches any real jostle but not normal vibration or sensor noise, which is around 0.02-0.05g on my desk.

On filter levels and sample rate: when I tried sampling at 10ms (100 Hz) the flash fired on nothing because I was catching noise spikes. Slowing to 50ms gives some natural averaging and makes it way less twitchy. Going the other way to 200ms missed fast taps on the chassis. 50ms felt like the sweet spot. If I was using the IMUs built in low-pass filter I could bump the rate back up and let hardware do the smoothing, but for a simple wake signal the software approach is fine.


Postlab

1. Logical vs physical time in LF

Physical time is just wall clock time, whatever the hardware clock says right now. Logical time is what the LF runtime assigns to events, and the whole point of LF is that reactions at the same logical time behave deterministically regardless of when they actually run on the CPU. For a regular timer they're the same thing more or less, but for a physical action the logical timestamp is set when lf_schedule is called (which is roughly "when the real world event happened"), and then the reaction runs shortly after that in physical time but sees the earlier logical time. The gap between them is basically scheduling latency. In my ButtonAction reactions the logical timestamp is when the ISR ran, not when the reaction body ran, so printing the logical elapsed time actually tells you when the press really happened.

2. ISR crashes when calling printf

Printf is a bad idea inside an ISR for a few reasons. It uses stdio which may have internal locks or buffers that arent interrupt safe, and if it was already in the middle of a printf when the interrupt fired you can deadlock or corrupt the buffer. It also allocates on the stack and walks through a bunch of format code, which eats time in the ISR when youre supposed to get in and out fast. And with the pico SDK stdio goes over USB-CDC which has its own state machine that really doesnt want to be called from interrupt context.

To make it work you could either switch stdio to use the UART instead of USB (UART writes are just register pokes so they're mostly ISR safe), or implement a tiny ring buffer where the ISR just memcpy's the string in and a background loop does the actual printing. The SDK also has a lockout thing you can disable for stdio but its risky.

The consequence of just forcing printf to work from the ISR is that you might corrupt stdout state for the main program, lose characters in concurrent prints, get weird interleaving, or just hang the USB stack. For debugging its tempting but in real code youd want the ring buffer approach.

3. Other debugging approaches instead of printf

GPIO toggling is the classic. Just wiggle a free pin high when you enter a region and low when you leave, then put a scope or logic analyzer on it. Super fast, no stdio involvement, and you can see timing down to microseconds. The catch is you need the hardware and a free pin.

LEDs work if you only need to know "did this path run". Limited but zero risk.

SWD debugger with gdb/openocd is the proper answer. You can set breakpoints, inspect memory, see registers, and even halt the CPU inside an ISR without any of the printf risks. Downside is setup and that halting the CPU messes with real-time behavior, so some bugs disappear when you break.

A ring buffer logger in RAM that you dump later. Cheap to write from anywhere, no locking if you make it single-producer single-consumer, and you can read it out over SWD or over serial when the main loop gets around to it. This is what I'd actually use.

Consequences: gdb can mask timing bugs, printf can cause the bugs you're trying to find, and ring buffers use RAM you may not have. Every method trades something.

4. Takeaways

The physical action pattern is the biggest thing I want to remember from this lab. Before it, my instinct for handling a button was to put everything inside the callback, but that mixes ISR context with normal code and gets ugly fast. Having the callback be a single lf_schedule and then doing real work in a reaction is way cleaner and also gives you deterministic logical timestamps for free.

Debouncing being done in software with a timestamp comparison is also something I hadnt really thought about before. I assumed you needed an RC filter on the hardware side but a 200ms gap check in the ISR does the job with zero extra parts.

Modes in LF were new to me and I think really cool. Having two timers that only exist inside their own mode means I dont need a big state machine with if/else in a reaction, the runtime handles it. The diagram makes a ton more sense than the equivalent spaghetti would.

Surprising thing: the accelerometer is noisy enough at rest that you genuinely have to calibrate and threshold carefully to avoid false wakes. I thought "0.1g, should be easy" but with raw readings I was getting fake triggers until I added the baseline subtraction. Also a bit surprised that printf from an ISR works at all sometimes on the pico, which I think is what tempts people to do it even though its wrong.
