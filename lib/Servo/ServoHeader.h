#ifndef SERVO_H
#define SERVO_H
#include <Servo.h>

// #define PINNUMBERHERE
// #define PINNUMBERHERE

#define LargeServIn 8
#define SmallServIn 7
#define ServMid 90
#define ServRight 180
#define ServLeft 0

void LargeServoSetup();
void SmallServoSetup2();
void ServoLoop();

#endif // ServoHeader.h