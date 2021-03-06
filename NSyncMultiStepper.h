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

#ifndef Neguino_NSYNCMULTISTEPPER_H
#define Neguino_NSYNCMULTISTEPPER_H

#include <Arduino.h>

#include <NTools.h>
#include <NMultiStepper.h>

/*! \file NSyncMultiStepper.h
*/

/*! \namespace Neguino
    \brief Namespace encapsulating all classes and functions.
*/
namespace Neguino {

  //! a class for stepping multiple stepper motors synchronously
  /*!
   */
  class NSyncMultiStepper : public NMultiStepper
  {
  public:

    //! default constructor
    NSyncMultiStepper();

    //! start stepping for all managed stepper motors
    virtual void execute();
  };
  
}

#endif // Neguino_NSYNCMULTISTEPPER_H
