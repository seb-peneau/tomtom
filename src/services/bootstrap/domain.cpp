#include "domain.h"

int count = 0;

void Domain::setup() {
  debug->debug("Domain::setup");
  network->setup(debug);
  storage->setup(debug);
  webServer->setup(debug);
  display->setup(debug);

  displayWifiAnimation = false;

  // reset was triggered by user input on reset button
  // remove configuration
  if (board->isUserTriggeredReset()) {
    storage->write(SSIDSTORAGE, "");
    storage->write(PASSSTORAGE, "");
  }
  connectionInProgress = false;
  String ssid = storage->read(SSIDSTORAGE);
  String password = storage->read(PASSSTORAGE);
  if (ssid != "" && password != "") {
    displayWifiAnimation = true;
    network->connect(ssid, password);
    connectionInProgress = true;
  }
}

void Domain::loop() {
  network->loop();
  webServer->loop();
  display->loop();
  display->displayWifiStatus(displayWifiAnimation);

  // Network disconnected
  if (network->isConnected() == false) {
    // Access point is not created
    if (network->isApCreated() == false && storage->read(SSIDSTORAGE) == "") { // First time launch no network
      displayWifiAnimation = false;
      bool result = network->createAccessPoint(APSSID, APPWD);
      if (result == true) { // Create Webserver
        display->displayConfigurationMode(true);
        webServer->startWebServer(80);
        webServer->on("/", "GET", [&, this](){
          debug->debug("Domain::on GET /");
          return handleSetupRequest ();
        });
        webServer->on("/conf", "POST", [&, this](){
          debug->debug("Domain::on POST /conf");
          return handleSaveConfiguration ();
        });
      }
    }
    if (network->isApCreated() == false 
        && storage->read(SSIDSTORAGE) != "" 
        && connectionInProgress == false) { // Network is lost try to reconnect
      String ssid = storage->read(SSIDSTORAGE);
      String password = storage->read(PASSSTORAGE);
      if (ssid != "" && password != "") {
        displayWifiAnimation = true;
        network->connect(ssid, password);
        connectionInProgress = true;
      }      
    }
  } else { // Network is up and running
    connectionInProgress = false;
    if (network->isApCreated()) { // close AccessPoint and firstInstall webserver
      webServer->stopWebServer();
      network->closeAccessPoint(); 
    }  
    if (displayWifiAnimation == true) {
      ota->setup(debug);
      debug->debug(network->getIpAddress());
      ota->onProgress([&, this](unsigned int progress, unsigned int total){
          debug->debug("Domain::on handleOtaProgress");
          return handleOtaProgress(progress, total);
      });
      display->displayIpAddress(network->getIpAddress());      
      displayWifiAnimation = false;
    }
    ota->loop();

    // start configuration webserver
    if (webServer->isStarted() == false) {
      handleConfiguration();
    }

    // Do something bootstrap went fine
    // WARNING : YOU ARE IN LOOP :)
  } 
}

/**
 * handleSetupRequest: Handle Http configuration request on main page ("/") 
 **/
void Domain::handleSetupRequest () {
  debug->debug("Domain::handleSetupRequest");
  String content = "";
  std::vector<String> networkList = network->listNetworks();
  if (networkList.size() > 0) {
    for (int i = 0; i < networkList.size(); i++) {
      content += ("<option value='" + networkList[i] + "'>" + networkList[i] + "</option>");
    }
  }
  webServer->serve(200, "text/html", SETUPSTARTCONTENT + content + SETUPENDCONTENT);
}

/**
 * handleSaveConfiguration: Handle POST request to get the configuration
 **/
void Domain::handleSaveConfiguration () {
  debug->debug("Domain::handleSaveConfiguration");
  String ssid = webServer->getBodyField("ssid");
  String pass = webServer->getBodyField("password");
  storage->write(SSIDSTORAGE, ssid);
  storage->write(PASSSTORAGE, pass);
  display->displayConfigurationMode(false);
  displayWifiAnimation = true;
  webServer->serve(200, "text/html", "<html><body>ok</body></html>");
  webServer->stopWebServer();
  network->closeAccessPoint();
  network->connect(ssid, pass);
}

/**
 * handleConfiguration : Manage in app configuration for TAMTAM
 * 
 * */
void Domain::handleConfiguration () {
  debug->debug("Domain::handleConfiguration");
  webServer->startWebServer(80); 
  webServer->on("/", "GET", [&, this](){
    debug->debug("Domain::on GET /");
    return handleConfigurationRequest ();
  });
  webServer->on("/reset", "GET", [&, this](){
    debug->debug("Domain::on GET /reset");
    return handleSoftReset ();
  });  
}


/**
 * handleSetupRequest: Handle Http configuration request on main page ("/") 
 **/
void Domain::handleConfigurationRequest () {
  debug->debug("Domain::handleConfigurationRequest");
  webServer->serve(200, "text/html", CONFIGURATIONCONTENT);
}

/**
 * handleSoftReset: Handle configuration reset in case there is no button on the board
 */
void Domain::handleSoftReset () {
  debug->debug("Domain::handleSoftReset");
  storage->write(SSIDSTORAGE, "");
  storage->write(PASSSTORAGE, "");
  network->disconnect();
  webServer->serve(200, "text/html", "<html><body>ok</body></html>");
}

void Domain::handleOtaProgress (unsigned int progress, unsigned int total) {
  double progressP = (float) progress / (float) total;
  int progressPercent = progressP * 100;
  display->displayOtaProgress(progressPercent);
}

void Domain::setBoardInterface (BoardInterface *bI) {
  board = bI;
}

void Domain::setDebugInterface(DebugInterface* dI) {
  debug = dI;
}

void Domain::setNetworkInterface (NetworkInterface* nI) {
  network = nI;
}

void Domain::setStorageInterface (StorageInterface* sI) {
  storage = sI;
}

void Domain::setDisplayInterface (DisplayInterface* dI) {
  display = dI;
}

void Domain::setWebServerInterface (WebServerInterface* wsI) {
  webServer = wsI;
}

void Domain::setOtaInterface (OtaInterface* oI) {
  ota = oI;
}