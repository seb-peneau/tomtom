#include "displayv2.h"

DisplayV2::DisplayV2 () {
  display = new MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);
  displayController = display->getGraphicObject();
}

void DisplayV2::setup () {
  display->begin(2);
  display->setZone(0, 1, 3);
  display->setZone(1, 4, 7);
  display->setZone(2, 0, 1);
  display->setFont(myFont);
  display->displayReset();
  display->displayZoneText(0, "1", PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
  display->displayZoneText(1, "hello", PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
  
}

void DisplayV2::loop () {
  display->displayAnimate();
}

void DisplayV2::clearDisplay () {
  displayController->clear();
  display->begin(2);
  display->setZone(0, 0, 3);
  display->setZone(1, 4, 7);  
  display->setFont(myFont);
  display->displayReset();
}

void DisplayV2::displayHexagon() {
}

void DisplayV2::displayHour(int hour, int minutes) {
  String hourM = hour < 10  ? "0" + (String) hour : (String) hour;
  String minutesM = minutes < 10  ? "0" + (String) minutes : (String) minutes;
  String hourModel = (String) hourM + ":" + (String) minutesM;
  strcpy(cHour, hourModel.c_str());
  display->displayZoneText(0, cHour, PA_LEFT, 0, 0, PA_PRINT, PA_NO_EFFECT);
}

void DisplayV2::setCoordStatus (int i, int j, bool state) {
}

void DisplayV2::displayWifiStatus (bool wifiStatus) {
  if (wifiStatus == false) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousWifiMillis > 100) {
      searchForWifi();
      previousWifiMillis = currentMillis;
    }    
  } else {
    wifiAnimState = 0;
  }
}

void DisplayV2::searchForWifi () {
  if (wifiAnimState == 0) {
    displayController->clear();
    displayController->setPoint(3, 15, true);
    displayController->setPoint(3, 16, true);
    displayController->setPoint(4, 15, true);
    displayController->setPoint(4, 16, true);    
  }
  if (wifiAnimState == 1 or wifiAnimState == 4) {
    bool isDisplayed = (wifiAnimState == 1);
    displayController->setPoint(2, 13, isDisplayed);
    displayController->setPoint(1, 14, isDisplayed);
    displayController->setPoint(1, 15, isDisplayed);
    displayController->setPoint(1, 16, isDisplayed); 
    displayController->setPoint(1, 17, isDisplayed); 
    displayController->setPoint(2, 18, isDisplayed);
  }
  if (wifiAnimState == 2 or wifiAnimState == 5) {
    bool isDisplayed = (wifiAnimState == 2);    
    displayController->setPoint(1, 11, isDisplayed);
    displayController->setPoint(0, 12, isDisplayed);
    displayController->setPoint(0, 19, isDisplayed);
    displayController->setPoint(1, 20, isDisplayed); 
    displayController->setPoint(7, 13 + ZONE_SIZE, isDisplayed);
    displayController->setPoint(7, 14 + ZONE_SIZE, isDisplayed);
    displayController->setPoint(7, 15 + ZONE_SIZE, isDisplayed);
    displayController->setPoint(7, 16 + ZONE_SIZE, isDisplayed);
    displayController->setPoint(7, 17 + ZONE_SIZE, isDisplayed);
    displayController->setPoint(7, 18 + ZONE_SIZE, isDisplayed);
  }
  if (wifiAnimState == 3 or wifiAnimState == 6) {
    bool isDisplayed = (wifiAnimState == 3);    
    displayController->setPoint(0, 9, isDisplayed);
    displayController->setPoint(0, 22, isDisplayed);
    displayController->setPoint(7, 10 + ZONE_SIZE, isDisplayed);
    displayController->setPoint(7, 21 + ZONE_SIZE, isDisplayed);    
    displayController->setPoint(6, 11 + ZONE_SIZE, isDisplayed);
    displayController->setPoint(6, 20 + ZONE_SIZE, isDisplayed);    
    displayController->setPoint(5, 12 + ZONE_SIZE, isDisplayed);
    displayController->setPoint(5, 13 + ZONE_SIZE, isDisplayed);
    displayController->setPoint(5, 14 + ZONE_SIZE, isDisplayed);
    displayController->setPoint(5, 15 + ZONE_SIZE, isDisplayed);
    displayController->setPoint(5, 16 + ZONE_SIZE, isDisplayed);
    displayController->setPoint(5, 17 + ZONE_SIZE, isDisplayed);
    displayController->setPoint(5, 18 + ZONE_SIZE, isDisplayed);
    displayController->setPoint(5, 19 + ZONE_SIZE, isDisplayed);
  }  
  wifiAnimState = wifiAnimState + 1;
  if (wifiAnimState > 6) {
    wifiAnimState = 1;
  }
}


void DisplayV2::displayTemp (int temp) {
  String tempModel = (String) temp + "°";
  strcpy(cTemp, tempModel.c_str());
  display->displayZoneText(2, cTemp, PA_RIGHT, 0, 0, PA_PRINT, PA_NO_EFFECT);
}

void DisplayV2::displayConfigurationMode (bool confEnabled) {
}

void DisplayV2::displayOtaProgress (int progressPercent) {
  if (progressPercent == 0) {
    clearDisplay();
    displayController->setPoint(0, 0, true);
    displayController->setPoint(7, 32, true);
    displayController->setPoint(7, 63, true);
    displayController->setPoint(0, 31, true);
    for (int i = 0; i < ZONE_SIZE; i++) {
      displayController->setPoint(1, i, true);
      displayController->setPoint(6, i+ZONE_SIZE, true);
    }
  }
  // 28 leds for 100 percent
  int led = (int) (28 * progressPercent / 100);
  displayController->setPoint(7, (2*ZONE_SIZE) - (3 + led), true);
  displayController->setPoint(0, ZONE_SIZE - (3 + led), true);
}