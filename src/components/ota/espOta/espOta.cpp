#include "espOta.h"

ESPOta::ESPOta () {
  arduinoOta = new ArduinoOTAClass();
}

void ESPOta::setup (DebugInterface* dI) {
  debug = dI;
  debug->debug("ESPOta::setup::" + arduinoOta->getHostname());
  
  arduinoOta->onStart([&, this]() {
    debug->debug("ESPOTA::onstart");
  });

  arduinoOta->onError([&, this](ota_error_t error) {
    if (error == OTA_AUTH_ERROR) debug->debug("Auth Failed");
    else if (error == OTA_BEGIN_ERROR) debug->debug("Begin Failed");
    else if (error == OTA_CONNECT_ERROR) debug->debug("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) debug->debug("Receive Failed");
    else if (error == OTA_END_ERROR) debug->debug("End Failed");
  });
  arduinoOta->begin();
}

void ESPOta::onProgress (ArduinoOTAClass::THandlerFunction_Progress handler) {
  arduinoOta->onProgress(handler);
}

void ESPOta::loop () {
  // debug->debug("ESPOta::loop::" + arduinoOta->getHostname());
  arduinoOta->handle();
} 