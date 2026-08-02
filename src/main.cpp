#include <Arduino.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Starting TFT test...");

  tft.init();
  Serial.println("TFT init done");
  tft.setRotation(1);
  tft.fillScreen(TFT_RED);
  Serial.println("Screen should be RED now");
}

void loop() {
  Serial.println("Alive...");
  delay(1000);
}
