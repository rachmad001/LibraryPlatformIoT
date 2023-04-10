#include "Platform.h"

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
  // put your setup code here, to run once:
  Serial.begin(9600);
  platform.connectWiFi(ssid, password);
}

void loop() {
  // put your main code here, to run repeatedly:
  if((millis() - lastTime) > interval){
    //getDataByRange(idProject, idDevices, startIndexData, endIndexData)
    String data = platform.getDataByRange(idProject, idDevices, 0, 1);
    Serial.println(data);
  }
}
