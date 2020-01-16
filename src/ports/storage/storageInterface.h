#ifndef StorageInterface_h
#define StorageInterface_h

#include "Arduino.h"
#include "../debug/debugInterface.h"

class StorageInterface
{
  public:
    virtual void setup (DebugInterface* dI);
    virtual void loop ();
    virtual String read(char address);
    virtual void write (char address, String value);
};

#endif