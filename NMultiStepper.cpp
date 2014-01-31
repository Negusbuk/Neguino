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

    unsigned long time;
    unsigned long dtime;
    unsigned int stepsLeft = 0;
    unsigned long lastTime = millis();

    Neguino::NVector<unsigned long> lastTimes(steppers_.size());

    unsigned int minStepDelay = steppers_[0]->getStepDelay();
    for (uint8_t s=1;s<steps_.size();++s) {
      minStepDelay = Neguino::euclid(minStepDelay, steppers_[s]->getStepDelay());
    }
    
    for (uint8_t s=0;s<steps_.size();++s) {
      stepsLeft += abs(steps_[s]);
      lastTimes[s] = lastTime;

      /*
      Serial.print(s, DEC);
      Serial.print("  ");
      Serial.print(steps_[s], DEC);
      Serial.print("  ");
      Serial.print(steppers_[s]->getStepDelay(), DEC);
      Serial.print("\n");
      
      Serial.print("cycles ");
      Serial.print(cycles[s], DEC);
      Serial.print("\n");
      */
    }
    
    /*
    Serial.print("min step delay: ");
    Serial.print(minStepDelay, DEC);
    Serial.print("\n");
    
    Serial.print("max step delay: ");
    Serial.print(maxStepDelay, DEC);
    Serial.print("\n");
    
    Serial.print("max cycles: ");
    Serial.print(maxCycles, DEC);
    Serial.print("\n");
    */
   
    while (stepsLeft>0) {

      time = millis();
      dtime = time - lastTime;

      if (dtime>=minStepDelay) {

        stepsLeft = 0;

        /*
        Serial.print("dtime ");
        Serial.print(dtime, DEC);
        Serial.print(" cycle ");
        Serial.print(cycle, DEC);
        Serial.print("\n");
        */

        for (uint8_t s=0;s<steps_.size();++s) {

          dtime = time - lastTimes[s];
          
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
            
            lastTimes[s] = time;
          }

          //Serial.print(steps_[s], DEC);
          //Serial.print(" step left xxx\n");

          stepsLeft += abs(steps_[s]);
        }
        
        //Serial.print(stepsLeft, DEC);
        //Serial.print(" step left\n");

        lastTime = time;
      }
    }

    for (uint8_t s=0;s<steps_.size();++s) {
      steps_[s] = 0;
    }
  }

}
