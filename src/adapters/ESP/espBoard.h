#ifndef esp_h
#define esp_h

#include "../../ports/board/boardInterface.h"
#include "Arduino.h"

class ESPBoard: public BoardInterface {
  public:
    ESPBoard ();
    bool isUserTriggeredReset ();
};

#endif