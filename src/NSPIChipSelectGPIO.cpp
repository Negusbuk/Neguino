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

#include <SPI.h>

#include <NSPIChipSelectGPIO.h>

namespace Neguino {

  NSPIChipSelectGPIO::NSPIChipSelectGPIO(uint8_t _cs, uint8_t /*_ioaddress*/, uint8_t /*_scs*/)
  : cs_(_cs) {

  }

  void NSPIChipSelectGPIO::selectChip() const {

    // take the CS pin low to select the chip
    digitalWrite(cs_, LOW);
  }

  void NSPIChipSelectGPIO::deselectChip() const {

    // take the CS pin high to deselect the chip
     digitalWrite(cs_, HIGH);
  }

  void NSPIChipSelectGPIO::init() {

    // set the CS pin mode to output
    pinMode(cs_, OUTPUT);
    // take the CS pin high to deselect the chip
    digitalWrite(cs_, HIGH);
  }

}
