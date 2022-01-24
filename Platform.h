#ifndef Platform_h
#define Platform_h

#include <Arduino.h>

class Platform
{
  public:
    Platform(String token, String server);
    void connectWiFi(String ssid, String password);
    void sendData(String project, String device,  String data);
  private:
    String _token;
    String _server;
};

#endif

  
