This library contains a modified version of Sparkfun's Autodriver library to allow the Autodriver to be controlled by an Arduino Due. Note that I have not tested these libraries with any other microcontroller, so they may not work with other Arduino boards. I have also not thoroughly tested every function in the Autodriver library, but as far as I can tell everything is working as expected. Here is a brief summary of the main changes:

Autodriver.h:
Comment private so that SPIConfig() is accessible. 

Autodriver.cpp:
Changed SPIConfig() to set up the SPI configuration for the Due because the Due does not have and an SPI EEPROM. 
Note that now board.SPIConfig() must be called in the arduino setup loop.
I have also removed the busyPin constructor as I never use it, but that should be able to be added back in if needed. 
The _delay_ms() function has also been changed to delayMicroseconds() and works because the function is being called in the arduino setup loop.

The only other change that I had to make was to change all of the "for (char i = )" loops to "for (int i =)". I have no idea why the "char" type doesn't work in this instance, but A LOT of trial and error revealed this to be the case.

I hope this helps!

Jim
