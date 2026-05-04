// Define Sensor Pin
const int irSensorPin = 3; // Connect Signal pin to Pin 2

void setup() {
  pinMode(irSensorPin, INPUT); // Initialize sensor pin
  Serial.begin(9600);          // Serial monitor for debugging
}

void loop() {
  int sensorValue = digitalRead(irSensorPin);

  // Often, HIGH means NO line (white) and LOW means LINE FOUND (black)
  // This varies by sensor module manufacturer
  if (sensorValue == HIGH) {
    Serial.println("Black Line Detected!");
  } else {
    Serial.println("White Surface");
  }
  delay(100);
}
