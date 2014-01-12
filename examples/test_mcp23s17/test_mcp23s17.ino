#include <Arduino.h>
#include <SPI.h>

#include <NSPIChipSelectGPIO.h>
#include <NMCP23S17.h>

#define DATAOUT      11 // MOSI
#define DATAIN       12 // MISO 
#define SPICLOCK     13 // sck
#define CHIPSELECT1  10 // cs

Neguino::NMCP23S17* mcp;

void setup()
{
  Serial.begin(9600);

  pinMode(DATAOUT, OUTPUT);
  pinMode(DATAIN, INPUT);
  pinMode(SPICLOCK, OUTPUT);

  SPI.begin();

  Neguino::NSPIChipSelectGPIO cs(CHIPSELECT1);
  mcp = new Neguino::NMCP23S17(cs, 0);
  mcp->init();
}

void loop()
{
  Serial.print(mcp->readRegister(Neguino::NMCP23S17::GPIOA), HEX);
  Serial.print("\n");
  Serial.print(mcp->readRegister(Neguino::NMCP23S17::GPIOB), HEX);
  Serial.print("\n");
  Serial.print("\n");
  delay(2000);
}

