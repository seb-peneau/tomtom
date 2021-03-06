#include "components/board/boardInterface.h"
#include "components/debug/debugInterface.h"
#include "components/network/networkInterface.h"
#include "components/storage/storageInterface.h"
#include "./component/display/bootstrapDisplay.h"
#include "components/webserver/webserverinterface.h"
#include "components/ota/otaInterface.h"

#define SSIDSTORAGE "ssid"
#define PASSSTORAGE "pass"

#define APSSID "tamtam"
#define APPWD "T4MT4M"

class Domain {
  private:
    DebugInterface* debug;
    NetworkInterface* network;
    StorageInterface* storage;
    BootstrapDisplay* display;
    WebServerInterface* webServer;
    BoardInterface *board;
    OtaInterface *ota;

    // STATE MACHINE
    bool displayWifiAnimation;
    bool connectionInProgress;

    void handleSetupRequest ();
    void handleSaveConfiguration ();
    void handleConfiguration ();
    void handleConfigurationRequest ();
    void handleSoftReset ();
    void handleOtaProgress (unsigned int progress, unsigned int total);

  public:
    void setup ();
    void loop ();

    void setBoardInterface(BoardInterface* board);
    void setDebugInterface(DebugInterface* debug);
    void setNetworkInterface(NetworkInterface* network);
    void setStorageInterface(StorageInterface* storage);
    void setDisplayInterface(BootstrapDisplay* display);
    void setWebServerInterface(WebServerInterface* webServer);
    void setOtaInterface(OtaInterface* ota);
   
};


const String SETUPSTARTCONTENT = "\
  <html>\
    <head>\
    </head>\
    <body>\
      <h1>Welcome on configuration page of TOMTOM</h1>\
      <form method='POST' action='/conf' enctype='application/x-www-form-urlencoded'>\
        <select name='ssid'>\
";

const String SETUPENDCONTENT = "\
        </select>\
        <input type='text' placeholder='password' name='password' />\
        <input type='submit' value='submit' />\
    </body>\
  </html>\
";

const String CONFIGURATIONCONTENT = "\
  <html>\
    <head>\
    </head>\
    <body>\
      <h1>App configuration of TAMTAM</h1>\
      <form method='GET' action='/reset'>\
        <input type='submit' value='reset configuration' />\
      </form>\
    </body>\
  </html>\
";
