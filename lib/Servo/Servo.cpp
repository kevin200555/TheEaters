// src/Servo.cpp
#include "ServoHeader.h"
#include <Arduino.h>

// Define servo pin and mid-point angle


// Setup function to initialize the servo
void ServoSetup() {
  servo.attach(ServIn); // Attach the servo to pin 9
  servo.write(ServMid); // Set servo to mid-point (90 degrees)
}

void ServoLoop() {
  
}