#ifndef wifi_h
#define wifi_h

#include "../../ports/network/NetworkInterface.h"

#include "../../ports/debug/debugInterface.h"

#include <ESP8266WiFi.h>

class EspWifi : public NetworkInterface {

  private:
    DebugInterface* debug;
    bool connected = false;
    bool apcreated = false;
    bool isConnecting = false;

  public:
    EspWifi ();
    void setup (DebugInterface* dI);
    void loop ();
    bool isConnected ();
    bool isApCreated();
    void connect (String ssid, String password);
    void disconnect ();
    bool createAccessPoint (String apssid, String appass);
    void closeAccessPoint ();
    std::vector<String> listNetworks ();
     
};

#endif