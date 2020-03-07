#ifndef LaBoite_h
#define LaBoite_h

#include "../displayInterface.h"

#include <LedControl.h>
#include <Ticker.h>
#include <MD_MAX72xx.h>

class LedDisplayImpl : public DisplayInterface
{
  private:
    int DIN = 16; // D0
    int CS = 5; // D1
    int CLK = 4; // D2  
    LedControl* ledControl;
    Ticker *ticker;
    static void staticDrawCallback(LedDisplayImpl *ledDisplay);
    bool nextLedState[32][16] = {{}};
    bool currentLedState[32][16] = {{}};
    bool lastWifiStatus = false;
    int fadingEffectCount = 0;
    unsigned long previousMillis = 0;
    unsigned long previousTimeMillis = 0;
    int currentWifiAnimState = 0;
    int wifiSignalStep1[3] = {15,12,12};
    int wifiSignalStep2[7] = {13,11,10,10,10,10,11};
    int wifiSignalStep3[11] = {11,10,9,8,8,8,8,8,8,9,10};
    int wifiSignalStep4[15] = {9,9,8,7,6,6,6,6,6,6,6,6,7,8,9};
    int currentHexaAnimState = 0;
    /**
     * NUMBERS definitions
     **/
    int a[5] = {0, 0, 0, 0, 0};
    int h[5] = {0, 0, 1, 0, 0};
    int i[5] = {1, 0, 0, 0, 0};
    int j[5] = {1, 0, 1, 0, 0};
    int b[5] = {1, 0, 0, 0, 1};
    int f[5] = {1, 0, 1, 0, 1};
    int c[5] = {1, 0, 1, 1, 1};
    int g[5] = {1, 1, 1, 0, 0};
    int d[5] = {1, 1, 1, 0, 1};
    int e[5] = {1, 1, 1, 1, 1};
    int* numbers[10][3] = {{e, b, e}, {a, a, e}, {c, f, d}, {b, f, e}, {g, h, e}, {d, f, c}, {e, f, c}, {i, i, e}, {e, f, e}, {d, f, e}};

    /**
     * PARAMETER definitions 
     */
    int aa[14] = {0,0,0,0,1,1,0,0,1,1,0,0,0,0};
    int ab[14] = {0,1,1,0,1,1,1,1,1,1,0,1,1,0};
    int ac[14] = {0,1,1,1,1,1,1,1,1,1,1,1,1,0};
    int ad[14] = {0,0,1,1,1,0,0,0,0,1,1,1,0,0};
    int ae[14] = {0,0,1,1,0,0,0,0,0,0,1,1,0,0};
    int af[14] = {1,1,1,1,0,0,0,0,0,0,1,1,1,1};
    int* params[14] = {aa, aa, ab, ac, ad, ae, af, af, ae, ad, ac, ab, aa, aa}; 

    void searchForWifi();
    void drawCallback();
    void displayNumber(int number, int posX, int posY);
    void renderHexagon();

  public:
    LedDisplayImpl();
    void setup ();
    void clearDisplay ();
    void setCoordStatus (int x, int y, bool state);
    void displayWifiStatus (bool wifiStatus);
    void displayHour(int hour, int minute);
    void displayTemp(int temp);
    void displayConfigurationMode(bool confEnabled);
    void displayHexagon();
    void displayOtaProgress (int progressPercent);

};

#endif