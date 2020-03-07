#include "console.h"

Console::Console () {
  #ifdef DEBUG
  Serial.begin(BAUDRATE);
  #endif  
}

void Console::debug (String message) {
  #ifdef DEBUG
  Serial.println(message);
  #endif  
}