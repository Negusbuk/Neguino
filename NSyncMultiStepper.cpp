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

#include <NSyncMultiStepper.h>

namespace Neguino {

  NSyncMultiStepper::NSyncMultiStepper()
  :NMultiStepper()
  {

  }

  void NSyncMultiStepper::execute()
  {
    if (steps_.size()==0) return;

    Neguino::NVector<uint8_t> speeds(steps_.size());
    unsigned int duration;
    unsigned int maxDuration = 0;
    for (uint8_t s=0;s<steps_.size();++s) {
      speeds[s] = steppers_[s]->getSpeed();
      duration = steppers_[s]->getStepDelay()*abs(steps_[s]);
      if (duration>maxDuration) maxDuration = duration;
    }
    unsigned int delay;
    for (uint8_t s=0;s<steps_.size();++s) {
      delay = maxDuration / abs(steps_[s]);
      steppers_[s]->setStepDelay(delay);
    }

    NMultiStepper::execute();

    for (uint8_t s=0;s<steps_.size();++s) {
      steppers_[s]->setSpeed(speeds[s]);
    }
  }

}
