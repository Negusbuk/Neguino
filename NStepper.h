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

/*! \file NStepper.h
*/

/*! \namespace Neguino
    \brief Namespace encapsulating all classes and functions.
*/
namespace Neguino {

  //! a stepper motor class
  /*!
   */
  class NStepper
  {
  public:

    //! constructor taking the number of turns and pointers to two NIOPin objects as arguments
    NStepper(uint16_t _stepsPerTurn,
             NIOPin* _pin1, NIOPin* _pin2);

    //! constructor taking the number of turns and pointers to four NIOPin objects as arguments
    NStepper(uint16_t _stepsPerTurn,
             NIOPin* _pin1, NIOPin* _pin2,
             NIOPin* _pin3, NIOPin* _pin4);

    //! returns the number of steps per turn for this stepper
    uint16_t getNumberOfStepsPerTurn() const { return numberOfStepsPerTurn_; }

    //! returns the speed
    uint8_t getSpeed() const { return speed_; }

    //! set the speed
    void setSpeed(uint8_t speed);

    //! returns the delay between steps
    unsigned int getStepDelay() const { return stepDelay_; }

    //! set the delay between steps
    void setStepDelay(unsigned int delay);

    //! method that lets the motor do a certain amount of steps
    void step(int steps);

    //! method that lets the motor do a single step
    void singleStep(int direction);

  protected:

    //! the actual method responsible for stepping the motor
    void stepMotor(uint8_t this_step);

    NIOPin* pin1_;         //!< NIOPin 1
    NIOPin* pin2_;         //!< NIOPin 2
    NIOPin* pin3_;         //!< NIOPin 3
    NIOPin* pin4_;         //!< NIOPin 4
    uint8_t numberOfPins_; //!< number of pins this stepper uses

    uint16_t numberOfStepsPerTurn_; //!< number of steps this motor needs per turn
    char direction_;                //!< the stepping direction
    unsigned int speed_;            //!< the speed
    unsigned int stepDelay_;        //!< the delay between steps

    uint16_t stepNumber_;           //!< current position in the step sequence

    unsigned long lastTime_;        //!< last system time
  };
  
}

#endif
