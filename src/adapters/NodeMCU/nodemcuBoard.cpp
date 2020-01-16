#include "nodemcuBoard.h"

extern "C" {
  #include <user_interface.h> // https://github.com/esp8266/Arduino actually tools/sdk/include
}

NodeMCUBoard::NodeMCUBoard() {

}
/**
 * NODEMCU does not return the reset action, more precisely, there is an issue and the reason is always user input...
 */
bool NodeMCUBoard::isUserTriggeredReset() {
  return false;
}