#include "storeEeprom.h"

StoreEeprom::StoreEeprom() {

}

void StoreEeprom::setup (DebugInterface* di) {
  console = di;
  EEPROM.begin(512);
}

void StoreEeprom::loop () {
  
}

void StoreEeprom::write (char address, String data) {
  console->debug("StoreEeprom::write");
  EEPROM.begin(512);
  int _size = data.length();
  for (int i=0; i<_size; i++)
  {
    EEPROM.write(address+i,data[i]);
  }
  EEPROM.write(address+_size,'\0');
  bool result = EEPROM.commit();
  console->debug("StoreEeprom::write::success::"+(String) result);
  EEPROM.end();
}

String StoreEeprom::read (char address) {
  // console->debug("StoreEeprom::read : "+ (String) address);
  EEPROM.begin(512);
  char data[100]; //Max 100 Bytes
  int len=0;
  unsigned char k;
  k=EEPROM.read(address);
  while(k != '\0' && len<500)   //Read until null character
  {    
    k=EEPROM.read(address+len);
    data[len]=k;
    len++;
  }
  data[len]='\0';
  EEPROM.end();
  return String(data);
}