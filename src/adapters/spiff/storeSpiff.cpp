#include "storeSpiff.h"

StoreSpiff::StoreSpiff() {

}

void StoreSpiff::setup (DebugInterface* di) {
  console = di;
}

void StoreSpiff::loop () {
  
}

void StoreSpiff::write (char address, String data) {
  console->debug("StoreSpiff::write");
  SPIFFS.begin();
  File dataFile = SPIFFS.open("/"+(String) address, "w");
  //Affichage des données du fichier
  dataFile.print(data);
  dataFile.flush();
  dataFile.close();  
}

String StoreSpiff::read (char address) {
  console->debug("StoreSpiff::read");
  SPIFFS.begin();
  File dataFile = SPIFFS.open("/"+(String) address, "r");
  //Affichage des données du fichier
  String result = dataFile.readString();
  dataFile.close();  
  return result;
}