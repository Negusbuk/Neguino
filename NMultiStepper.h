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

#ifndef Neguino_NMULTISTEPPER_H
#define Neguino_NMULTISTEPPER_H

#include <Arduino.h>

#include <NTools.h>
#include <NStepper.h>

/*! \file NMultiStepper.h
*/

/*! \namespace Neguino
    \brief Namespace encapsulating all classes and functions.
*/
namespace Neguino {

  //! a class for stepping multiple stepper motors at the same time
  /*!
   */
  class NMultiStepper
  {
  public:

    //! default constructor
    NMultiStepper();

    //! add stepper motor
    virtual void addStepper(NStepper* stepper);

    //! schedule steps to stepper motor at index idx
    void step(uint8_t idx, int steps);

    //! start stepping for all managed stepper motors
    virtual void execute();

  protected:

    Neguino::NVector<NStepper*> steppers_; //!< vector of NStepper objects
    Neguino::NVector<int> steps_;          //!< vector of steps to be executed
  };
  
}

#endif // Neguino_NMULTISTEPPER_H
