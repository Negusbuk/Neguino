#include <Arduino.h>
#include <SPI.h>

#include <NSPIChipSelectGPIO.h>
#include <NMCP23S17.h>
#include <NStepper.h>
#include <NMultiStepper.h>

#define DATAOUT      11 // MOSI
#define DATAIN       12 // MISO 
#define SPICLOCK     13 // sck
#define CHIPSELECT1  10 // cs

Neguino::NMCP23S17* mcp;
Neguino::NStepper* stepper1;
Neguino::NStepper* stepper2;
Neguino::NStepper* stepper3;
Neguino::NStepper* stepper4;
Neguino::NMultiStepper* multiStepper;

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
    
  Neguino::NMCP23S17Pin* pin4  = mcp->getPin( 4);
  Neguino::NMCP23S17Pin* pin5  = mcp->getPin( 5);
  Neguino::NMCP23S17Pin* pin6  = mcp->getPin( 6);
  Neguino::NMCP23S17Pin* pin7  = mcp->getPin( 7);
  
  Neguino::NMCP23S17Pin* pin8  = mcp->getPin( 8);
  Neguino::NMCP23S17Pin* pin9  = mcp->getPin( 9);
  Neguino::NMCP23S17Pin* pin10 = mcp->getPin(10);
  Neguino::NMCP23S17Pin* pin11 = mcp->getPin(11);
  
  Neguino::NMCP23S17Pin* pin12 = mcp->getPin(12);
  Neguino::NMCP23S17Pin* pin13 = mcp->getPin(13);
  Neguino::NMCP23S17Pin* pin14 = mcp->getPin(14);
  Neguino::NMCP23S17Pin* pin15 = mcp->getPin(15);
  
  stepper1 = new Neguino::NStepper(128,  pin0,  pin1,  pin2,  pin3);
  stepper2 = new Neguino::NStepper(128,  pin4,  pin5,  pin6,  pin7);
  stepper3 = new Neguino::NStepper(128,  pin8,  pin9, pin10, pin11);
  stepper4 = new Neguino::NStepper(128, pin12, pin13, pin14, pin15);
  
  multiStepper = new Neguino::NMultiStepper();
  multiStepper->addStepper(stepper1);
  multiStepper->addStepper(stepper2);
  multiStepper->addStepper(stepper3);
  multiStepper->addStepper(stepper4);
  
  // this line is for Leonardo's, it delays the serial interface
  // until the terminal window is opened
  while (!Serial);
  Serial.println("HELLO");
}

void loop()
{
  Serial.print(mcp->readRegister(Neguino::NMCP23S17::GPIOA), HEX);
  Serial.print("\n");
  Serial.print(mcp->readRegister(Neguino::NMCP23S17::GPIOB), HEX);
  Serial.print("\n");
  Serial.print("\n");
  delay(2000);
  
  stepper1->step(100);
  
  multiStepper->step(0, -100);
  multiStepper->execute();
}

