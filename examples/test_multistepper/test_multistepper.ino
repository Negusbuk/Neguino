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
Neguino::NStepper* stepper0;
Neguino::NStepper* stepper1;
Neguino::NMultiStepper* multiStepper;

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
  
  Neguino::NMCP23S17Pin* pin4  = mcp->getPin(Neguino::NMCP23S17::GPIOB4);
  Neguino::NMCP23S17Pin* pin5  = mcp->getPin(Neguino::NMCP23S17::GPIOB5);
  Neguino::NMCP23S17Pin* pin6  = mcp->getPin(Neguino::NMCP23S17::GPIOB6);
  Neguino::NMCP23S17Pin* pin7  = mcp->getPin(Neguino::NMCP23S17::GPIOB7);
  
  stepper0 = new Neguino::NStepper(48,  pin0,  pin1,  pin2,  pin3);
  stepper0->setSpeed(200);
  stepper0->singleStep(1);
  
  stepper1 = new Neguino::NStepper(48,  pin4,  pin5,  pin6,  pin7);
  stepper1->setSpeed(200);
  stepper1->singleStep(1);
  
  multiStepper = new Neguino::NMultiStepper();
  multiStepper->addStepper(stepper0);
  multiStepper->addStepper(stepper1);
  
  // this line is for Leonardo's, it delays the serial interface
  // until the terminal window is opened
  while (!Serial);
  Serial.begin(9600);
  
  inputString.reserve(32);
}

void loop()
{
  if (stringComplete) {
    
    int index = inputString.indexOf(',');
    
    if (index!=-1) {
      
      int stepper = inputString.substring(0, index).toInt();
      int steps = inputString.substring(index+1).toInt();
    
      multiStepper->step(stepper, steps);
    
      Serial.print("stepper ");
      Serial.print(stepper, DEC);
      Serial.print(": ");
      Serial.print(steps, DEC);
      Serial.println(" steps"); 
    } else if (inputString.startsWith("x")) {
      Serial.println("execute");
      multiStepper->execute();
    }
    
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
