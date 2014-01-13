#include <Arduino.h>
#include <SPI.h>

#include <NSPIChipSelectGPIO.h>
#include <NMCP23S17.h>

#define DATAOUT      11 // MOSI
#define DATAIN       12 // MISO 
#define SPICLOCK     13 // sck
#define CHIPSELECT1  10 // cs

Neguino::NMCP23S17* mcp;
Neguino::NMCP23S17Pin* pin0;
Neguino::NMCP23S17Pin* pin1;

void setup()
{  
  pinMode(DATAOUT, OUTPUT);
  pinMode(DATAIN, INPUT);
  pinMode(SPICLOCK, OUTPUT);

  SPI.begin();

  Neguino::NSPIChipSelectGPIO cs(CHIPSELECT1);
  mcp = new Neguino::NMCP23S17(cs, 0);
  mcp->init();
  
  pin0 = mcp->getPin(Neguino::NMCP23S17::GPIOB0);
  pin1 = mcp->getPin(Neguino::NMCP23S17::GPIOB1);

  // this line is for Leonardo's, it delays the serial interface
  // until the terminal window is opened
  while (!Serial);
  Serial.begin(9600);
}

void loop()
{
  Serial.print("GPIOA: ");
  Serial.print(mcp->readRegister(Neguino::NMCP23S17::GPIOA), HEX);
  Serial.print("\n");

  Serial.print("GPIOB: ");
  Serial.print(mcp->readRegister(Neguino::NMCP23S17::GPIOB), HEX);
  Serial.print("\n");
  
  Serial.print("pin 0: ");
  Serial.print(pin0->read(), HEX);
  Serial.print("\n");
  
  Serial.print("pin 1: ");
  Serial.print(pin1->read(), HEX);
  Serial.print("\n");
  
  Serial.print("\n");
  
  delay(1000);
}

