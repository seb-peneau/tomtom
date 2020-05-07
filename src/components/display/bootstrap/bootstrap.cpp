#include "bootstrap.h"


BootstrapDisplayImpl::BootstrapDisplayImpl() {
  display = new PxMATRIX(32,16,P_LAT, P_OE,P_A,P_B,P_C);
}

void BootstrapDisplayImpl::setup (DebugInterface *debug) {
  displayDebug = debug;
  display->begin(8);
  display->setFastUpdate(true);
  display->setFont(&TomThumb);
  display->setCursor(0,0);
  display->setTextColor(display->color565(125,125,125));  
  display->print("Bootstrap");
  display_ticker = new Ticker();
  display_ticker->attach_ms(2, &BootstrapDisplayImpl::display_updater, this);
}

// ISR for display refresh
void BootstrapDisplayImpl::display_updater(BootstrapDisplayImpl *bootstrapDisplay)
{
  bootstrapDisplay->display->display(bootstrapDisplay->display_draw_time);
}

void BootstrapDisplayImpl::setCursor(int16_t x, int16_t y) {
  display->setCursor(x, y + Y_FONT_OFFSET);
}

void BootstrapDisplayImpl::loop() {
}

void BootstrapDisplayImpl::clearDisplay () {
  displayDebug->debug("BootstrapDisplayImpl::clearDisplay");
  display->clearDisplay();
}

void BootstrapDisplayImpl::displayHour(int hour, int minutes) {
}

void BootstrapDisplayImpl::setCoordStatus (int i, int j, bool state) {
}

void BootstrapDisplayImpl::displayWifiStatus (bool displayWifi) {
  if (displayWifi == true && displayWifi != lastWifiStatus) {
    displayDebug->debug("BootstrapDisplayImpl::displayWifiStatus::true");
    clearDisplay();
    setCursor(0, 0);
    display->print("no wifi");
    lastWifiStatus = true;
  } else if (displayWifi != lastWifiStatus) {
    displayDebug->debug("BootstrapDisplayImpl::displayWifiStatus::false");
    lastWifiStatus = false;
  }
}

void BootstrapDisplayImpl::displayTemp (int temp) {
}

void BootstrapDisplayImpl::displayConfigurationMode (bool confEnabled) {
  displayDebug->debug("BootstrapDisplayImpl::displayConfigurationMode");
  if (confEnabled == true) {
    clearDisplay();
    setCursor(0, 0);
    display->print("Config");
  }
}

void BootstrapDisplayImpl::displayOtaProgress (int progressPercent) {
  displayDebug->debug("BootstrapDisplayImpl::displayOtaProgress");
  clearDisplay();
  setCursor(12, 4);
  display->print((String) progressPercent);  
}

void BootstrapDisplayImpl::displayIpAddress (String ipAddress) {
  displayDebug->debug("BootstrapDisplayImpl::displayIpAddress");
  clearDisplay();
  setCursor(0, 0);  
  display->print(ipAddress);
}
