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

#include <NStepper.h>

namespace Neguino {

  NStepper::NStepper(uint8_t _stepsPerTurn, NIOPin& _pin1, NIOPin& _pin2)
  :numberOfStepsPerTurn_(_stepsPerTurn),
   pin1_(&_pin1),
   pin2_(&_pin2),
   numberOfPins_(2)
  {

  }

  NStepper::NStepper(uint8_t _stepsPerTurn,
                     NIOPin& _pin1, NIOPin& _pin2,
                     NIOPin& _pin3, NIOPin& _pin4)
  :numberOfStepsPerTurn_(_stepsPerTurn),
   pin1_(&_pin1),
   pin2_(&_pin2),
   pin3_(&_pin3),
   pin4_(&_pin4),
   numberOfPins_(4)
  {

  }

}
