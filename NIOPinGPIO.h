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

/*! \file NIOPinGPIO.h
*/

/*! \namespace Neguino
    \brief Namespace encapsulating all classes and functions.
*/
namespace Neguino {

  //! class for one IO pin of the Arduino GPIOs
  /*!
   */
  class NIOPinGPIO : public NIOPin
  {
  public:

    //! the constructor taking the pin number as an argument
    NIOPinGPIO(uint8_t _pin);

    //! set the mode of the IO pin.
    virtual void setMode(uint8_t mode);

    //! write data to the pin
    virtual void write(uint8_t data);

    //! read data from the pin
    virtual uint8_t read();

  protected:

    uint8_t pin_; //!< the pin number of the Arduino GPIO
  };
  
}

#endif
