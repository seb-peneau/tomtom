#ifndef BootstrapDisplay_h
#define BootstrapDisplay_h

#include "Arduino.h"
#include "../../../../components/display/displayInterface.h"

// I don't get why I need this include here
#include <Wire.h>
// TODO : should remove it

#include <PxMatrix.h>
#include <Ticker.h>
#include <Fonts/TomThumb.h>
#include <Fonts/Picopixel.h>
#include <Fonts/Tiny3x3a2pt7b.h>
#include <Fonts/Org_01.h>

#define P_LAT 16
#define P_A 12
#define P_B 0
#define P_C 15
#define P_OE 2

#define Y_FONT_OFFSET 5


class BootstrapDisplay : public DisplayInterface
{
  private:
    DebugInterface *debug;
    PxMATRIX *display;
    Ticker *display_ticker;
    uint8_t display_draw_time=20; //10-50 is usually fine
    static void display_updater (BootstrapDisplay *ledDisplay);    
    void setCursor (int16_t x, int16_t y);
    bool lastWifiStatus = false;

  public:
    BootstrapDisplay();
    void setup (DebugInterface *debug);
    void loop ();
    void clearDisplay ();
    void setCoordStatus (int x, int y, bool state);
    void displayConfigurationMode(bool confModeEnabled);
    void displayWifiStatus(bool isWifiConnected);
    void displayOtaProgress(int progress);
    void displayString(String text);
};

#endif