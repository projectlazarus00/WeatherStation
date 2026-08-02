#include <Arduino.h>
#include <TFT_eSPI.h>
#include <WiFiManager.h>

TFT_eSPI tft = TFT_eSPI();

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Starting TFT + WiFiManager test...");

  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLUE);
  Serial.println("Screen should be BLUE now");

  WiFiManager wm;
  Serial.println("About to start WiFiManager portal...");
  bool res = wm.autoConnect("WeatherStation-Test");

  if (res) {
    Serial.println("WiFi connected!");
    tft.fillScreen(TFT_GREEN);
  } else {
    Serial.println("WiFi NOT connected, portal timed out or failed");
    tft.fillScreen(TFT_YELLOW);
  }
}

void loop() {
  Serial.println("Alive...");
  delay(1000);
}
