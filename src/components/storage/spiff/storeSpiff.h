#ifndef storeSpiff_h
#define storeSpiff_h

#include "../storageInterface.h"

#include <FS.h>

class StoreSpiff : public StorageInterface {

  private:
    DebugInterface* console;

  public:
    StoreSpiff();
    void setup (DebugInterface* dI);
    void loop ();
    void write (char address, String value);
    String read (char address);
};

#endif