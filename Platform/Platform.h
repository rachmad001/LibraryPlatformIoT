#ifndef Platform_h
#define Platform_h

#include <Arduino.h>

class Platform
{
  public:
    Platform(String token, String server);
    void connectWiFi(String ssid, String password);
    String sendData(String project, String device,  String data);
    String get(String project, String device);
    String getData();
    String getLastData(String project, String device);
    
  private:
    String _token;
    String _server;
    String _data;
    String _lastData;
};

#endif

  
