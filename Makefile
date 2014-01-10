HEADERS = NTools.h \
		  NSPIChipSelect.h \
		  NSPIChipSelectGPIO.h

MODULES	= NSPIChipSelectGPIO
		  
CXX		  = /Applications/Arduino.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-g++
CXXFLAGS  = -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections
CXXFLAGS += -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=151
CXXFLAGS += -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/avr/cores/arduino
CXXFLAGS += -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/avr/variants/standard
CXXFLAGS += -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/avr/libraries/SPI
CXXFLAGS += -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/avr/libraries/Wire
CXXFLAGS += -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/avr/libraries/SoftwareSerial
CXXFLAGS += -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/avr/libraries/EEPROM
CXXFLAGS += -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/avr/libraries/Servo
CXXFLAGS += -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/avr/libraries/Stepper
CXXFLAGS += -I.

ALLDEPEND = $(addsuffix .d,$(MODULES))
EXISTDEPEND = $(shell find . -name \*.d -type f -print)

all: $(addsuffix .o,$(MODULES))

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(addsuffix .o,$(MODULES))
	rm -f $(addsuffix .d,$(MODULES))

ifeq ($(findstring clean,$(MAKECMDGOALS)),)
ifneq ($(EXISTDEPEND),)
-include $(EXISTDEPEND)
endif
endif
	