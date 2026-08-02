#include <Arduino.h>
#include <WiFi.h>

const char* ssid = "No Internet";
const char* password = "ZuriTemi0912#";

void setup() {
  Serial.begin(115200);
  while (!Serial) {}; 
  Serial.print("WeatherStation");
  Serial.println(VW_Version);

  //--- WiFi connection using Captive_AP.
  //--- WiFi connection using hardcoded credentials
WiFi.begin("No Internet", "ZuriTemi0912#");

int wifiAttempts = 0;
while (WiFi.status() != WL_CONNECTED && wifiAttempts < 40) {
  delay(500);
  Serial.print(".");
  wifiAttempts++;
}

if (WiFi.status() != WL_CONNECTED) {
  Serial.println("Failed to connect and hit timeout");
  delay(3000);
  ESP.restart();
}

Serial.println("INFO: connected to WiFi");

  setupApi();
  getTime(NULL);

  //--- Initialize display
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(WS_BLACK);

  fromSensor.t = 0.0; // set dummy values for first time display
  fromSensor.h = 0.0;
  fromSensor.b = 100;
  drawSensor(fromSensor.t,fromSensor.h,fromSensor.b,TFT_RED); // using RED color because we still not have real sensor data

  drawTime(NULL);
  getSensor(NULL);
  getForecast(NULL);
  
  //--- Create Timers for main Weather Station functions
  timer.every(500,drawTime);               // Every 500ms, display time
  timer.every(15*60*1000,getTime);         // Every 15mn
  timer.every(5*60*1000,getSensor);        // Every 5mn
  timer.every(10*60*1000,getForecast);     // Every 10mn
}

void loop() {
  server.handleClient();
  timer.tick();
}

//--- getInternet Time From API server and set RTC time.
DateTime parseISO8601(const String& iso8601) {
  DateTime dt;
  sscanf(iso8601.c_str(), "%4d-%2d-%2dT%2d:%2d:%2d.%7ld",
         &dt.year, &dt.month, &dt.day,
         &dt.hour, &dt.minute, &dt.second, &dt.microsecond);
  return dt;
}

bool getTime(void *) {
  HTTPClient http;
  int httpResponseCode;
  JsonDocument jsonDoc;
  String payload;
  DeserializationError error;
  const char * datetime;
  DateTime dt;

  http.begin(timeServer);
  httpResponseCode = http.GET();
  if (httpResponseCode > 0){
    payload = http.getString();
    // Serial.println(httpResponseCode);      // for debug purpose
    // Serial.println(payload);
  } else {
    Serial.println("WiFi failed to connect");
  }
}

void loop() {
  Serial.println("Alive...");
  delay(1000);
}
