#ifndef TimeInterface_h
#define TimeInterface_h

class TimeInterface
{
  public:
    virtual void setup ();
    virtual void loop ();
    virtual int getHour();
    virtual void start();
    virtual int getMinutes();
};

#endif