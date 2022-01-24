#include "Platform.h"
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

Platform::Platform(String token, String server){
    _token = token;
    _server = server;
}

void Platform::connectWiFi(String ssid, String password){
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(200);
  }
  Serial.println("");
  Serial.print("connect to WiFi with IP Address");
  Serial.println(WiFi.localIP());
}

void Platform::sendData(String project, String device,  String data){
  WiFiClient client;
  HTTPClient http;
  http.begin(client, _server+"/addData");
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  String datatoServer = "token="+_token+"&"+
                "nameproject="+project+"&"+
                "namedevices="+device+"&"+
                "data="+data;
  int httpResponseCode = http.POST(datatoServer);
  if(httpResponseCode > 0) {
    String payload = http.getString();
    Serial.println(payload);              
  }
}
