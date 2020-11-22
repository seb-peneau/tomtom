#include <Arduino.h>

#include "bootstrapDisplay.h"

BootstrapDisplay::BootstrapDisplay() {
  display = new PxMATRIX(32,16,P_LAT, P_OE,P_A,P_B,P_C);
}

void BootstrapDisplay::setup(DebugInterface *debug) {
  this->debug = debug;
  display->begin(8);
  display->setFastUpdate(true);
  display->setFont(&TomThumb);
  display->setCursor(0,0);
  display->setTextColor(display->color565(125,125,125));  
  display_ticker = new Ticker();
  display_ticker->attach_ms(2, &BootstrapDisplay::display_updater, this);  
}

void BootstrapDisplay::loop() {
}

void BootstrapDisplay::clearDisplay () {
  debug->debug("BootstrapDisplay::clearDisplay");
  display->clearDisplay();
}

void BootstrapDisplay::displayConfigurationMode(bool confModeEnabled) {
  if (confModeEnabled) {
    debug->debug("BootstrapDisplay::displayConfigurationMode::true");
    clearDisplay();
    setCursor(0, 0);    
    display->setTextColor(display->color565(255,0,0));  
    display->print("Config Mode");
  }
}

void BootstrapDisplay::setCoordStatus (int i, int j, bool state) {
}

void BootstrapDisplay::displayWifiStatus(bool isWifiConnected) {
  if (isWifiConnected == false && isWifiConnected != lastWifiStatus) {
    debug->debug("BootstrapDisplay::displayWifiStatus::false");
    clearDisplay();
    setCursor(0, 0);
    display->print("no wifi");
    lastWifiStatus = false;
  } else if (isWifiConnected != lastWifiStatus) {
    debug->debug("BootstrapDisplay::displayWifiStatus::false");
    lastWifiStatus = true;
  }
}


void BootstrapDisplay::setCursor(int16_t x, int16_t y) {
  display->setCursor(x, y + Y_FONT_OFFSET);
}

// ISR for display refresh
void BootstrapDisplay::display_updater(BootstrapDisplay *bootstrapDisplay)
{
  bootstrapDisplay->display->display(bootstrapDisplay->display_draw_time);
}