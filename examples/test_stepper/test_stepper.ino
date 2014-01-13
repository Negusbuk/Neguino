#include <Arduino.h>
#include <SPI.h>

#include <NSPIChipSelectGPIO.h>
#include <NMCP23S17.h>
#include <NStepper.h>

#define DATAOUT      11 // MOSI
#define DATAIN       12 // MISO 
#define SPICLOCK     13 // sck
#define CHIPSELECT1  10 // cs

Neguino::NMCP23S17* mcp;
Neguino::NStepper* stepper;

void setup()
{  
  pinMode(DATAOUT, OUTPUT);
  pinMode(DATAIN, INPUT);
  pinMode(SPICLOCK, OUTPUT);

  SPI.begin();

  Neguino::NSPIChipSelectGPIO cs(CHIPSELECT1);
  mcp = new Neguino::NMCP23S17(cs, 0);
  mcp->init();
  
  Neguino::NMCP23S17Pin* pin0  = mcp->getPin( 0);
  Neguino::NMCP23S17Pin* pin1  = mcp->getPin( 1);
  Neguino::NMCP23S17Pin* pin2  = mcp->getPin( 2);
  Neguino::NMCP23S17Pin* pin3  = mcp->getPin( 3);
  
  stepper = new Neguino::NStepper(128,  pin0,  pin1,  pin2,  pin3);
  
  // this line is for Leonardo's, it delays the serial interface
  // until the terminal window is opened
  while (!Serial);
  Serial.println("HELLO");
}

void loop()
{
  stepper->step(200);

  delay(1000);

  stepper->step(-100);

  delay(1000);  
}

