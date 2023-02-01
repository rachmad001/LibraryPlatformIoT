#ifndef Platform_h
#define Platform_h

#include <Arduino.h>

class Platform
{
  public:
    Platform(String token, String server);
    void connectWiFi(String ssid, String password);
    void sendData(String project, String device,  String data);
    void get(String project, String device);
    String getData();
    
  private:
    String _token;
    String _server;
    String _data;
    String _lastData;
};

#endif

  
