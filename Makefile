HEADERS = NTools.h \
		  NIOPin.h \
		  NIOPinGPIO.h \
		  NSPIChipSelect.h \
		  NSPIChipSelectGPIO.h \
		  NSPIDevice.h \
		  NMCP23S17.h \
		  NMCP23S08.h \
		  NStepper.h \
		  NMultiStepper.h

MODULES	= NIOPinGPIO \
		  NSPIChipSelect \
		  NSPIChipSelectGPIO \
		  NSPIDevice \
		  NMCP23S17 \
		  NMCP23S08 \
		  NStepper \
		  NMultiStepper
		  
MACHINE:= $(shell uname -m)
SYSTEM:= $(shell uname -s)

CXXFLAGS  = -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections
CXXFLAGS += -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=151

ifeq "$(MACHINE)" "armv6l"
ARDUINOBASE = /usr/share/arduino
CXX       = avr-g++
CXXFLAGS += -I$(ARDUINOBASE)/hardware/arduino/cores/arduino
CXXFLAGS += -I$(ARDUINOBASE)/hardware/arduino/variants/standard
CXXFLAGS += -I$(ARDUINOBASE)/libraries/SPI
CXXFLAGS += -I$(ARDUINOBASE)/libraries/Wire
CXXFLAGS += -I$(ARDUINOBASE)/libraries/SoftwareSerial
CXXFLAGS += -I$(ARDUINOBASE)/libraries/EEPROM
CXXFLAGS += -I$(ARDUINOBASE)/libraries/Servo
#CXXFLAGS += -I$(ARDUINOBASE)/libraries/Stepper
CXXFLAGS += -I.
endif

ifeq "$(SYSTEM)" "Darwin"
ARDUINOBASE = /Applications/Arduino.app/Contents/Resources/Java/hardware
CXX       = $(ARDUINOBASE)/tools/avr/bin/avr-g++
CXXFLAGS += -I$(ARDUINOBASE)/arduino/avr/cores/arduino
CXXFLAGS += -I$(ARDUINOBASE)/arduino/avr/variants/standard
CXXFLAGS += -I$(ARDUINOBASE)/arduino/avr/libraries/SPI
CXXFLAGS += -I$(ARDUINOBASE)/arduino/avr/libraries/Wire
CXXFLAGS += -I$(ARDUINOBASE)/arduino/avr/libraries/SoftwareSerial
CXXFLAGS += -I$(ARDUINOBASE)/arduino/avr/libraries/EEPROM
CXXFLAGS += -I$(ARDUINOBASE)/arduino/avr/libraries/Servo
#CXXFLAGS += -I$(ARDUINOBASE)/arduino/avr/libraries/Stepper
CXXFLAGS += -I.
endif

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

