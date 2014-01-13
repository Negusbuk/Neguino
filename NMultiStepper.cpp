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

#include <NMultiStepper.h>

namespace Neguino {

  NMultiStepper::NMultiStepper()
  :lastTime_(0)
  {

  }

  void NMultiStepper::addStepper(NStepper* stepper)
  {
    steppers_.push_back(stepper);
    steps_.push_back(0);
  }

  void NMultiStepper::step(uint8_t idx, int steps)
  {
    if (idx>=steps_.size()) return;
    steps_[idx] = steps;
  }

  void NMultiStepper::execute()
  {
    if (steps_.size()==0) return;

    unsigned int minStepDelay = steppers_[0]->getStepDelay();
    for (uint8_t s=1;s<steps_.size();++s) {
      minStepDelay = Neguino::euclid(minStepDelay, steppers_[s]->getStepDelay());
    }

    unsigned long time;
    unsigned long dtime;
    unsigned int stepsLeft;

    while (1) {

      time = millis();
      dtime = time - lastTime_;

      if (dtime >= minStepDelay) {

        stepsLeft = 0;

        for (uint8_t s=0;s<steps_.size();++s) {

          if (dtime >= steppers_[s]->getStepDelay() &&
              abs(steps_[s])!=0) {

            if (steps_[s]>0) {
              steppers_[s]->singleStep(1);
              steps_[s]--;
            }
            if (steps_[s]<0) {
              steppers_[s]->singleStep(-1);
              steps_[s]++;
            }

            stepsLeft += abs(steps_[s]);
          }
        }

        if (stepsLeft==0) break;
      }

      lastTime_ = time;
    }

    for (uint8_t s=0;s<steps_.size();++s) {
      steps_[s] = 0;
    }
  }

}
