#include "Platform.h"
#include <ArduinoJson.h>

String token =  "Y7c9Wa6GqP4T2rgeReoaR43WL";
String server = "http://192.168.137.1:8000";

String ssid = "OPPO A12";
String password = "1234duakali";

unsigned long lastTime = 0;
unsigned long interval = 2000;

String projectName = "rumahan";
String devices = "testing";

Platform platform(token, server);
void setup() {
  Serial.begin(9600);
  platform.connectWiFi(ssid, password);
}

void loop() {
  StaticJsonDocument<200> doc;
  if((millis() - lastTime) > interval){
    doc["namadepan"] = "rachmad";
    doc["namabelakang"] = "sukri";
    String data = "";
    serializeJson(doc, data);
    platform.sendData(projectName, devices, data);
    lastTime = millis();
  }
}
