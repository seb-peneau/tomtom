#ifndef BoardInterface_h
#define BoardInterface_h

#include "Arduino.h"

class BoardInterface
{
  public:
    virtual bool isUserTriggeredReset ();
};

#endif