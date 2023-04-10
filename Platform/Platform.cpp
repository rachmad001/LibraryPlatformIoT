#include "Platform.h"
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

Platform::Platform(String token, String server)
{
  _token = token;
  _server = server;
}

void Platform::connectWiFi(String ssid, String password)
{
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(200);
  }
  Serial.println("");
  Serial.print("connect to WiFi with IP Address");
  Serial.println(WiFi.localIP());
}

String Platform::sendData(String project, String device, String data)
{
  WiFiClient client;
  HTTPClient http;
  http.begin(client, _server + "/addData");
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  String datatoServer = "token=" + _token + "&" +
                        "idProject=" + project + "&" +
                        "idDevice=" + device + "&" +
                        "data=" + data;
  int httpResponseCode = http.POST(datatoServer);
  if (httpResponseCode > 0)
  {
    String payload = http.getString();
    return payload;
  }
  else
  {
    return sendData(project, device, data);
  }
}

String Platform::getData(String project, String device)
{
  WiFiClient client;
  HTTPClient http;
  http.begin(client, _server + "/data/" + project + "/" + device + "?type=all");
  http.addHeader("token", _token);
  int httpResponseCode = http.GET();
  if (httpResponseCode > 0)
  {
    return http.getString();
  }
  else
  {
    return get(project, device);
  }
}

String Platform::getLastData(String project, String device)
{
  WiFiClient client;
  HTTPClient http;
  http.begin(client, _server + "/data/" + project + "/" + device + "?type=last");
  http.addHeader("token", _token);
  int httpResponseCode = http.GET();
  if (httpResponseCode > 0)
  {
    return http.getString();
  }
  else
  {
    return get(project, device);
  }
}

String Platform::getDataByIndex(String project, String device, int index)
{
  WiFiClient client;
  HTTPClient http;
  http.begin(client, _server + "/data/" + project + "/" + device + "?type=byIndex&index="+String(index));
  http.addHeader("token", _token);
  int httpResponseCode = http.GET();
  if (httpResponseCode > 0)
  {
    return http.getString();
  }
  else
  {
    return get(project, device);
  }
}

String Platform::getDataByRange(String project, String device, int start, int end){
  WiFiClient client;
  HTTPClient http;
  http.begin(client, _server + "/data/" + project + "/" + device + "?type=byIndex&start="+String(start)+"&end="+String(end));
  http.addHeader("token", _token);
  int httpResponseCode = http.GET();
  if (httpResponseCode > 0)
  {
    return http.getString();
  }
  else
  {
    return get(project, device);
  }
}
