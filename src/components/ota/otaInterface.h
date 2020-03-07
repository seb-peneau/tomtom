#ifndef OtaInterface_h
#define OtaInterface_h

#include "../debug/debugInterface.h"

class OtaInterface
{
  public:
    virtual void setup (DebugInterface*);
    virtual void loop ();
    virtual void onProgress (std::function<void(unsigned int progress, unsigned int total)>);
};

#endif