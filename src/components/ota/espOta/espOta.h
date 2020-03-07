#ifndef EspOta_h
#define EspOta_h

#include "../otaInterface.h"

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