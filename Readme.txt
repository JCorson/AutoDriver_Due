{\rtf1\ansi\ansicpg1252\cocoartf1343\cocoasubrtf160
{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural

\f0\fs24 \cf0 This library contains a modified version of Sparkfun\'92s Autodriver library to allow the Autodriver to be controlled by an Arduino Due. Note that I have not tested these libraries with any other microcontroller, so they may not work with other Arduino boards. I have also not thoroughly tested every function in the Autodriver library, but as far as i can tell everything is working as expected. Here is a brief summary of the main changes:\
\
Autodriver.h:\
Comment \'93private\'94 so that SPIConfig() is accessible. \
\
Autodriver.cpp:\
Changed SPIConfig() to set up the SPI configuration for the Due because the Due does not have and an SPI EEPROM. \
Note that now board.SPIConfig() must be called in the arduino setup\{\} loop.\
I have also removed the busyPin constructor as I never use it, but that should be able to be added back in if needed. \
The _delay_ms() function has also been changed to delayMicroseconds() and works because the function is being called in the arduino setup\{\} loop.\
\
The only other change that I had to make was to change all of the \'93for (char i = \'85)\'94 loops to \'93for (int i =\'85)\'94. I have no idea why the \'93char\'94 type doesn\'92t work in this instance, but A LOT of trial and error revealed this to be the case.\
\
I hope this helps!\
\
Jim}