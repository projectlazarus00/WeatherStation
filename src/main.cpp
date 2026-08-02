#include <Arduino.h>
#include <WiFi.h>

const char* ssid = "No Internet";
const char* password = "ZuriTemi0912#";

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Starting WiFi test...");

  WiFi.begin(ssid, password);

  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 20) {
    delay(500);
    Serial.println("Connecting...");
    attempts++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("WiFi connected!");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("WiFi failed to connect");
  }
}

void loop() {
  Serial.println("Alive...");
  delay(1000);
}
