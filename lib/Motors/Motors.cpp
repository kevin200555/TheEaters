#include <Arduino.h>
#include "Motors.h"
void MotorsSetup()
{
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(EN, OUTPUT);
}
void MotorsLoop()
{
    Serial.println("Motor Forward");
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(EN, 255); // PWM 0-255, 255 = full speed
    delay(2000);          // Run for 2 seconds

    // Stop motor
    Serial.println("Motor Stop");
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(EN, 0);
    delay(1000);

    // Run motor backward at half speed
    Serial.println("Motor Backward");
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(EN, 128); // half speed
    delay(2000);

    // Stop motor
    Serial.println("Motor Stop");
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(EN, 0);
    delay(1000);
}