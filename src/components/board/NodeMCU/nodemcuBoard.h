#ifndef nodemcu_h
#define nodemcu_h

#include "../boardInterface.h"
#include "Arduino.h"

class NodeMCUBoard: public BoardInterface {
  public:
    NodeMCUBoard ();
    bool isUserTriggeredReset ();
};

#endif