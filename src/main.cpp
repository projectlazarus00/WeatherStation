#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("BOOT OK - minimal test running");
}

void loop() {
  Serial.println("Alive...");
  delay(1000);
}
