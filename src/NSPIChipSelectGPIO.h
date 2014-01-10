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

#ifndef NSPICHIPSELECTGPIO_H
#define NSPICHIPSELECTGPIO_H

#include <Arduino.h>

#include <NSPIChipSelect.h>

/** \file
    NSPIChipSelectGPIO header file. */

namespace Neguino {

  class NSPIChipSelectGPIO : public NSPIChipSelect
  {
  public:
    NSPIChipSelectGPIO(uint8_t _cs, uint8_t _ioaddress, uint8_t _gpio);

    virtual void selectChip() const;
    virtual void deselectChip() const ;
    virtual void init();

  protected:

    uint8_t cs_;
  };
  
}

#endif
