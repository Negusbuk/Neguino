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

/*! \file NIOPin.h
*/

/*! \namespace Neguino
    \brief Namespace encapsulating all classes and functions.
*/
namespace Neguino {

  //! pure virtual class for a generic IO pin
  /*!
   */
  class NIOPin
  {
  public:

    //! the IO direction of the pin
    /*!
     */
    enum IODIRECTION {
      IOOUTPUT    = 0x00, //!< output direction
      IOINPUT     = 0xFF  //!< input direction
    };

    //! default constructor
    NIOPin() { }

    //! set the mode of the IO pin.
    virtual void setMode(uint8_t mode) = 0;

    //! write data to the pin
    virtual void write(uint8_t data) = 0;

    //! read data from the pin
    virtual uint8_t read() = 0;
  };
  
}

#endif
