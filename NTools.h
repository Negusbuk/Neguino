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

#ifndef Neguino_TOOLS_H
#define Neguino_TOOLS_H

#include <Arduino.h>

namespace Neguino
{
  
  template<typename T>
  T maximum(T a, T b) {
    return (a>b?a:b);
  }

  template<typename T>
  T minimum(T a, T b) {
    return (a<b?a:b);
  }

  template<typename T>
  T euclid(T a, T b) {
    if (b==0) return 0;
    T numerator = maximum(a, b);
    T denominator = minimum(a, b);
    T mod = numerator % denominator;
    if (mod==0)
      return denominator;
    else
      return euclid(denominator, mod);
  }

}

#endif
