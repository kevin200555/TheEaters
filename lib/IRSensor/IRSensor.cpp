#include <Arduino.h>
#include "IRSensor.h"

//Setup function to initialize the IR sensor pin
void IRsensorSetup() {
  pinMode(IRSensor1, INPUT); 
}

int IRsensorLoop(){
  int sensorValue1 = digitalRead(IRSensor1);
  // HIGH = black line detected, LOW = white surface (varies by sensor module)
  if(sensorValue1 == HIGH){
    Serial.println("Black line detected!");
    return 1;
  }
  Serial.println("White surface");
  return 0;
}