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

#ifndef Neguino_NSTEPPER_H
#define Neguino_NSTEPPER_H

#include <Arduino.h>

#include <NIOPin.h>

/** \file
    NStepper header file. */

namespace Neguino {

  class NStepper
  {
  public:

    NStepper(uint16_t _stepsPerTurn,
             NIOPin* _pin1, NIOPin* _pin2);
    NStepper(uint16_t _stepsPerTurn,
             NIOPin* _pin1, NIOPin* _pin2,
             NIOPin* _pin3, NIOPin* _pin4);

    uint16_t getNumberOfStepsPerTurn() const { return numberOfStepsPerTurn_; }

    uint8_t getSpeed() const { return speed_; }
    void setSpeed(uint8_t speed);

    unsigned int getStepDelay() const { return stepDelay_; }
    void setStepDelay(unsigned int delay);

    // mover method
    void step(int steps);
    void singleStep(int direction);

  protected:

    void stepMotor(uint8_t this_step);

    NIOPin* pin1_;
    NIOPin* pin2_;
    NIOPin* pin3_;
    NIOPin* pin4_;
    uint8_t numberOfPins_;

    uint16_t numberOfStepsPerTurn_;
    char direction_;
    unsigned int speed_;
    unsigned int stepDelay_;

    uint16_t stepNumber_;

    unsigned long lastTime_;
  };
  
}

#endif
