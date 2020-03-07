#include "espBoard.h"

extern "C" {
  #include <user_interface.h> // https://github.com/esp8266/Arduino actually tools/sdk/include
}

ESPBoard::ESPBoard() {

}

bool ESPBoard::isUserTriggeredReset() {
  rst_info *myResetInfo;
  myResetInfo = ESP.getResetInfoPtr();
  return (myResetInfo->reason == REASON_EXT_SYS_RST);
}