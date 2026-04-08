#include <Arduino.h>
#include "Camera.h"
#include "ServoHeader.h"
#include "Motors.h"
#include "IRSensor.h"
bool scanArea();
bool getTheBlock();
bool activateClaw();
bool returnToBase();
bool getAway();
bool stopMotors();
Pixy2 pixy;

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
  bool test_mode = true;
  if (test_mode)
  {
    CameraLoop();
    delay(100);
    return;
  }
  // take data from IRSensor
  // int sensorValue = IRsensorLoop();

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
  // CameraLoop();
  // ServoLoop(); // Strafes servo from leftmost position to rightmost position and back again
  delay(100);
}

bool scanArea()
{
  pixy.ccc.getBlocks();
  int x = 0;
  int y = 0;
  int width = 0;
  int height = 0;

  if (pixy.ccc.numBlocks)
  {
    Serial.print("Blue box thing detected: ");
    Serial.println(pixy.ccc.numBlocks);
    for (int i = 0; i < pixy.ccc.numBlocks; i++)
    {
      // signiture 1: blue box thing
      if (pixy.ccc.blocks[i].m_signature == 1)
      {
        x = pixy.ccc.blocks[i].m_x;
        y = pixy.ccc.blocks[i].m_y;
        width = pixy.ccc.blocks[i].m_width;
        height = pixy.ccc.blocks[i].m_height;
        Serial.print("X: ");
        Serial.println(x);
        Serial.print("Y: ");
        Serial.println(y);
        Serial.print("Width: ");
        Serial.println(width);
        Serial.print("Height: ");
        Serial.println(height);
        return true;
      }
    }
  }
  return false;
}
bool getTheBlock()
{
}
bool activateClaw()
{
  return false;
  // the only issue is finding out how to verify this
}
bool returnToBase()
{
  return false;
}
bool getAway()
{
  return false;
}
bool stopMotors()
{
  return false;
}

// put function definitions here:
