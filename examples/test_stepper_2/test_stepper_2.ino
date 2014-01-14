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

String inputString = "";
boolean stringComplete = false;

void setup()
{  
  pinMode(DATAOUT, OUTPUT);
  pinMode(DATAIN, INPUT);
  pinMode(SPICLOCK, OUTPUT);

  SPI.begin();

  Neguino::NSPIChipSelectGPIO cs(CHIPSELECT1);
  mcp = new Neguino::NMCP23S17(cs, 0);
  mcp->init();
  
  Neguino::NMCP23S17Pin* pin0  = mcp->getPin(Neguino::NMCP23S17::GPIOB0);
  Neguino::NMCP23S17Pin* pin1  = mcp->getPin(Neguino::NMCP23S17::GPIOB1);
  Neguino::NMCP23S17Pin* pin2  = mcp->getPin(Neguino::NMCP23S17::GPIOB2);
  Neguino::NMCP23S17Pin* pin3  = mcp->getPin(Neguino::NMCP23S17::GPIOB3);
  
  stepper = new Neguino::NStepper(48,  pin0,  pin1,  pin2,  pin3);
  stepper->setSpeed(100);
  stepper->singleStep(1);
  
  // this line is for Leonardo's, it delays the serial interface
  // until the terminal window is opened
  while (!Serial);
  Serial.begin(9600);
  
  inputString.reserve(32);
}

void loop()
{
  if (stringComplete) {
    int steps = inputString.toInt();
    
    stepper->step(steps);
    
    Serial.print("stepper: ");
    Serial.print(steps, DEC);
    Serial.println(" steps"); 
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}

void serialEvent()
{
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
