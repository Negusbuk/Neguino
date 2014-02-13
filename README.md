Neguino
=======

Neguino is a collection of C++ classes intended to provide a simple interface
to the Arduino electronics platform. Currently classes exist for the Arduino
GPIO pins, SPI port expander chips as well as SPI EEPROM. In addition, a
generic stepper motor class is provided that is not limited to the Arduino
GPIO pins. Several stepper motors can be controlled in parallel via dedicated
classes.

NMCP23S08 - a class for the MCP23S08 io expansion chip
NMCP23S17 - a class for the MCP23S17 io expansion chip
NSPIEEPROM25AA128k - a class for a 25AA128k type SPI eeprom
NStepper - a generic stepper motor class
NMultiStepper - a class for stepping multiple stepper motors
NSyncMultiStepper - a class for stepping multiple stepper motors synchronously
