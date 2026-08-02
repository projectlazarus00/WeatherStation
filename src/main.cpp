#include <Arduino.h>
#include <WiFiManager.h>

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("Test starting...");

  WiFiManager wm;
  Serial.println("WiFiManager object created OK");

  bool res = wm.autoConnect("WeatherStation-Test");

  Serial.println("autoConnect() returned");
  if (res) {
    Serial.println("WiFi connected!");
  } else {
    Serial.println("WiFi NOT connected");
  }
}

void loop() {
  Serial.println("Alive...");
  delay(1000);
}
