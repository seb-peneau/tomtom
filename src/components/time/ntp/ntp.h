#include "../timeInterface.h"

#include <WiFiUdp.h>
#include <NTPClient.h>

class Ntp : public TimeInterface {

  private:
    WiFiUDP ntpUDP;
    NTPClient* timeClient;
    unsigned long previousTimeUpdate = 0;
    bool isInitialized = false;

  public:
    void setup();
    void loop();
    void start();
    int getHour();
    int getMinutes();    
};