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

#ifndef Neguino_NEEPROM_H
#define Neguino_NEEPROM_H

#include <Arduino.h>

/*! \file NEEPROM.h
*/

/*! \namespace Neguino
    \brief Namespace encapsulating all classes and functions.
*/
namespace Neguino {

  //! pure virtual class for eeprom chips
  /*!
   */
  class NEEPROM
  {
  public:

    //! constructor taking the size and pagesize as arguments
    NEEPROM(uint32_t _size, uint16_t _pagesize);

    //! returns the size of the eeprom
    uint32_t getSize() const { return size_; }

    //! returns the pagesize of the eeprom
    uint32_t getPagesize() const { return pagesize_; }

    //! write to the eeprom
    virtual void write(uint32_t address, uint8_t* buffer, uint16_t n) = 0;

    //! read from the eeprom
    virtual void read(uint32_t address, uint8_t* buffer, uint16_t n) = 0;

    //! initialize the eeprom
    virtual void init() = 0;

  protected:

    uint32_t size_;     //!< the size of the eeprom
    uint16_t pagesize_; //!< the pagesize of the eeprom
  };
  
}

#endif // Neguino_NEEPROM_H
