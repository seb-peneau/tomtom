#include <Arduino.h>

#include "services/bootstrap/domain.h"

#include "../../services/bootstrap/component/display/bootstrapDisplay.h"
#include "./components/debug/console/console.h"
#include "./components/network/wifi/wifi.h"
#include "./components/storage/eeprom/storeEeprom.h"
#include "./components/board/ESP/espBoard.h"
#include "./components/storage/spiff/storeSpiff.h"
#include "./components/webserver/webserver/webserver.h"
#include "./components/ota/espOta/espOta.h"
#include "./components/time/ntp/ntp.h"

Domain* Tomtom = new Domain();

void setup() {
  Console* console = new Console();
  BootstrapDisplay *ledDisplay = new BootstrapDisplay(); // BOOTSTRAP DISPLAY IMPL
  Tomtom->setBoardInterface(new ESPBoard()); // FOR ESP BOARD
  Tomtom->setDebugInterface(console);
  Tomtom->setDisplayInterface(ledDisplay);
  Tomtom->setNetworkInterface(new EspWifi());
  Tomtom->setStorageInterface(new StoreEeprom()); // USE SPIFF for storage
  Tomtom->setWebServerInterface(new EspWebServer());
  Tomtom->setOtaInterface(new ESPOta());
  Tomtom->setup();
}

void loop() {
  Tomtom->loop();  
}