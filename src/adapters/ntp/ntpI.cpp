#include "ntp.h"

void Ntp::setup () {
  timeClient = new NTPClient(ntpUDP);
}

void Ntp::start () {
  if (isInitialized == false) {
    timeClient->begin();
    timeClient->update();
    isInitialized = true;
  }
}

void Ntp::loop () {
  unsigned long currentMillis = millis();
  if (currentMillis - previousTimeUpdate > 20000) {
    previousTimeUpdate = currentMillis;
    timeClient->update();
  }
}

int Ntp::getHour () {
  int hour = timeClient->getHours() + 1;
  hour = hour == 24 ? 0 : hour; 
  return hour; 
}

int Ntp::getMinutes () {
  return timeClient->getMinutes();
}
