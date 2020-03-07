#ifndef WebServerInterface_h
#define WebServerInterface_h

#include "Arduino.h"
#include "../debug/debugInterface.h"

class WebServerInterface
{
  public:
    virtual void setup (DebugInterface* dI);
    virtual void loop ();
    virtual bool startWebServer (int port);
    virtual void stopWebServer ();
    virtual bool isStarted ();
    virtual void on (const String &, String method, std::function<void()>);
    virtual void serve (int statusCode, String contentType, const String &content);
    virtual String getBodyField (String field);
};

#endif