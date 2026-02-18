#include <Arduino.h>
#include "Camera.h"
#include "ServoHeader.h"
#include "Motors.h"
#include "IRSensor.h"

// this robot works on a state machine, with each state requireing a different robot action to be run
// these robot actions are scanArea(), getTheBlock(),
enum RobotState
{
  SEARCHING,
  APPROACHING,
  PICKING,
  RETURNING,
  AVOID_BOUNDARY,
  COMPLETE
};

// these variables keep track of whether or not a certain milistone is reached, each robot action function should return a boolean value
// to verify if these milistones are met
bool objectInSight = false; 
bool objectPickable = false;
bool objectObtained = false;
bool onBlackLine = false;
bool missionComplete = false;

RobotState state = SEARCHING;

// put function declarations here:
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Starting...");
  MotorsSetup();
  Serial.println("Motors Setup!");
  CameraSetup();
  Serial.println("Camera Setup!");
  LargeServoSetup();
  SmallServoSetup2();
  Serial.println("Servos Setup!");
  IRsensorSetup();
  Serial.println("IRsensors Setup!");
}

void loop()
{
  // take data from IRSensor
  int sensorValue = IRsensorLoop();
  pixy.ccc.getBlocks(); // get blocks from camera

  // Avoiding the black line is very important, as it is needed no matter the state of execution
  // therefore, if a certain value from IRSensor is reached, activate AVOID_BOUNDARY
  if (onBlackLine) 
  {
    state = AVOID_BOUNDARY;
  }

  switch (state)
  {

  case SEARCHING:
    objectInSight = scanArea();
    if (objectInSight)
    {
      state = APPROACHING;
    }
    break;

  case APPROACHING:
    objectPickable = getTheBlock();
    if (objectPickable)
    {
      state = PICKING;
    }
    break;

  case PICKING:
    objectObtained = activateClaw();
    if (objectObtained)
    {
      state = RETURNING;
    }
    break;

  case RETURNING:
    missionComplete = returnToBase();
    if (missionComplete)
    {
      state = COMPLETE;
    }
    break;

  case AVOID_BOUNDARY:
    getAway();
    state = SEARCHING;
    break;

  case COMPLETE:
    stopMotors();
    break;
  }
  CameraLoop();
  ServoLoop(); // Strafes servo from leftmost position to rightmost position and back again
  delay(100);
}

bool scanArea(){

}
bool getTheBlock(){

}
bool activateClaw(){
  // the only issue is finding out how to verify this 
}
bool returnToBase(){

}
bool getAway(){

}
bool stopMotors(){

}

// put function definitions here:
