#ifndef storeEeprom_h
#define storeEeprom_h

#include "../storageInterface.h"

#include "EEPROM.h"

class StoreEeprom : public StorageInterface {

  private:
    DebugInterface* console;

  public:
    StoreEeprom();
    void setup (DebugInterface* dI);
    void loop ();
    void write (char address, String value);
    String read (char address);
};

#endif