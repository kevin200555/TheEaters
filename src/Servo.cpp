// src/Servo.cpp
#include <Servo.h>
Servo servo;

// Define servo pin and mid-point angle
#define ServIn = 9
#define ServMid = 90

// Setup function to initialize the servo
void ServoSetup() {
  servo.attach(ServIn); // Attach the servo to pin 9
  servo.write(ServMid); // Set servo to mid-point (90 degrees)
}
