#include "wifi.h"


EspWifi::EspWifi () {
}

void EspWifi::setup (DebugInterface* dI) {
  debug = dI;
  apcreated = false;
}

void EspWifi::loop () {
}

bool EspWifi::isConnected () {
  int wifiStatus = WiFi.status();
  if (apcreated == false) {
    if (wifiStatus == WL_CONNECTED) {
      isConnecting = false;
      return true;
    } else {
      return false;
    }
  } else { // don't care about AccessPoint events
    return false;
  }
}

bool EspWifi::isApCreated () {
  return apcreated;
}

bool EspWifi::createAccessPoint (String apSsid, String apPass) {
  if (!isConnecting) {
    debug->debug("Create access point....");
    bool res = false;
    res = WiFi.softAP(apSsid);
    IPAddress myIp = WiFi.softAPIP();
    debug->debug("AP IP ADDRESS : " + myIp.toString());
    apcreated = true;
    return res;
  } else {
    return false;
  }
}

void EspWifi::closeAccessPoint () {
  debug->debug("Disconnect access point");
  WiFi.softAPdisconnect();
  apcreated = false;
}

void EspWifi::connect (String ssid, String password) {
  debug->debug("EspWifi::connect");
  isConnecting = true;
  WiFi.begin(ssid, password);
}

void EspWifi::disconnect () {
  WiFi.disconnect();
  isConnecting = false;
}

std::vector<String> EspWifi::listNetworks () {
  int n = WiFi.scanNetworks(false, false);
  std::vector<String> results;
  for (int i = 0; i < n; i++) {
    String ssid;
    uint8_t encryptionType;
    int32_t RSSI;
    uint8_t* BSSID;
    int32_t channel;
    bool isHidden;    
    WiFi.getNetworkInfo(i, ssid, encryptionType, RSSI, BSSID, channel, isHidden);
    debug->debug(ssid + "nb : " + (String) i);
    results.push_back(ssid);
  }
  return results;
}

String EspWifi::getIpAddress () {
  return WiFi.localIP().toString();
}