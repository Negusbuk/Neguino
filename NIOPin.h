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

#ifndef Neguino_NIOPIN_H
#define Neguino_NIOPIN_H

#include <Arduino.h>

/** \file
    NIOPin header file. */

namespace Neguino {

  class NIOPin
  {
  public:
    NIOPin() { }

    virtual void setMode(uint8_t mode) = 0;
    virtual void write(uint8_t data) = 0;
    virtual uint8_t read() = 0;
  };
  
}

#endif
