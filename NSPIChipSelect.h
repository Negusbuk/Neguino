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

#ifndef Neguino_NSPICHIPSELECT_H
#define Neguino_NSPICHIPSELECT_H

#include <Arduino.h>

#include <NIOPin.h>

/*! \file NSPIChipSelect.h
*/

/*! \namespace Neguino
    \brief Namespace encapsulating all classes and functions.
*/
namespace Neguino {

  //! class for selecting SPI devices
  /*!
   */
  class NSPIChipSelect
  {
  public:

    //! constructor taking a NIOPin object as argument
    NSPIChipSelect(NIOPin* _ioPin);

    //! select the chip
    virtual void selectChip();

    //! select the chip
    virtual void deselectChip();

    //! initialize
    virtual void init();

  protected:

    NIOPin* ioPin_; //!< the NIOPin object associated to this object
  };
  
}

#endif
