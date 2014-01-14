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

  NStepper::NStepper(uint16_t _stepsPerTurn, NIOPin* _pin1, NIOPin* _pin2)
  :pin1_(_pin1),
   pin2_(_pin2),
   pin3_(0),
   pin4_(0),
   numberOfPins_(2),
   numberOfStepsPerTurn_(_stepsPerTurn),
   direction_(0),
   stepNumber_(0),
   lastTime_(0)
  {
    pin1_->setMode(NIOPin::IOOUTPUT);
    pin2_->setMode(NIOPin::IOOUTPUT);

    setSpeed(1);
  }

  NStepper::NStepper(uint16_t _stepsPerTurn,
                     NIOPin* _pin1, NIOPin* _pin2,
                     NIOPin* _pin3, NIOPin* _pin4)
  :pin1_(_pin1),
   pin2_(_pin2),
   pin3_(_pin3),
   pin4_(_pin4),
   numberOfPins_(4),
   numberOfStepsPerTurn_(_stepsPerTurn),
   direction_(0),
   stepNumber_(0),
   lastTime_(0)
  {
    pin1_->setMode(NIOPin::IOOUTPUT);
    pin2_->setMode(NIOPin::IOOUTPUT);
    pin3_->setMode(NIOPin::IOOUTPUT);
    pin4_->setMode(NIOPin::IOOUTPUT);

    setSpeed(1);
  }

  void NStepper::setSpeed(uint8_t speed)
  {
    speed_ = speed;
    stepDelay_ = 60 * 1000 / numberOfStepsPerTurn_ / speed_;
  }

  void NStepper::setStepDelay(unsigned int delay)
  {
    stepDelay_ = delay;
    speed_ = 60 * 1000 / numberOfStepsPerTurn_ / stepDelay_;
  }

  /*
    Moves the motor steps_to_move steps.  If the number is negative,
     the motor moves in the reverse direction.
   */
  void NStepper::step(int stepsToMove)
  {
    if (stepsToMove==0) return;

    unsigned long time;
    int steps_left = abs(stepsToMove);  // how many steps to take

    // determine direction based on whether steps_to_mode is + or -:
    if (stepsToMove > 0) direction_ = 1;
    if (stepsToMove < 0) direction_ = 0;

    // decrement the number of steps, moving one step each time:
    while (steps_left > 0) {

      time = millis();

      // move only if the appropriate delay has passed:
      if (time - lastTime_ >= stepDelay_) {

        // get the timeStamp of when you stepped:
        lastTime_ = time;

        if (direction_==1) {
          stepNumber_++;
          if (stepNumber_ == numberOfStepsPerTurn_) {
            stepNumber_ = 0;
          }
        } else {
          if (stepNumber_==0) {
            stepNumber_ = numberOfStepsPerTurn_;
          }
          stepNumber_--;
        }

        // decrement the steps left:
        steps_left--;

        // step the motor to step number 0, 1, 2, or 3:
        stepMotor(stepNumber_ % 4);
      }
    }
  }

  void NStepper::singleStep(int direction)
  {
    if (direction==0) return;
    if (direction > 0) direction_ = 1;
    if (direction < 0) direction_ = 0;

    if (direction_==1) {
      stepNumber_++;
      if (stepNumber_ == numberOfStepsPerTurn_) {
        stepNumber_ = 0;
      }
    } else {
      if (stepNumber_==0) {
        stepNumber_ = numberOfStepsPerTurn_;
      }
      stepNumber_--;
    }

    // step the motor to step number 0, 1, 2, or 3:
    stepMotor(stepNumber_ % 4);

    lastTime_ = millis();
  }

  void NStepper::stepMotor(uint8_t thisStep)
  {
    if (numberOfPins_==2) {

      switch (thisStep) {
      case 0: // 01
        pin1_->write(LOW);
        pin2_->write(HIGH);
        break;
      case 1: // 11
        pin1_->write(HIGH);
        pin2_->write(HIGH);
        break;
      case 2: // 10
        pin1_->write(HIGH);
        pin2_->write(LOW);
        break;
      case 3: // 00
        pin1_->write(LOW);
        pin2_->write(LOW);
        break;
      }

    }

    if (numberOfPins_== 4) {

      switch (thisStep) {
      case 0: // 1010
        pin1_->write(HIGH);
        pin2_->write(LOW);
        pin3_->write(HIGH);
        pin4_->write(LOW);
        break;
      case 1: // 0110
        pin1_->write(LOW);
        pin2_->write(HIGH);
        pin3_->write(HIGH);
        pin4_->write(LOW);
        break;
      case 2: //0101
        pin1_->write(LOW);
        pin2_->write(HIGH);
        pin3_->write(LOW);
        pin4_->write(HIGH);
        break;
      case 3: //1001
        pin1_->write(HIGH);
        pin2_->write(LOW);
        pin3_->write(LOW);
        pin4_->write(HIGH);
        break;
      }
    }

  }

}
