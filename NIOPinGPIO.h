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

#ifndef Neguino_NIOPINGPIO_H
#define Neguino_NIOPINGPIO_H

#include <Arduino.h>

#include <NIOPin.h>

/** \file
    NIOPinGPIO header file. */

namespace Neguino {

  class NIOPinGPIO : public NIOPin
  {
  public:
    NIOPinGPIO(uint8_t _pin);

    virtual void setMode(uint8_t mode);
    virtual void write(uint8_t data);
    virtual uint8_t read();

  protected:

    uint8_t pin_;
  };
  
}

#endif
