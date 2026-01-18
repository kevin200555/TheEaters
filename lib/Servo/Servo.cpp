// src/Servo.cpp
#include "ServoHeader.h"
#include <Arduino.h>

// Define servo pin and mid-point angle
Servo servo;
int angle = ServMid;

// Setup function to initialize the servo
void ServoSetup() {
  servo.attach(ServIn); // Attach the servo to pin 9
  servo.write(ServMid); // Set servo to mid-point (90 degrees)
}

void ServoLoop() {
  for (angle = ServLeft; angle <= ServRight; angle += 10) {
    Serial.print("Moving servo to: ");
    Serial.println(angle);
    servo.write(angle); // Move servo to the specified angle
    delay(15);
  }

  for (angle = ServRight; angle >= ServLeft; angle -= 10) {
    Serial.print("Moving servo to: ");
    Serial.println(angle);
    servo.write(angle); // Move servo back to the specified angle
    delay(15); 
  }
}