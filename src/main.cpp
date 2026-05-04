#include <Arduino.h>
// #include "Camera.h"
// #include "ServoHeader.h"
#include "Motors.h"
#include "IRSensor.h"
// bool scanArea();
// bool getTheBlock();
// bool activateClaw();
// bool returnToBase();
// bool getAway();
// bool stopMotors();
// Pixy2 pixy;

// int x = 0;
// int y = 0;
// int width = 0;
// int height = 0;

#define TICK_SPEED 1000

// this robot works on a state machine, with each state requireing a different robot action to be run
// these robot actions are scanArea(), getTheBlock(),
// enum RobotState
// {
//   SEARCHING,
//   APPROACHING,
//   PICKING,
//   RETURNING,
//   AVOID_BOUNDARY,
//   COMPLETE
// };

// these variables keep track of whether or not a certain milistone is reached, each robot action function should return a boolean value
// to verify if these milistones are met
// bool objectInSight = false;
// bool objectPickable = false;
// bool objectObtained = false;
bool onBlackLine = false;
// bool missionComplete = false;

// RobotState state = SEARCHING;

// put function declarations here:
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Starting...");
  MotorsSetup();
  Serial.println("Motors Setup!");
  // CameraSetup();
  // Serial.println("Camera Setup!");
  // LargeServoSetup();
  // SmallServoSetup2();
  // Serial.println("Servos Setup!");
  IRsensorSetup();
  Serial.println("IRsensors Setup!");
}

void loop()
{
  onBlackLine = IRsensorLoop();
  if (onBlackLine)
  {
    MotorStop();
    return;
  }
  MotorsLoop();
  return;

  // --- state machine (disabled during motor test) ---
  // bool test_mode = true;
  // if (test_mode)
  // {
  //   CameraLoop();
  //   return;
  // }
  // delay(TICK_SPEED);
  // if (onBlackLine)
  // {
  //   state = AVOID_BOUNDARY;
  // }
  // switch (state)
  // {
  // case SEARCHING:
  //   objectInSight = scanArea();
  //   if (objectInSight) state = APPROACHING;
  //   break;
  // case APPROACHING:
  //   objectPickable = getTheBlock();
  //   if (objectPickable) state = PICKING;
  //   break;
  // case PICKING:
  //   objectObtained = activateClaw();
  //   if (objectObtained) state = RETURNING;
  //   break;
  // case RETURNING:
  //   missionComplete = returnToBase();
  //   if (missionComplete) state = COMPLETE;
  //   break;
  // case AVOID_BOUNDARY:
  //   getAway();
  //   state = SEARCHING;
  //   break;
  // case COMPLETE:
  //   stopMotors();
  //   break;
  // }
  // delay(100);
}

// bool scanArea() { ... }
// bool getTheBlock() { ... }
// bool activateClaw() { return false; }
// bool returnToBase() { return false; }
// bool getAway() { return false; }
// bool stopMotors() { return false; }

// put function definitions here:
