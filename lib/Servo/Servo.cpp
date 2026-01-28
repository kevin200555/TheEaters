// src/Servo.cpp
#include "ServoHeader.h"
#include <Arduino.h>

// Define servo pin and mid-point angle
Servo servo;
int angle = ServMid;

// Setup function to initialize the servo
void LargeServoSetup() {
  servo.attach(LargeServIn); // Attach the servo to pin 8
  servo.write(ServMid); // Set servo to mid-point (90 degrees)
}

void SmallServoSetup2() {
  servo.attach(SmallServIn); // Attach the servo to pin 10
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

void ServoLeft(){
  Serial.println("Moving servo to leftmost position");
  servo.write(ServLeft);
  delay(15);
}

void ServoRight(){
  Serial.println("Moving servo to rightmost position");
  servo.write(ServRight);
  delay(15);
}

void ServoSetAngle(int targetAngle){
  Serial.print("Setting servo to angle: ");
  Serial.println(targetAngle);
  servo.write(targetAngle);
  delay(15);
}