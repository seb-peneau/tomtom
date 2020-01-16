#ifndef EspOta_h
#define EspOta_h

#include "../../ports/ota/otaInterface.h"
#include "../../ports/debug/debugInterface.h"

#include "Arduino.h"
#include <ArduinoOTA.h>

class ESPOta : public OtaInterface {
  private:
    DebugInterface* debug;
    ArduinoOTAClass* arduinoOta;
  public:
    ESPOta ();
    void setup (DebugInterface*);
    void loop ();
    void onProgress(ArduinoOTAClass::THandlerFunction_Progress handler);
};

#endif