#ifndef SERVO_H
#define SERVO_H
#include <Servo.h>

// #define PINNUMBERHERE
// #define PINNUMBERHERE

#define ServIn 9
#define ServMid 90
#define ServRight 180
#define ServLeft 0

void ServoSetup();
void ServoLoop();

#endif // ServoHeader.h