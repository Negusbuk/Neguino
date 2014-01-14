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

  template<typename T>
  class Vector {
  public:

    Vector()
    :d_size(0), d_capacity(0), d_data(0)
    {

    }

    Vector(size_t n)
    :d_size(n), d_capacity(n)
    {
      d_data = (T*)malloc(d_capacity*sizeof(T));
    }

    Vector(Vector const &other)
    :d_size(other.d_size), d_capacity(other.d_capacity), d_data(0)
    {
      d_data = (T*)malloc(d_capacity*sizeof(T));
      memcpy(d_data, other.d_data, d_size*sizeof(T));
    }

    ~Vector()
    {
      free(d_data);
    }

    Vector &operator=(Vector const &other)
    {
      free(d_data);
      d_size = other.d_size;
      d_capacity = other.d_capacity;
      d_data = (T*)malloc(d_capacity*sizeof(T));
      memcpy(d_data, other.d_data, d_size*sizeof(T));
      return *this;
    }

    void push_back(T const &x)
    {
      resize();
      d_data[d_size++] = x;
    }

    size_t size() const { return d_size; }
    T const &operator[](size_t idx) const { return d_data[idx]; }
    T &operator[](size_t idx) { return d_data[idx]; }

  protected:

    void resize() {
      if (d_capacity>d_size) return;
      d_capacity++;
      T *newdata = (T*)malloc(d_capacity*sizeof(T));
      memcpy(newdata, d_data, d_size * sizeof(T));
      free(d_data);
      d_data = newdata;
    };

    size_t d_size;
    size_t d_capacity;
    T *d_data;
  };

}

#endif
