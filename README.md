# Arduino-Temperature-Based-LED-Control

## Overview

This Arduino project interfaces with an LM35 temperature sensor and controls the onboard LED on an Arduino Uno based on temperature readings. When the temperature falls below a specified threshold, the LED blinks at one rate, and when the temperature exceeds the threshold, it blinks at a different rate.

## Components

- Arduino Uno
- LM35 Temperature Sensor
- Jumper Wires

## Dependencies

- [TaskScheduler library](https://www.arduino.cc/reference/en/libraries/taskscheduler/) (if used)

## Installation

1. Download the zip file to your local machine from this website.

2. If you are using the TaskScheduler library, make sure to install it using the Arduino Library Manager.

3. Connect the LM35 temperature sensor to Analog pin A0 on the Arduino Uno. Ensure the power and ground connections are correctly set up.

4. Open the `Arduino-Temperature-Based-LED-Control.ino` file in the Arduino IDE.

5. Upload the sketch to your Arduino Uno.

##Connections
![image](https://github.com/deeptib14/Arduino-Temperature-Based-LED-Control/assets/110586767/9a4e0022-b170-48c7-8b5d-f4736efaddce)


## Usage

1. Upload the sketch to the Arduino Uno.

2. Monitor the temperature readings in the Arduino IDE's Serial Monitor.

3. Observe the onboard LED's behavior as it blinks according to the temperature conditions(When the temperature falls below 30 degrees Celsius,onboard LED
blink every 250 milliseconds, and 500 milliseconds if temperature raises above 30 degrees Celsius).

4. Adjust the temperature threshold or LED blinking intervals as needed.



