# Lab 1 Report

## Prelab

1. **`ls -a` flag**: Shows all files, including hidden ones (those starting with `.`).

2. **`cd ..`**: Moves to the parent directory of the current one.

3. **Difference between `mv` and `cp`**: `mv` moves a file completely (removing it from the original location), while `cp` just copies it (keeping the original).

4. **`ls -h` command**: Prints sizes in human readable units (e.g., KB, MB, GB).

5. **Git status**: Shows whether you have local changes and describes what the changes are.

6. **Git pull**: Fetches any updates from the remote repo and merges them automatically into the current branch.

## Postlab

1. **Float format specifiers**: Use `%f` for fixed point floats, `%e` for scientific notation, and `%g` for the shortest representation.

2. **When printf debugging is best**: When you don't have a full debugger or if you want to see real-time behavior without halting the CPU.

3. **Testing/debugging embedded code without hardware**: Unit tests with simulators like QEMU, static analysis if you can get it to work, functional testing where you're testing known outputs.

4. **Volatile keyword in C**: Forces the compiler to not optimize read/writes with things like caching, as it means that the variable's value can change outside the program's normal flow (e.g., hardware registers, interrupt handlers).

5. **Key takeaways**: Figuring out how the environment actually works with the robot and how you can export code onto it, and how Lingua Franca uses a very interesting system of compiling both C and its own unique language. Also learned how to handle things like LED lights and what that looks like within Lingua Franca.

## Code Report

We decided to follow the example the lab mentioned of making the LED lights modular so we went down that route.

**ToolsLEDSolution.lf**: The application file that targets RP2040 C code, instantiates the LED reactor from lib/LED.lf, and uses a timer that fires every second to toggle the persistent `led_on` state, print it out for debugging, then set that boolean to `led.set` via `lf_set` so we know it's been set.

**LED.lf**: The LED hardware driver that actually turns on the light. It defines the LED reactor with an input port where we set a variable `set` to a bool, then initializes the board's default LED GPIO pin on startup, and whenever a set value arrives it turns it on or off based on the boolean.

In simple terms, ToolsLEDSolution.lf handles the logic with the timing and when to turn things on/off, and LED.lf handles physically turning on or off the lights.
