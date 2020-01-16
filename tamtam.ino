#include "src/domain/domain.h"

#include "src/adapters/console/console.h";
#include "src/adapters/wifi/wifi.h";
#include "src/adapters/eeprom/storeEeprom.h";
//#include "src/adapters/ESP/espBoard.h";
#include "src/adapters/NodeMCU/nodemcuBoard.h";
#include "src/adapters/spiff/storeSpiff.h";
#include "src/adapters/laboite/laboite.h";
#include "src/adapters/webserver/webserver.h";
#include "src/adapters/espOta/espOta.h";
#include "src/adapters/ntp/ntp.h";

Domain* Tamtam = new Domain();

void setup() {
  Console* console = new Console();
  LedDisplayImpl *ledDisplay = new LedDisplayImpl();
  //Tamtam->setBoardInterface(new ESPBoard()); // FOR ESP BOARD
  Tamtam->setBoardInterface(new NodeMCUBoard()); // FOR NODEMCU BOARD
  Tamtam->setDebugInterface(console);
  Tamtam->setDisplayInterface(ledDisplay);
  Tamtam->setNetworkInterface(new EspWifi());
  Tamtam->setStorageInterface(new StoreEeprom()); // USE EEPROM for storage
  // Tamtam->setStorageInterface(new StoreSpiff()); // USE SPIFF for storage
  Tamtam->setWebServerInterface(new EspWebServer());
  Tamtam->setOtaInterface(new ESPOta());
  Tamtam->setTimeInterface(new Ntp());
  Tamtam->setup();
}

void loop() {
  Tamtam->loop();
}