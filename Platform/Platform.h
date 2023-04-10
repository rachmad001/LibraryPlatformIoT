#ifndef Platform_h
#define Platform_h

#include <Arduino.h>

class Platform
{
  public:
    Platform(String token, String server);
    void connectWiFi(String ssid, String password);
    String sendData(String project, String device,  String data);
    String getData(String project, String device);
    String getLastData(String project, String device);
    String getDataByIndex(String project, String device, int index);
    String getDataByRange(String project, String device, int start, int end);
    
  private:
    String _token;
    String _server;
};

#endif

  
