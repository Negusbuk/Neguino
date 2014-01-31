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

#ifndef Neguino_NSPICHIPSELECTGPIO_H
#define Neguino_NSPICHIPSELECTGPIO_H

#include <Arduino.h>

#include <NIOPinGPIO.h>
#include <NSPIChipSelect.h>

/*! \file NSPIChipSelectGPIO.h
*/

/*! \namespace Neguino
    \brief Namespace encapsulating all classes and functions.
*/
namespace Neguino {

  //! class for selecting SPI devices via one of the Arduino GPIO pins
  /*!
   */
  class NSPIChipSelectGPIO : public NSPIChipSelect
  {
  public:

    //! the constructor taking the pin number as an argument
    explicit NSPIChipSelectGPIO(uint8_t _gpio);

    //! the constructor taking a NIOPinGPIO object as argument
    explicit NSPIChipSelectGPIO(NIOPinGPIO* _gpio);
  };
  
}

#endif
