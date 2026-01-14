#include <Arduino.h>
#include "Camera.h"
#include "ServoHeader.h"
#include "Motors.h"
#include "IRSensor.h"
// put function declarations here:


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Starting...");
  MotorsSetup();
  Serial.println("Motors Setup!");
  CameraSetup();
  Serial.println("Camera Setup!");
  ServoSetup();
  Serial.println("Servo Setup!");
  IRsensorSetup();
  Serial.println("IRsensors Setup!");

}

void loop() {
  // put your main code here, to run repeatedly:
  MotorsLoop();
  CameraLoop();
  int sensorValue = IRsensorLoop();
  delay(100);
}

// put function definitions here:
