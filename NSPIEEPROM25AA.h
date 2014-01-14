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

/** \file
    NEEPROM25AA header file. */

namespace Neguino {

  class NSPIEEPROM25AA : public NSPIEEPROM
  {
  public:

    enum OPCODES {
      WREN  = 0x6,
      WRDI  = 0x4,
      RDSR  = 0x5,
      WRSR  = 0x1,
      READ  = 0x3,
      WRITE = 0x2
    };

    NSPIEEPROM25AA(const NSPIChipSelect& _cs, uint32_t _size, uint16_t _pagesize,
                   uint8_t _delay);

    void write(uint32_t address, uint8_t* buffer, uint16_t n);
    void read(uint32_t address, uint8_t* buffer, uint16_t n);
    void init();

  protected:

    void writeAligned(uint32_t address, uint8_t* buffer, uint16_t n);

    uint8_t delay_;
  };

}

#endif // Neguino_NSPIEEPROM25AA_H
