#include <Arduino.h>

#define IRPin 2 //temporary placeholder
#define ledPin 13 //temporary placeholder

//Setup function to initialize the IR sensor pin
void IRPinSetup() {
  pinMode(IRPin, INPUT); // Set IR sensor pin as input
  pinMode(ledPin, OUTPUT); // Set LED pin as output
}