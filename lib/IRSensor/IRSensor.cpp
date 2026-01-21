#include <Arduino.h>
#include "IRSensor.h"

//Setup function to initialize the IR sensor pin
void IRsensorSetup() {
  pinMode(IRSensor1, INPUT); 
  pinMode(IRSensor2, INPUT);
}

int IRsensorLoop(){
  int hasBlackLine;
  int sensorValue1 = digitalRead(IRSensor1);
  int sensorValue2 = digitalRead(IRSensor2);
  if(sensorValue2 == LOW or sensorValue1 == LOW){
    Serial.println("Black line detected!");
  }
  else{
    Serial.println("White line detected!");
  }
  return hasBlackLine;
}