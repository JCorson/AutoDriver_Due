
#include <SPI.h>
#include "AutoDriver_Due.h"
AutoDriver_Due board(10,6); //AutoDriver(int CSPin, int resetPin);

    
void setup() {  
// Configure SPI
  board.SPIConfig();
  delayMicroseconds(100);

// Reset each axis 
  board.resetDev(); 
  delayMicroseconds(100);
  
// Configure each axis 
  dSPINConfig_board();
  delayMicroseconds(100);

// Get the status to clear the UVLO Flag
  board.getStatus();

}

void loop() {
  
}
