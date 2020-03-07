#include "src/domain/domain.h"

#include "src/components/debug/console/console.h";
#include "src/components/network/wifi/wifi.h";
#include "src/components/storage/eeprom/storeEeprom.h";
//#include "src/components/board//ESP/espBoard.h";
#include "src/components/board/NodeMCU/nodemcuBoard.h";
#include "src/components/storage/spiff/storeSpiff.h";
//#include "src/components/display/laboite/laboite.h";
#include "src/components/display/laboite2/displayv2.h";
#include "src/components/webserver/webserver/webserver.h";
#include "src/components/ota/espOta/espOta.h";
#include "src/components/time/ntp/ntp.h";

Domain* Tamtam = new Domain();

void setup() {
  Console* console = new Console();
  //LedDisplayImpl *ledDisplay = new LedDisplayImpl(); //V1 for laboite
  DisplayV2 *ledDisplay = new DisplayV2(); // V2 for laboite
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