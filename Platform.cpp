#include "Platform.h"
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

Platform::Platform(String token){
    _token = token;
}

void Platform::connectWiFi(String ssid, String password){
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("connect to WiFi with IP Address");
  Serial.println(WiFi.localIP());
}

void Platform::sendData(String project, String device,  String data){
  
}
