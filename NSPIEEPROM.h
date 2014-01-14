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

/** \file
    NSPIEEPROM header file. */

namespace Neguino {

  class NSPIEEPROM : public NEEPROM, public NSPIDevice
  {
  public:
    NSPIEEPROM(const NSPIChipSelect& _cs, uint32_t _size, uint16_t _pagesize);

    virtual void write(uint32_t address, uint8_t* buffer, uint16_t n) = 0;
    virtual void read(uint32_t address, uint8_t* buffer, uint16_t n) = 0;
    virtual void init() = 0;
  };
  
}

#endif // Neguino_NSPIEEPROM_H
