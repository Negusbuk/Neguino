/****************************************************************************
 **
 **  Copyright (C) 2013, 2014 Andreas Mussgiller
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

#ifndef Neguino_NSPIEEPROM25AA_H
#define Neguino_NSPIEEPROM25AA_H

#include <Arduino.h>
#include <SPI.h>

#include <NSPIEEPROM.h>

/*! \file NSPIEEPROM25AA.h
*/

/*! \namespace Neguino
    \brief Namespace encapsulating all classes and functions.
*/
namespace Neguino {

  //! class for 25AA type SPI eeprom chips
  /*!
   */
  class NSPIEEPROM25AA : public NSPIEEPROM
  {
  public:

    //! the operation codes
    /*!
     */
    enum OPCODES {
      WREN  = 0x6, //!< enable write
      WRDI  = 0x4, //!< disable write
      RDSR  = 0x5, //!< read status register
      WRSR  = 0x1, //!< write status register
      READ  = 0x3, //!< read
      WRITE = 0x2  //!< write
    };

    //! constructor taking the NSPIChipSelect object, size and pagesize, and a delay as arguments
    NSPIEEPROM25AA(const NSPIChipSelect& _cs, uint32_t _size, uint16_t _pagesize,
                   uint8_t _delay);

    //! write to the eeprom
    virtual void write(uint32_t address, uint8_t* buffer, uint16_t n);

    //! read from the eeprom
    virtual void read(uint32_t address, uint8_t* buffer, uint16_t n);

    //! initialize the eeprom
    virtual void init();

  protected:

    //! write to the eeprom after alignment
    void writeAligned(uint32_t address, uint8_t* buffer, uint16_t n);

    uint8_t delay_; //!< the delay
  };

  //! class for a 25AA128k type SPI eeprom chips
  /*!
   */
  class NSPIEEPROM25AA128k : public NSPIEEPROM25AA
  {
  public:

    //! constructor taking the NSPIChipSelect object and a delay as arguments
    NSPIEEPROM25AA128k(const NSPIChipSelect& _cs, uint8_t _delay);
  };

}

#endif // Neguino_NSPIEEPROM25AA_H
