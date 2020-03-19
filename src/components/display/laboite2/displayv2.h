#ifndef DisplayV2_h
#define DisplayV2_h

#include "../displayInterface.h"

#include <MD_Parola.h>
//#include <MD_MAX72xx.h>
#include "myFont.h"

// Define the number of devices we have in the chain and the hardware interface
// NOTE: These pin numbers will probably not work with your hardware and may
// need to be adapted
//#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW

#define MAX_DEVICES 8

#define CLK_PIN   D2 // or SCK
#define DATA_PIN  D0 // or MOSI
#define CS_PIN    D1 // or SS

#define ZONE_SIZE 32

const uint8_t F_WIFI = 1;
const uint8_t W_WIFI = 16;
static const uint8_t PROGMEM wifiScreen1 [F_WIFI * W_WIFI] = {
  0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x18, 0x18, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
};


class DisplayV2 : public DisplayInterface
{

  private:
    MD_Parola *display;
    MD_MAX72XX *displayController;
    int wifiAnimState = 0;
    unsigned long previousWifiMillis = 0;
    char *cHour = new char[5];
    char *cTemp = new char[5];
    void searchForWifi();

  public:
    DisplayV2();
    void setup ();
    void loop ();
    void clearDisplay ();
    void setCoordStatus (int x, int y, bool state);

    void displayWifiStatus (bool wifiStatus);
    void displayHour (int hour, int minutes);
    void displayTemp (int temp);
    void displayConfigurationMode(bool configModeEnabled);
    void displayOtaProgress(int progressPercent);

    void displayHexagon();
};

#endif