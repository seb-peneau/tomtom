#include "./components/display/tomtom/tomtom.h"

#include <Arduino.h>

#include "./components/board/ESP/espBoard.h"
#include "./components/debug/console/console.h"
#include "./components/network/wifi/wifi.h"
#include "./components/ota/espOta/espOta.h"
#include "./components/storage/eeprom/storeEeprom.h"
#include "./components/storage/spiff/storeSpiff.h"
#include "./components/time/ntp/ntp.h"
#include "./components/webserver/webserver/webserver.h"
#include "./services/tomtom/domain.h"

Domain* Tamtam = new Domain();

void setup() {
    Console* console = new Console();
    TomtomDisplayImpl* ledDisplay = new TomtomDisplayImpl();  // V2 for laboite
    Tamtam->setBoardInterface(new ESPBoard());                // FOR esp board
    Tamtam->setDebugInterface(console);
    Tamtam->setDisplayInterface(ledDisplay);
    Tamtam->setNetworkInterface(new EspWifi());
    Tamtam->setStorageInterface(new StoreEeprom());  // USE EEPROM for storage
    // Tamtam->setStorageInterface(new StoreSpiff()); // USE SPIFF for storage
    Tamtam->setWebServerInterface(new EspWebServer());
    Tamtam->setOtaInterface(new ESPOta());
    Tamtam->setTimeInterface(new Ntp());
    Tamtam->setup();
}

void loop() {
    Tamtam->loop();
}