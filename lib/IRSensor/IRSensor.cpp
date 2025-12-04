#include <Arduino.h>
#include "IRSensor.h"

//Setup function to initialize the IR sensor pin
void IRsensorSetup() {
  pinMode(IRPin, INPUT); // Set IR sensor pin as input
  pinMode(ledPin, OUTPUT); // Set LED pin as output
}

int IRsensorLoop(){
  int sensorValue = digitalRead(IRPin);
  if(sensorValue == LOW){
    Serial.println("Black line detected!");
    digitalWrite(ledPin, HIGH);
  }
  else{
    Serial.println("White line detected!");
    digitalWrite(ledPin, LOW);
  }
  return sensorValue;
}