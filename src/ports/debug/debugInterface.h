#ifndef DebugInterface_h
#define DebugInterface_h

#include "Arduino.h"

class DebugInterface
{
  public:
    virtual void debug (String message);
};

#endif