#ifndef NetworkInterface_h
#define NetworkInterface_h

#include "../debug/debugInterface.h"

class NetworkInterface
{
  public:
    virtual void setup (DebugInterface*);
    virtual void loop ();
    virtual bool isConnected();
    virtual bool isApCreated();
    virtual void connect (String ssid, String password);
    virtual void disconnect ();
    virtual bool createAccessPoint (String apName, String apPassword);
    virtual void closeAccessPoint ();
    virtual String getIpAddress ();
    virtual std::vector<String> listNetworks ();
};

#endif