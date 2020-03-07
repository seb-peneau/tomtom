#include "laboite.h"

LedDisplayImpl::LedDisplayImpl () {
}

void LedDisplayImpl::setup () {
  Serial.println("LedDisplayImpl::setup");
  ledControl = new LedControl(DIN, CLK, CS, 8);
  //we have already set the number of devices when we created the LedControl
  int devices = ledControl->getDeviceCount();
  //we have to init all devices in a loop
  for(int address = 0; address < devices; address++) {
    /*The MAX72XX is in power-saving mode on startup*/
    ledControl->shutdown(address,false);
    /* Set the brightness to a medium values */
    ledControl->setIntensity(address,8);
    /* and clear the display */
    ledControl->clearDisplay(address);
  }
  ticker = new Ticker();
  ticker->attach_ms(5, &LedDisplayImpl::staticDrawCallback, this);
}

void LedDisplayImpl::clearDisplay () {
  for (int i = 0; i < 32; i++) {
    for (int j = 0; j < 16; j++) {
      nextLedState[i][j] = false;
    }
  }
}

void LedDisplayImpl::displayNumber(int number, int posX, int posY) {
  for (int i=0; i < 3; i++) {
    for (int j=0; j < 5; j++) {
      bool di = numbers[number][i][j] == 1 ? true : false;
      nextLedState[posX+i][posY+j] = di;
    } 
  }
}

void LedDisplayImpl::displayHexagon() {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis > 100) {
      renderHexagon();
      previousMillis = currentMillis;
    }
}

void LedDisplayImpl::renderHexagon() {
  switch (currentHexaAnimState)
  {
  case 0: nextLedState[0][15] = true; break;
  case 1: nextLedState[1][15] = true; break;
  case 2: nextLedState[2][15] = true; break;
  case 3: nextLedState[3][15] = true; break;
  case 4: nextLedState[4][15] = true; break;
  case 5: nextLedState[5][15] = true; break;
  case 6: nextLedState[6][15] = true; break;
  case 7: nextLedState[7][15] = true; break;
  case 8: nextLedState[8][15] = true; break;
  case 9: nextLedState[9][15] = true; break;
  case 10: nextLedState[10][15] = true; break;
  case 11: nextLedState[11][15] = true; break;
  case 12: nextLedState[12][15] = true; break;
  case 13: nextLedState[13][15] = true; break;
  case 14: nextLedState[14][15] = true; break;
  case 15: nextLedState[15][15] = true; break;
  case 16: nextLedState[16][15] = true; break;
  case 17: nextLedState[17][15] = true; break;
  case 18: nextLedState[18][15] = true; break;
  case 19: nextLedState[19][14] = true; break; //start diag up right
  case 20: nextLedState[20][13] = true; break;
  case 21: nextLedState[21][12] = true; break;
  case 22: nextLedState[22][11] = true; break;
  case 23: nextLedState[23][10] = true; break;
  case 24: nextLedState[23][9] = true; break; //start line up
  case 25: nextLedState[23][8] = true; break;
  case 26: nextLedState[23][7] = true; break;
  case 27: nextLedState[23][6] = true; break;
  case 28: nextLedState[23][5] = true; break;
  case 29: nextLedState[22][4] = true; break; //start diag up left
  case 30: nextLedState[21][3] = true; break;
  case 31: nextLedState[20][2] = true; break;
  case 32: nextLedState[19][1] = true; break;
  case 33: nextLedState[18][0] = true; break;
  case 34: nextLedState[17][0] = true; break; //start line left
  case 35: nextLedState[16][0] = true; break;
  case 36: nextLedState[15][0] = true; break; // middle
  case 37: nextLedState[14][0] = true; nextLedState[0][15] = false; break;
  case 38: nextLedState[13][0] = true; nextLedState[1][15] = false; break;
  case 39: nextLedState[12][1] = true; nextLedState[2][15] = false; break; // start diag bot left
  case 40: nextLedState[11][2] = true; nextLedState[3][15] = false; break;
  case 41: nextLedState[10][3] = true; nextLedState[4][15] = false; break;
  case 42: nextLedState[9][4] = true; nextLedState[5][15] = false; break;
  case 43: nextLedState[8][5] = true; nextLedState[6][15] = false; break;
  case 44: nextLedState[8][6] = true; nextLedState[6][15] = false; break; // start line bot
  case 45: nextLedState[8][7] = true; nextLedState[6][15] = false; break;
  case 46: nextLedState[8][8] = true; nextLedState[6][15] = false; break;
  case 47: nextLedState[8][9] = true; nextLedState[6][15] = false; break;
  case 48: nextLedState[8][10] = true; nextLedState[6][15] = false; break;
  case 49: nextLedState[9][11] = true; nextLedState[6][15] = false; break; // start diag bot right
  case 50: nextLedState[10][12] = true; nextLedState[6][15] = false; break;
  case 51: nextLedState[11][13] = true; nextLedState[6][15] = false; break;
  case 52: nextLedState[12][14] = true; nextLedState[6][15] = false; break;
  case 53: nextLedState[13][15] = true; nextLedState[6][15] = false; break;  

  default:
    break;
  }
  currentHexaAnimState++;
}

void LedDisplayImpl::displayHour(int hour, int minutes) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousTimeMillis > 10000) {
      int one = hour / 10;
      displayNumber(one, 0, 11);
      int rem = hour - (one * 10);
      displayNumber(rem, 4, 11);
      one = minutes / 10;
      displayNumber(one, 9, 11);
      rem = minutes - (one * 10);
      displayNumber(rem, 13, 11);
    }
}

void LedDisplayImpl::setCoordStatus (int i, int j, bool state) {
  if (j > 7) {
    i = i + 32;
    j = j - 8;
  }  
  int screen = i / 8;
  int x = 7 - (i - (screen * 8));
  int y = 7 - j;
  ledControl->setLed(screen, y, x, state);
}

void LedDisplayImpl::displayWifiStatus (bool wifiStatus) {
  if (wifiStatus != lastWifiStatus) {
    clearDisplay();
    lastWifiStatus = wifiStatus;
  }
  if (wifiStatus == false) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis > 100) {
      searchForWifi();
      previousMillis = currentMillis;
    }
  } else {
    currentWifiAnimState = 0;
  }
}

void LedDisplayImpl::searchForWifi () {
  if (currentWifiAnimState == 0 or currentWifiAnimState == 4) {
    int startX = wifiSignalStep1[0];
    for (int i = 1; i < 3; i++) {
      nextLedState[startX + i -1][wifiSignalStep1[i]] = (currentWifiAnimState == 0);
    }
  }
  if (currentWifiAnimState == 1 or currentWifiAnimState == 5) {
    int startX = wifiSignalStep2[0];
    for (int i = 1; i < 7; i++) {
      nextLedState[startX + i -1][wifiSignalStep2[i]] = (currentWifiAnimState == 1);
    }
  }
  if (currentWifiAnimState == 2 or currentWifiAnimState == 6) {
    int startX = wifiSignalStep3[0];
    for (int i = 1; i < 11; i++) {
      nextLedState[startX + i -1][wifiSignalStep3[i]] = (currentWifiAnimState == 2);
    }
  }
  if (currentWifiAnimState == 3 or currentWifiAnimState == 7) {
    int startX = wifiSignalStep4[0];
    for (int i = 1; i < 15; i++) {
      nextLedState[startX + i -1][wifiSignalStep4[i]] = (currentWifiAnimState == 3);
    }
  }
  currentWifiAnimState = currentWifiAnimState + 1;
  if (currentWifiAnimState > 7) {
    currentWifiAnimState = 0;
  }
}

void LedDisplayImpl::drawCallback () {
  for (int i = 0; i < 32; i++) {
    for (int j = 0; j < 16; j++) {
      if (nextLedState[i][j] != currentLedState[i][j]) {
        currentLedState[i][j] = nextLedState[i][j];
        setCoordStatus(i, j, currentLedState[i][j]);
      }
    }
  } 
}

void LedDisplayImpl::displayTemp (int temp) {
  if (temp > 9) {
    int one = temp / 10;
    displayNumber(one, 21, 11);
    int rem = temp - (one * 10);
    displayNumber(rem, 25, 11);
  } else {
    displayNumber(temp, 25, 11);
  }
  nextLedState[29][11] = nextLedState[29][12] = nextLedState[30][11] = nextLedState[30][12] = true;
}

void LedDisplayImpl::displayConfigurationMode (bool confEnabled) {
  for (int i=0; i < 14; i++) {
    for (int j=0; j < 14; j++) {
      bool di = params[i][j] == 1 ? true : false;
      nextLedState[9+i][1+j] = di;
    } 
  }
}

void LedDisplayImpl::staticDrawCallback (LedDisplayImpl *led) {
  led->drawCallback();
}

void LedDisplayImpl::displayOtaProgress (int progressPercent) {
  if (progressPercent == 0) {
    clearDisplay();
    nextLedState[1][8] = true;
    nextLedState[1][9] = true;
    nextLedState[30][8] = true;
    nextLedState[30][9] = true;      
    for (int i = 0; i < 30; i++) {
      nextLedState[1+i][7] = true;
      nextLedState[1+i][10] = true;
    }
  }
  // 28 leds for 100 percent
  int led = (int) (28 * progressPercent / 100);
  nextLedState[1+led][8] = true;
  nextLedState[1+led][9] = true;
}