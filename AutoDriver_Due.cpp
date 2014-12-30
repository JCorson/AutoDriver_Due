#include "AutoDriver_Due.h"
#include "SPI.h"


//// Constructors

AutoDriver_Due::AutoDriver_Due(int CSPin, int resetPin)
{
  _CSPin = CSPin;
  _resetPin = resetPin;
  _busyPin = -1;

//  SPIConfig();
}

void AutoDriver_Due::SPIConfig()
{
  pinMode(_CSPin, OUTPUT);
  digitalWrite(_CSPin, HIGH);
  pinMode(_resetPin, OUTPUT);
  digitalWrite(_resetPin, HIGH);

  if (_busyPin != -1) pinMode(_busyPin, INPUT_PULLUP);
  
// Let's set up the SPI peripheral. SPCR first:
  //  bit 7 - SPI interrupt (disable)
  //  bit 6 - SPI peripheral enable (enable)
  //  bit 5 - data order (MSb first)
  //  bit 4 - master/slave select (master mode)
  //  bit 3 - CPOL (active high)
  //  bit 2 - CPHA (sample on rising edge)
  //  bit 1:0 - data rate (8 or 16, depending on SPSR0)
  //SPCR = B01011101;
    

  // SPSR next- not much here, just SPI2X
  //  bit 0 - double clock rate (no)
  // SPSR = B00000000;

    SPI.begin();
    SPI.setBitOrder(MSBFIRST);
    SPI.setDataMode(SPI_MODE3);
    SPI.setClockDivider(42);
  
  // From now on, any data written to SPDR will be pumped out over the SPI pins
  //  and SPSR7 will be set when data TX/RX is complete. Read SPSR, then SPDR, to
  //  clear.
    
    digitalWrite(_resetPin, LOW);
    delayMicroseconds(5000);
    digitalWrite(_resetPin, HIGH);
    delayMicroseconds(5000);
    
}

int AutoDriver_Due::busyCheck(void)
{
  if (_busyPin == -1)
  {
    if (getParam(STATUS) & 0x0002) return 0;
    else                           return 1;
  }
  else 
  {
    if (digitalRead(_busyPin) == HIGH) return 0;
    else                               return 1;
  }
}
