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

#include <NSPIChipSelectGPIO.h>

namespace Neguino {

  NSPIChipSelect::NSPIChipSelect(NIOPin* _ioPin)
  : ioPin_(_ioPin)
  {

  }

  void NSPIChipSelect::selectChip()
  {
    // take the CS pin low to select the chip
    ioPin_->write(LOW);
  }

  void NSPIChipSelect::deselectChip()
  {
    // take the CS pin high to deselect the chip
     ioPin_->write(HIGH);
  }

  void NSPIChipSelect::init()
  {
    // set the CS pin mode to output
    ioPin_->setMode(OUTPUT);
    // take the CS pin high to deselect the chip
    ioPin_->write(HIGH);
  }

}
