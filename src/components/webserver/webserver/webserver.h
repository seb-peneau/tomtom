#ifndef webserver_h
#define webserver_h

#include "../webserverinterface.h"
#include <ESP8266WebServer.h>

class EspWebServer : public WebServerInterface {

  private:
    DebugInterface* debug;
    ESP8266WebServer* server;
    bool started = false;

  public:
    EspWebServer ();
    void setup (DebugInterface* dI);
    void loop ();
    bool startWebServer (int port);
    void stopWebServer ();
    bool isStarted ();
    void on (const String &uri, String method, ESP8266WebServer::THandlerFunction handler);
    void serve (int statusCode, String contentType, const String &content);
    String getBodyField (String field);
};

#endif