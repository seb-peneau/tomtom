#ifndef console_h
#define console_h

#include "../debugInterface.h"
#include "Arduino.h"

#define BAUDRATE 115200

/** Uncomment following line to enable debug **/
#define DEBUG 1
class Console: public DebugInterface {
  public:
    Console ();
    void debug (String message);
};

#endif