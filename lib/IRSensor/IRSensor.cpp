#include <Arduino.h>
#include "IRSensor.h"

//Setup function to initialize the IR sensor pin
void IRsensorSetup() {
  pinMode(IRPin, INPUT); // Set IR sensor pin as input
  pinMode(ledPin, OUTPUT); // Set LED pin as output
}

void IRsensorLoop(){

}