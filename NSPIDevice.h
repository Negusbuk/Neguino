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

#ifndef Neguino_NSPIDEVICE_H
#define Neguino_NSPIDEVICE_H

#include <Arduino.h>

#include <NSPIChipSelect.h>

/** \file
    NSPIChipSelect header file. */

namespace Neguino {

  class NSPIDevice
  {
  public:
    NSPIDevice(const NSPIChipSelect& _cs);

    virtual void init() = 0;
    void selectChip();
    void deselectChip();

  protected:

    NSPIChipSelect cs_;
  };
  
}

#endif
