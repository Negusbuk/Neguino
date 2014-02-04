/****************************************************************************
 **
 **  Copyright (C) 2013, 2014 Andreas Mussgiller
 **
 **  based on libmcp23s17 by Thomas Preston
 **           http://github.com/piface/libmcp23s17
 **
 **  Datasheet: http://ww1.microchip.com/downloads/en/devicedoc/21952b.pdf
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

#ifndef Neguino_NMCP23S17_H
#define Neguino_NMCP23S17_H

#include <NIOPin.h>
#include <NSPIDevice.h>

/*! \file NMCP23S17.h
*/

/*! \namespace Neguino
    \brief Namespace encapsulating all classes and functions.
*/
namespace Neguino {

  class NMCP23S17;

  //! class for a single pin the the MCP23S17 16 port io expansion chip
  /*!
   */
  class NMCP23S17Pin : public NIOPin
  {
    friend class NMCP23S17;

  public:

    //! set the mode of the IO pin.
    virtual void setMode(uint8_t mode);

    //! write data to the pin
    virtual void write(uint8_t data);

    //! read data from the pin
    virtual uint8_t read();

  protected:

    //! constructor taking a pointer to the mother NMCP23S17 chip and the pin number as argument
    NMCP23S17Pin(NMCP23S17* _mcp, uint8_t _pin);

    NMCP23S17* mcp_; //!< pointer to the mother NMCP23S17 chip
    uint8_t pin_;    //!< the pin number
  };


  //! class for the MCP23S17 16 port io expansion chip
  /*!
   */
  class NMCP23S17 : public NSPIDevice
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
      GPIOA0 =    0, //!< GPIO pin A0
      GPIOA1 =    1, //!< GPIO pin A1
      GPIOA2 =    2, //!< GPIO pin A2
      GPIOA3 =    3, //!< GPIO pin A3
      GPIOA4 =    4, //!< GPIO pin A4
      GPIOA5 =    5, //!< GPIO pin A5
      GPIOA6 =    6, //!< GPIO pin A6
      GPIOA7 =    7, //!< GPIO pin A7
      GPIOB0 =    0, //!< GPIO pin B0
      GPIOB1 =    1, //!< GPIO pin B1
      GPIOB2 =    2, //!< GPIO pin B2
      GPIOB3 =    3, //!< GPIO pin B3
      GPIOB4 =    4, //!< GPIO pin B4
      GPIOB5 =    5, //!< GPIO pin B5
      GPIOB6 =    6, //!< GPIO pin B6
      GPIOB7 =    7  //!< GPIO pin B7
    };

    //! the registers of the chip
    /*!
     */
    enum REGISTER {
      IODIRA     = 0x00, //!< I/O direction A
      IODIRB     = 0x01, //!< I/O direction B
      IPOLA      = 0x02, //!< I/O polarity A
      IPOLB      = 0x03, //!< I/O polarity B
      GPINTENA   = 0x04, //!< interupt enable A
      GPINTENB   = 0x05, //!< interupt enable B
      DEFVALA    = 0x06, //!< register default value A (interupts)
      DEFVALB    = 0x07, //!< register default value B (interupts)
      INTCONA    = 0x08, //!< interupt control A
      INTCONB    = 0x09, //!< interupt control B
      IOCON      = 0x0A, //!< I/O config (also 0x0B)
      GPPUA      = 0x0C, //!< port A pullups
      GPPUB      = 0x0D, //!< port B pullups
      INTFA      = 0x0E, //!< interupt flag A (where the interupt came from)
      INTFB      = 0x0F, //!< interupt flag B
      INTCAPA    = 0x10, //!< interupt capture A (value at interupt is saved here)
      INTCAPB    = 0x11, //!< interupt capture B
      GPIOA      = 0x12, //!< port A
      GPIOB      = 0x13, //!< port B
      OLATA      = 0x14, //!< output latch A
      OLATB      = 0x15  //!< output latch B
    };

    //! the bits of the control register
    /*!
     */
    enum IO {
      BANK_ON         = 0x80, //!< addressing mode on
      INT_MIRROR_ON   = 0x40, //!< interupt mirror (INTa|INTb) on
      SEQOP_OFF       = 0x20, //!< incrementing address pointer off
      DISSLW_ON       = 0x10, //!< slew rate on
      HAEN_ON         = 0x08, //!< hardware addressing on
      ODR_ON          = 0x04, //!< open drain for interupts on
      INTPOL_HIGH     = 0x02  //!< interupt polarity high
    };

    //! constructor taking a NSPIChipSelect object and the address of the chip as arguments
    explicit NMCP23S17(const NSPIChipSelect& _cs, uint8_t _address);

    //! destructor
    virtual ~NMCP23S17() { }

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

    //! returns a pointer to a NMCP23S17Pin object for a certain pin
    NMCP23S17Pin* getPin(uint8_t pin);

  protected:

    //! returns the SPI control byte
    uint8_t getSPIControlByte(COMMAND cmd);

    uint8_t address_;        //!< the address of the chip on the SPI bus
    NMCP23S17Pin* pins_[16]; //!< array of pointers to the NMCP23S17Pin objects
  };

};

#endif // Neguino_NMCP23S17_H
