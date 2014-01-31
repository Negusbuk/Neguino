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

/*! \file NTools.h
*/

/*! \namespace Neguino
    \brief Namespace encapsulating all classes and functions.
*/
namespace Neguino
{
  
  //! template function returning the maximum of two numbers.
  /*!
    \param a the first argument.
    \param b the second argument.
   */
  template<typename T>
  T maximum(T a, T b) {
    return (a>b?a:b);
  }

  //! template function returning the minimum of two numbers.
  /*!
    \param a the first argument.
    \param b the second argument.
   */
  template<typename T>
  T minimum(T a, T b) {
    return (a<b?a:b);
  }

  //! template function returning the greatest common divisor of two numbers.
  /*!
    \param a the first argument.
    \param b the second argument.
   */
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

  //! a vector class
  /*!
   */
  template<typename T>
  class NVector {
  public:

    //! constructs a new and empty vector.
    NVector()
    :d_size(0), d_capacity(0), d_data(0)
    {

    }

    //! constructs a new vector initial size n.
    NVector(size_t n)
    :d_size(n), d_capacity(n)
    {
      d_data = (T*)malloc(d_capacity*sizeof(T));
    }

    //! constructs a new vector and copies the contents of vector other.
    NVector(NVector const &other)
    :d_size(other.d_size), d_capacity(other.d_capacity), d_data(0)
    {
      d_data = (T*)malloc(d_capacity*sizeof(T));
      memcpy(d_data, other.d_data, d_size*sizeof(T));
    }

    //! desctructor
    ~NVector()
    {
      free(d_data);
    }

    //! clears the vector and assigns the contents of vector other
    NVector &operator=(NVector const &other)
    {
      free(d_data);
      d_size = other.d_size;
      d_capacity = other.d_capacity;
      d_data = (T*)malloc(d_capacity*sizeof(T));
      memcpy(d_data, other.d_data, d_size*sizeof(T));
      return *this;
    }

    //! adds a new element to the end of the vector
    void push_back(T const &x)
    {
      resize();
      d_data[d_size++] = x;
    }

    //! returns the size of the vector, i.e. the number of elements.
    size_t size() const { return d_size; }

    //! returns element at index idx as a const reference.
    T const &operator[](size_t idx) const { return d_data[idx]; }

    //! returns element at index idx as a reference.
    T &operator[](size_t idx) { return d_data[idx]; }

  protected:

    //! resizes the vector, i.e. increases the capacity by one element.
    /*!
     */
    void resize() {
      if (d_capacity>d_size) return;
      d_capacity++;
      T *newdata = (T*)malloc(d_capacity*sizeof(T));
      memcpy(newdata, d_data, d_size * sizeof(T));
      free(d_data);
      d_data = newdata;
    };

    size_t d_size;     //!< the size of the vector
    size_t d_capacity; //!< the capacity of the vector
    T *d_data;         //!< pointer to the actual storage of elements
  };

}

#endif
