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

/** \file
    NMultiStepper header file. */

namespace Neguino {

  class NMultiStepper
  {
  public:

    NMultiStepper();

    virtual void addStepper(NStepper* stepper);

    void step(uint8_t idx, int steps);
    virtual void execute();

  protected:

    Neguino::Vector<NStepper*> steppers_;
    Neguino::Vector<int> steps_;
  };
  
}

#endif // Neguino_NMULTISTEPPER_H
