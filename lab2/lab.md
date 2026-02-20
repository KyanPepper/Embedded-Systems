1. Change the low pass filter or signal conditioning setting to different options. Do you notice a difference
in the noise levels?

2. Explore the different operating modes for the accelerometer in the datasheet and describe them. What
changes would be needed to implement all the modes? We will explore interrupt-based methods in a
future lab.

3. Determine the register settings needed to change the range of accelerometer values. What are the
trade-offs when we change the range? Change the range to the highest value and observe changes in
the accelerometer values.

4. (Additional question) This is an extra question for your exploration. The derivative of acceleration
is often referred to as jerk or jolt. It measures the rate of change in acceleration to detect sudden
movements. Implement a state to track sudden change in acceleration (e.g., more than 0.5 g in few
milliseconds). Print a message on the display when this happens.

* 4.2 Questions
1a. Explain why, when the robot is sitting on a flat surface, the sensed accelerations in the x and y directions are near zero and in the z direction near one.

**Answer:** Gravity works in the z direction, so x and y are understandably near zero.

---

1b. Why is the z direction not near negative one? Doesn't gravitation pull you down, not up?

**Answer:** The z direction measures the normal force, which is the force pushing against gravity. Near positive one makes sense as it's pushing against the 1G of gravity.

---
2a. Open the file src/AccelerometerDisplay.lf in VS Code. Enable the diagram, navigate and read the code, and explain what each of the reactions labeled A, B, C, and D does: AccelerometerDisplay diagram

**Answer:** A is the timer that runs the acclerometer measurement every 250ms. B is the initalization cycle that runs once each measurement, initalizes the hardware. C is the communication with the physical sensors and reads the three raw values x y and z. D is the data processing reaction, which is where the pitch and roll calcuations happen, also formatting.

---

2b. Notice the target specification at the top of each of the .lf files. What do you think is the significance of the directive: single-threaded: true

**Answer:** This directive forces the Pi to run the program on a single thread. This is useful because multi-threads would add a bunch of complexity with timing and race conditions. Single threading makes programming on the Pi much more simple.

---

* Postlab
1. Suppose a sensor gives you a 16-bit signed integer representing some measured quantity in some well-defined units, that the range of the sensor in those units is -4.0 to 4.0, and that the sensitivity in those units is 0.000122 (1/213). What is representation in hex and in binary of a sensor reading of 1.0 in those units?

2. Suppose that your goal with the accelerometer is to measure the tilt in degrees of the surface on which your robot is moving. How would you measure the bias and then compensate for this bias?

3. Suppose that your goal is to orient the robot to point straight up the hill. How would you use the pitch and roll measurements to accomplish this?

4. What were your takeaways from the lab? What did you learn during the lab? Did any results in the lab surprise you?
