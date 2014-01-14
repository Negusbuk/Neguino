/****************************************************************************
 **
 **  Copyright (C) 2013, 2014 Andreas Mussgiller
 **
 **  based on libmcp23s17 by Thomas Preston
 **           http://github.com/piface/libmcp23s17
 **
 **  Datasheet: http://ww1.microchip.com/downloads/en/DeviceDoc/21919e.pdf
 **
 **  This program is free software: you can redistribute it and/or modify
 **  it under the terms of the GNU General Public License as published by
 **  the Free Software Foundation, either version 3 of the License, or
 **  (at your option) any later version.
 **
 **  This program is distributed in the hope that it will be useful,
 **  but WITHOUT ANY WARRANTY; without even the implied warranty of
 **  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **  GNU General Public License for more details.
 **
 **  You should have received a copy of the GNU General Public License
 **  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **
 **
 ****************************************************************************/

#ifndef Neguino_NMCP23S08_H
#define Neguino_NMCP23S08_H

#include <NIOPin.h>
#include <NSPIDevice.h>

namespace Neguino {

  class NMCP23S08;

  class NMCP23S08Pin : public NIOPin
  {
    friend class NMCP23S08;

  public:

    virtual void setMode(uint8_t mode);
    virtual void write(uint8_t data);
    virtual uint8_t read();

  protected:

    NMCP23S08Pin(NMCP23S08* _mcp, uint8_t _pin);

    NMCP23S08* mcp_;
    uint8_t pin_;
  };

  class NMCP23S08 : public NSPIDevice
  {
  public:

    enum COMMAND {
      WRITE_CMD = 0x0,
      READ_CMD  = 0x1
    };

    enum IODIRECTION {
      IOOUTPUT    = 0x00,
      IOINPUT     = 0xFF
    };

    enum GPIOPIN {
      GPIO0 =    0,
      GPIO1 =    1,
      GPIO2 =    2,
      GPIO3 =    3,
      GPIO4 =    4,
      GPIO5 =    5,
      GPIO6 =    6,
      GPIO7 =    7
    };

    enum REGISTER {
      IODIR      = 0x00,  // I/O direction
      IPOL       = 0x01,  // I/O polarity
      GPINTEN    = 0x02,  // interupt enable
      DEFVAL     = 0x03,  // register default value (interupts)
      INTCON     = 0x04,  // interupt control
      IOCON      = 0x05,  // I/O config (also 0x0B)
      GPPU       = 0x06,  // port pullups
      INTF       = 0x07,  // interupt flag (where the interupt came from)
      INTCAP     = 0x08,  // interupt capture (value at interupt is saved here)
      GPIO       = 0x09,  // io port
      OLAT       = 0x0A,  // output latch
      NREGISTERS
    };

    enum IO {
      SEQOP_OFF       = 0x20,  // incrementing address pointer
      SEQOP_ON        = 0x00,
      DISSLW_ON       = 0x10,  // slew rate
      DISSLW_OFF      = 0x00,
      HAEN_ON         = 0x08,  // hardware addressing
      HAEN_OFF        = 0x00,
      ODR_ON          = 0x04,  // open drain for interupts
      ODR_OFF         = 0x00,
      INTPOL_HIGH     = 0x02,  // interupt polarity
      INTPOL_LOW      = 0x00
    };

    explicit NMCP23S08(const NSPIChipSelect& _cs, uint8_t _address);
    virtual ~NMCP23S08() { }

    virtual uint8_t readRegister(uint8_t reg);
    virtual void writeRegister(uint8_t reg, uint8_t data);

    virtual uint8_t readBit(uint8_t bit, uint8_t reg);
    virtual void writeBit(uint8_t bit, uint8_t reg, uint8_t data);

    virtual void init();

    NMCP23S08Pin* getPin(uint8_t pin);

  protected:

    uint8_t getSPIControlByte(COMMAND cmd);

    uint8_t address_;

    NMCP23S08Pin* pins_[8];
  };

};

#endif // Neguino_NMCP23S08_H
