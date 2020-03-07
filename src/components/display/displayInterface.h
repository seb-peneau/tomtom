#ifndef DisplayInterface_h
#define DisplayInterface_h

class DisplayInterface
{
  public:
    virtual void setup ();
    virtual void loop ();
    virtual void clearDisplay ();
    virtual void setCoordStatus (int x, int y, bool state);

    virtual void displayWifiStatus (bool wifiStatus);
    virtual void displayHour (int hour, int minutes);
    virtual void displayTemp (int temp);
    virtual void displayConfigurationMode(bool configModeEnabled);
    virtual void displayOtaProgress(int progressPercent);

    virtual void displayHexagon();
};

#endif