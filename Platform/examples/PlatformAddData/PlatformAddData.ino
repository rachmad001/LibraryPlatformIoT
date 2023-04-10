#include "Platform.h"
#include <ArduinoJson.h>

String token =  "qhzLDmz3hD3mvmsaYLgZa7pE2"; //your token
String server = "http://192.168.137.1:8000"; //host/url server

String ssid = "hotspot"; //ssid wifi
String password = "hotspot12"; //password wifi

unsigned long lastTime = 0;
unsigned long interval = 1000;

String idProject = "z4QZiz50pXveCOBO"; //your id project
String idDevices = "BwMNrN6uUQJVxZPS"; //your id devices

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
    Serial.println(platform.sendData(idProject, idDevices, data));
    lastTime = millis();
  }
}
