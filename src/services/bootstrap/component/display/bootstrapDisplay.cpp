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
    display->setTextColor(display->color565(255,255,255));  
    display->print("Config");
  }
}

void BootstrapDisplay::setCoordStatus (int i, int j, bool state) {
}

void BootstrapDisplay::displayWifiStatus(bool isWifiConnected) {
  if (isWifiConnected == true && isWifiConnected != lastWifiStatus) {
    debug->debug("BootstrapDisplay::displayWifiStatus::true");
    clearDisplay();
    setCursor(0, 0);
    display->setTextColor(display->color565(255,255,255)); 
    display->print("no wifi");
    lastWifiStatus = true;
  } else if (isWifiConnected != lastWifiStatus) {
    debug->debug("BootstrapDisplay::displayWifiStatus::false");
    lastWifiStatus = false;
  }
}

void BootstrapDisplay::displayOtaProgress (int progressPercent) {
  debug->debug("BootstrapDisplayImpl::displayOtaProgress");
  clearDisplay();
  setCursor(12, 4);
  display->print((String) progressPercent + " %");  
}

void BootstrapDisplay::displayString (String ipAddress) {
  debug->debug("BootstrapDisplay::display");
  clearDisplay();
  setCursor(0, 0);  
  display->print(ipAddress);
}


void BootstrapDisplay::setCursor(int16_t x, int16_t y) {
  display->setCursor(x, y + Y_FONT_OFFSET);
}

// ISR for display refresh
void BootstrapDisplay::display_updater(BootstrapDisplay *bootstrapDisplay)
{
  bootstrapDisplay->display->display(bootstrapDisplay->display_draw_time);
}