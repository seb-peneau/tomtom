#include "webserver.h"

EspWebServer::EspWebServer () {
}

void EspWebServer::setup (DebugInterface* dI) {
  debug = dI;
  started = false;
}

void EspWebServer::loop () {
  if (started == true) {
    server->handleClient();
  }
}

bool EspWebServer::isStarted () {
  return started;
}

bool EspWebServer::startWebServer (int port) {
  debug->debug("EspWebServer::startWebServer");
  server = new ESP8266WebServer(port);
  server->begin();
  started = true;
  return started;
}

void EspWebServer::stopWebServer () {
  debug->debug("EspWebServer::stopWebServer");
  server->stop();
  started = false;
}

void EspWebServer::on (const String &uri, String method, ESP8266WebServer::THandlerFunction handler) {
  if (method == "GET") {
    server->on(uri, HTTP_GET, handler);
  } else if (method == "POST") {
    server->on(uri, HTTP_POST, handler);
  }
}

void EspWebServer::serve (int statusCode, String contentType, const String &content) {
  server->send(statusCode, contentType, content);
}

String EspWebServer::getBodyField (String field) {
  String message = "";
  if (server->hasArg(field)) {
    message = server->arg(field);
  }
  return message;
}