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

#include <NIOPinGPIO.h>

namespace Neguino {

  NIOPinGPIO::NIOPinGPIO(uint8_t _pin)
  : pin_(_pin)
  {

  }

  void NIOPinGPIO::setMode(uint8_t mode)
  {
    pinMode(pin_, mode);
  }

  void NIOPinGPIO::write(uint8_t data)
  {
    digitalWrite(pin_, data);
  }

  uint8_t NIOPinGPIO::read()
  {
    return digitalRead(pin_);
  }

}
