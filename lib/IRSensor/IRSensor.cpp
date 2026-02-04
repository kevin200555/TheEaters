#include <Arduino.h>
#include "IRSensor.h"

//Setup function to initialize the IR sensor pin
void IRsensorSetup() {
  pinMode(IRSensor1, INPUT); 
}

int IRsensorLoop(){
  int hasBlackLine;
  int sensorValue1 = digitalRead(IRSensor1);
  if(sensorValue1 == LOW){
    Serial.println("Black line detected!");
  }
  else{
    Serial.println("White line detected!");
  }
  return hasBlackLine;
}