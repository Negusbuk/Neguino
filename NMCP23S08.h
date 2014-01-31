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

/*! \file NMCP23S08.h
*/

/*! \namespace Neguino
    \brief Namespace encapsulating all classes and functions.
*/
namespace Neguino {

  class NMCP23S08;

  //! class for a single pin the the MCP23S08 8 port io expansion chip
  /*!
   */
  class NMCP23S08Pin : public NIOPin
  {
    friend class NMCP23S08;

  public:

    //! set the mode of the IO pin.
    virtual void setMode(uint8_t mode);

    //! write data to the pin
    virtual void write(uint8_t data);

    //! read data from the pin
    virtual uint8_t read();

  protected:

    //! constructor taking a pointer to the mother NMCP23S08 chip and the pin number as argument
    NMCP23S08Pin(NMCP23S08* _mcp, uint8_t _pin);

    NMCP23S08* mcp_; //!< pointer to the mother NMCP23S08 chip
    uint8_t pin_;    //!< the pin number
  };

  //! class for the MCP23S08 8 port io expansion chip
  /*!
   */
  class NMCP23S08 : public NSPIDevice
  {
  public:

    //! the SPI commands
    /*!
     */
    enum COMMAND {
      WRITE_CMD = 0x0, //!< write command
      READ_CMD  = 0x1  //!< read command
    };

    //! the IO direction of a pin
    /*!
     */
    enum IODIRECTION {
      IOOUTPUT    = 0x00, //!< output direction
      IOINPUT     = 0xFF  //!< input direction
    };

    //! the GPIO pins of the chip
    /*!
     */
    enum GPIOPIN {
      GPIO0 =    0, //!< GPIO pin 0
      GPIO1 =    1, //!< GPIO pin 1
      GPIO2 =    2, //!< GPIO pin 2
      GPIO3 =    3, //!< GPIO pin 3
      GPIO4 =    4, //!< GPIO pin 4
      GPIO5 =    5, //!< GPIO pin 5
      GPIO6 =    6, //!< GPIO pin 6
      GPIO7 =    7  //!< GPIO pin 7
    };

    //! the registers of the chip
    /*!
     */
    enum REGISTER {
      IODIR      = 0x00, //!< I/O direction
      IPOL       = 0x01, //!< I/O polarity
      GPINTEN    = 0x02, //!< interupt enable
      DEFVAL     = 0x03, //!< register default value (interupts)
      INTCON     = 0x04, //!< interupt control
      IOCON      = 0x05, //!< I/O config (also 0x0B)
      GPPU       = 0x06, //!< port pullups
      INTF       = 0x07, //!< interupt flag (where the interupt came from)
      INTCAP     = 0x08, //!< interupt capture (value at interupt is saved here)
      GPIO       = 0x09, //!< io port
      OLAT       = 0x0A  //!< output latch
    };

    //! the bits of the control register
    /*!
     */
    enum IO {
      SEQOP_OFF       = 0x20, //!< incrementing address pointer off
      DISSLW_ON       = 0x10, //!< slew rate on
      HAEN_ON         = 0x08, //!< hardware addressing on
      ODR_ON          = 0x04, //!< open drain for interupts on
      INTPOL_HIGH     = 0x02  //!< interupt polarity high
    };

    //! constructor taking a NSPIChipSelect object and the address of the chip as arguments
    explicit NMCP23S08(const NSPIChipSelect& _cs, uint8_t _address);

    //! destructor
    virtual ~NMCP23S08() { }

    //! read from a register
    virtual uint8_t readRegister(uint8_t reg);

    //! write to a register
    virtual void writeRegister(uint8_t reg, uint8_t data);

    //! read a certain bit of a register
    virtual uint8_t readBit(uint8_t bit, uint8_t reg);

    //! write to a certain bit of a register
    virtual void writeBit(uint8_t bit, uint8_t reg, uint8_t data);

    //! initialize
    virtual void init();

    //! returns a pointer to a NMCP23S08Pin object for a certain pin
    NMCP23S08Pin* getPin(uint8_t pin);

  protected:

    //! returns the SPI control byte
    uint8_t getSPIControlByte(COMMAND cmd);

    uint8_t address_;       //!< the address of the chip on the SPI bus
    NMCP23S08Pin* pins_[8]; //!< array of pointers to the NMCP23S08Pin objects
  };

};

#endif // Neguino_NMCP23S08_H
