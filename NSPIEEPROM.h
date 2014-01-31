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

#ifndef Neguino_NSPIEEPROM_H
#define Neguino_NSPIEEPROM_H

#include <Arduino.h>

#include <NEEPROM.h>
#include <NSPIDevice.h>

/*! \file NSPIEEPROM.h
*/

/*! \namespace Neguino
    \brief Namespace encapsulating all classes and functions.
*/
namespace Neguino {

  //! pure virtual class for SPI eeprom chips
  /*!
   */
  class NSPIEEPROM : public NEEPROM, public NSPIDevice
  {
  public:

    //! constructor taking the NSPIChipSelect object, size and pagesize as arguments
    NSPIEEPROM(const NSPIChipSelect& _cs, uint32_t _size, uint16_t _pagesize);

    //! write to the eeprom
    virtual void write(uint32_t address, uint8_t* buffer, uint16_t n) = 0;

    //! read from the eeprom
    virtual void read(uint32_t address, uint8_t* buffer, uint16_t n) = 0;

    //! initialize the eeprom
    virtual void init() = 0;
  };
  
}

#endif // Neguino_NSPIEEPROM_H
