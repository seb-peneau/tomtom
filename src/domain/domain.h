#include "Arduino.h"

#include "../ports/board/boardInterface.h"
#include "../ports/debug/debugInterface.h"
#include "../ports/network/networkInterface.h"
#include "../ports/storage/storageInterface.h"
#include "../ports/display/displayInterface.h"
#include "../ports/webserver/webserverinterface.h"
#include "../ports/ota/otaInterface.h"
#include "../ports/time/timeInterface.h"

#define SSIDSTORAGE 10
#define PASSSTORAGE 60

#define APSSID "tamtam"
#define APPWD "T4MT4M"

class Domain {
  private:
    DebugInterface* debug;
    NetworkInterface* network;
    StorageInterface* storage;
    DisplayInterface* display;
    WebServerInterface* webServer;
    BoardInterface *board;
    OtaInterface *ota;
    TimeInterface *time;

    // STATE MACHINE
    bool displayWifiAnimation;

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
    void setDisplayInterface(DisplayInterface* display);
    void setWebServerInterface(WebServerInterface* webServer);
    void setOtaInterface(OtaInterface* ota);
    void setTimeInterface(TimeInterface *time);
    
};


const String SETUPSTARTCONTENT = "\
  <html>\
    <head>\
    </head>\
    <body>\
      <h1>Welcome on configuration page of TAMTAM</h1>\
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
