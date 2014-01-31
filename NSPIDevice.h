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

/*! \file NSPIDevice.h
*/

/*! \namespace Neguino
    \brief Namespace encapsulating all classes and functions.
*/
namespace Neguino {

  //! pure virtual class for a generic SPI device
  /*!
   */
  class NSPIDevice
  {
  public:

    //! constructor taking a NSPIChipSelect object as argument
    NSPIDevice(const NSPIChipSelect& _cs);

    //! initialize the device
    virtual void init() = 0;

    //! select the chip
    void selectChip();

    //! deselect the chip
    void deselectChip();

  protected:

    NSPIChipSelect cs_; //!< the NSPIChipSelect object associated to this SPI device
  };
  
}

#endif
