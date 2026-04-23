Lab 5 - Robot


Prelab

1. Which sensors on the robot are most useful for detecting obstacles?

The bump sensors on the front bar are the obvious one since they're specifically meant for hitting stuff. The accelerometer can also help because if the robot crashes into something and suddenly decelerates the IMU spikes, which you can use as a fallback when the bump switches miss. The line sensors technically share hardware with the bump sensors so you pick one or the other. If you had extra hardware a distance sensor (IR or ultrasonic) would be better since its non-contact but the stock robot doesnt come with one.

2. Converting angular velocity samples to an angle estimate

If you have samples v_i of angular velocity in degrees per second taken at times t_i, you integrate numerically. The simplest is rectangular: a_i = a_(i-1) + v_i * (t_i - t_(i-1)). More accurate is the trapezoidal rule which averages the current and previous sample: a_i = a_(i-1) + (v_i + v_(i-1)) / 2 * (t_i - t_(i-1)). The IMU.lf library already has a TrapezoidalIntegrator reactor that does exactly that, which is what GyroAngle uses.

3. Which GPIOs drive the motors?

Looking at the Pololu 3pi+ 2040 users guide the motor driver takes 4 PWM inputs: left forward (GPIO 10), left reverse (GPIO 11), right forward (GPIO 14), right reverse (GPIO 15). The RP2040 maps each of those to a PWM slice. 10/11 are slice 5 and 14/15 are slice 7. You PWM the direction you want and hold the other low, which gives you proportional power in one direction.

4. State machine for a square

Simple FSM with two states:

FORWARD: drive both motors, accumulate distance from encoders. When distance >= D, transition to TURNING.

TURNING: spin in place (one motor forward one motor reverse), accumulate heading from gyro. When heading change >= 90 degrees, transition back to FORWARD.

Loop forever. You can count edges if you only want one square then stop.


7.2 Motors and RobotDrive.lf

motors_set_power takes a duty cycle, a forward/reverse flag, and a left/right flag. Under the hood it writes to one of the two PWM slices depending on the left flag. If forward is true it sets the forward pin to the duty cycle and clears the reverse pin. If reverse it does the opposite. The Motors reactor in the lib just takes a float from -1 to +1, decides direction by sign, clamps magnitude to 1, converts to MAX_MOTOR_POWER * power for the duty cycle, then calls motors_set_power. Clean abstraction.

RobotDrive.lf extends RobotTemplate so the STOPPED mode sets both powers to 0 and the DRIVING mode sets both to 0.1f. The toggle timer flips modes every 2 seconds. On my robot 0.1 is right at the threshold where the motors barely start moving, 0.15 is a more reliable "this is definitely moving" power.

One gotcha: motors won't run on USB power alone. I had to put the batteries in and hit the power button so the blue LED came on.


7.3 Encoders and RobotEncoder.lf

Wheel diameter is 3.175 cm so circumference is pi * 0.03175 m, roughly 0.0998 m per full rotation. To convert an encoder angle in degrees to distance: distance = (angle / 360) * pi * d. The AngleToDistance reactor in RobotEncoder.lf does exactly that.

Overflow: encoder outputs are int32 which has a range of about +-2.1 billion. If the raw encoder counts correspond to sub-degree resolution the wraparound is pretty far out (probably tens of thousands of meters of driving). For a lab that runs a few meters at most I don't need to worry about it. If this were a long-running robot I'd handle it by taking diffs between samples rather than using absolute values.

I tested by rolling the robot forward about 30 cm and comparing the LCD reading to a tape measure. It was within a cm or two which is reasonable given wheel slip.


7.4 Square Navigation - RobotSquare.lf

Uses the GyroAngle reactor for heading and Encoders for distance. The SquareController reactor has two modes, FORWARD and TURNING, exactly like the FSM from prelab Q4.

FORWARD mode drives both motors at 0.15 power and uses the encoder deltas to figure out how far its gone. When the average of left and right distance exceeds 0.5 m it stops and switches to TURNING.

TURNING mode drives left motor reverse and right motor forward at 0.12 power (spin in place). It reads the GyroAngle z output and compares to the heading when the mode started. When the magnitude exceeds 90 degrees it stops and switches back to FORWARD.

A 50ms timer ticks the encoders and gyro so the controller gets fresh data.

Factors that make the square imperfect:
- wheel slip, especially on smooth floors (carpet is worse)
- slight differences between left and right motor speed at the same power
- gyro drift, if you integrate long enough the heading wanders
- encoder rounding because you can only sample at 50ms
- the robot starts turning before stopping, and stops turning before reaching exactly 90, due to inertia
- battery level changes power delivery over time

I got something roughly square-shaped, ending up maybe 15 cm from where I started after 4 edges.


7.5 Obstacle Avoidance - RobotAvoid.lf

The Bump reactor samples the two bump switches every 100ms. On startup it calibrates them, which is needed because the ambient IR varies and without calibration you get false bumps in bright light. It fires a true output on left or right whenever the corresponding switch is pressed. Note that bump and line sensors cant be used at the same time since they share pins.

RobotAvoid.lf adds two new modes to the square FSM, BACKUP and EVADE. When a bump fires while in FORWARD, the controller notes which side hit (for picking evade direction), then transitions to BACKUP. BACKUP runs both motors in reverse for ~700ms (14 ticks of 50ms). Then it transitions to EVADE which turns about 45 degrees away from the side that was hit before going back to FORWARD. This actually gets the robot around most obstacles.

Modal model: the reactor has 4 modes and uses reset transitions so the timers restart clean when you re-enter a mode.


Extra experiments

1. Different obstacle types

Cardboard box: bump sensors trigger fine, robot backs up and evades as expected.

Soft pillow: bump sensor sometimes doesnt trigger hard enough because the switch doesnt fully close against a soft surface. The robot can stall against it without ever noticing. This is where a wheel-slip check from the encoders would help.

Chair leg (narrow cylinder): hits one side of the bump bar, so the robot correctly picks the evasion direction based on left vs right.

Wall: hits both bump sensors at the same time, which I made turn in a consistent direction (the first branch wins). Could be smarter by picking randomly or alternating.

Low obstacle under the bump bar (like a book lying flat): bump bar goes over it, wheels ride up, robot tilts. Nothing detects this, which is a good case for using the accelerometer as a backup trigger.

2. Circle / oval around an object

RobotCircle.lf just sets the two motors to different powers (0.18 left, 0.10 right) so the robot arcs continuously. The ratio controls the turning radius. Running for 10 seconds gives a roughly complete loop at my scaling. To make an oval you can alternate between two wheel-speed ratios (more-different for the tight ends, less-different for the straight sides) on a timer, but the simple arc already looks like an oval on carpet because of slip.


Postlab

1. Ensuring progress when bumps are missed

Add a timeout or stuck detector. A few options:
- If encoders arent increasing while the motors are commanded forward, the robot is stuck. After say 500ms of no encoder motion, trigger the backup+evade sequence even without a bump.
- Cap each FORWARD mode with a max time so even if the distance never fills up you still transition to the next state.
- Use the accelerometer: if acceleration spikes or the robot isn't accelerating forward the way it should be given the motor command, something is wrong.

The stuck detector (encoder delta check) is probably the most robust because it catches low obstacles, soft obstacles, pinned wheels, etc, all with one check.

2. Closing the loop on speed

Use feedback control. You pick a desired speed in m/s, compute actual speed from encoder delta / time, and adjust motor power based on the error. A PI controller works well: P term brings you close to the target, I term fixes steady-state error from things like the motors needing more power at low speeds. lib/MotorsWithFeedback.lf does exactly this. Without feedback, setting power to 0.15 gives different actual speeds on carpet vs hardwood or with full vs low batteries. With feedback the speed stays close to target regardless.

3. Takeaways

Modal reactors are a much cleaner way to express robot behavior than giant if/else trees in a reaction. Each mode has its own timers and reactions that only exist while in that mode, so you dont need a million state flags.

Dead reckoning is way less accurate than I thought. Even with encoders and a gyro, after one square the robot was noticeably off from its start. This is probably why real robots use external references like cameras or lidar.

The bump sensor calibration step was a surprise. I thought they were just mechanical switches but they're actually IR based, and ambient IR level matters. This makes sense after reading the docs but wasnt obvious at first.

Battery level matters way more than I expected. With fresh batteries 0.1 power moves the robot cleanly. Once theyre a bit drained I had to bump up to 0.15 or 0.2 to get the same speed, which throws off the square timing if you dont have feedback.

Sampling rate on the gyro matters for heading accuracy. At 100ms samples the heading was visibly drifting during a single turn. At 50ms it was better. At 20ms it was tightest but reaction overhead went up. 50ms felt like the right balance for this robot.
