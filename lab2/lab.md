1. Change the low pass filter or signal conditioning setting to different options. Do you notice a difference
in the noise levels?

**Answer:** Yes, chaning the low pass filter results in different noise level. We tested three values of the CRTL8_XL register at 0x00, 0x80, and 0xC0. Each subsequent register value had less noise, resulting in less jiterry pitch and roll values.

2. Explore the different operating modes for the accelerometer in the datasheet and describe them. What
changes would be needed to implement all the modes? We will explore interrupt-based methods in a
future lab.

**Answer:** The different operating modes control the power/performance tradeoff modes. Lower ODR settings mean less power consuption and higher ODR settings means faster/more accurate(?) readings but they consume more power. High performance also means less noise. Right now, the program is asking the acclerometer for data every 100ms, but in future labs we could implement interrupt-based methods where instead of asking for data, the accelerometer tells us when new data is ready via interrupts. This is important for high ODR modes because 100ms is far too slow to be asking for new data.

3. Determine the register settings needed to change the range of accelerometer values. What are the
trade-offs when we change the range? Change the range to the highest value and observe changes in
the accelerometer values.

**Answer:** To change the range of accelerometer values, we need to change uint8_t fs_acc which writes to CRTL1_XL bits 3 and 2. We changed this variable to 0b01 to change the range to 16g! Now, the values seem to be noiser because the range is much larger, meaning that the resolution is poorer. Same number of bits for a larger range.

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

**Answer:** The sens is 1/213, so to get the raw count we do 1.0/(1/213) = 8197 in decimal. Converted to hex: 0x2005. Converted to binary: 0010000000000101. 

2. Suppose that your goal with the accelerometer is to measure the tilt in degrees of the surface on which your robot is moving. How would you measure the bias and then compensate for this bias?

**Answer:** Use a level to find a flat surface and place the robot on it. Then, take a bunch of samples of the tilt on the flat surface. The average of these samples is the bias, and we can compensate by substracting this bias from every subsequent reading. 

3. Suppose that your goal is to orient the robot to point straight up the hill. How would you use the pitch and roll measurements to accomplish this?

**Answer:** We're assuming straight up the hill means on the hill and pointed directly up the slope. To do this, roll needs to be 0 so that the robot is level side to side, therefore pointing it directly up the slope. The pitch would measure the angle of the hill and isn't needed to point the robot straight up the hill, assuming the hill is just one angle and doesn't change.

4. What were your takeaways from the lab? What did you learn during the lab? Did any results in the lab surprise you?

**Answer:** Fun lab! First time I've ever edited the registers on an MCU. It was challenging to find where exactly the code went but satisfying to see it work. I also got to learn how pitch and roll are calculated and tradeoffs between measurement range & resolution, performance and power.