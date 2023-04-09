#include "Platform.h"
#include <ArduinoJson.h>

String token =  "ptiZNNdIPfgjMqtQziTXN6cbF";
String server = "http://192.168.137.1:8000";

String ssid = "OPPO A12";
String password = "1234duakali";

unsigned long lastTime = 0;
unsigned long interval = 1000;

String projectName = "rumahan";
String devices = "testing";

Platform platform(token, server);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  platform.connectWiFi(ssid, password);
}

void loop() {
  // put your main code here, to run repeatedly:
  if((millis() - lastTime) > interval){
    String data = platform.get(projectName, devices);
    Serial.println(data);
  }
}
