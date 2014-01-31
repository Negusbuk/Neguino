/*  Copyright (c) 2013 by Andreas Mussgiller <andreas ~AT~ mussgiller.de>

    This file is part of the Arduino Negusbuk Library.

    The Arduino Negusbuk Library is free software: you can redistribute it
    and/or modify it under the terms of the GNU General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    The Arduino Negusbuk Library is distributed in the hope that it will be
    useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with The Arduino Negusbuk Library.  If not, see
    <http://www.gnu.org/licenses/>. */

#include <NSPIEEPROM25AA.h>

namespace Neguino {

  NSPIEEPROM25AA::NSPIEEPROM25AA(const NSPIChipSelect& _cs,
                                 uint32_t _size, uint16_t _pagesize,
                                 uint8_t _delay)
  : NSPIEEPROM(_cs, _size, _pagesize),
    delay_(_delay)
  {

  }

  void NSPIEEPROM25AA::init()
  {

  }

  void NSPIEEPROM25AA::write(uint32_t address, uint8_t* buffer, uint16_t n)
  {
    if (address>size_) return;
    uint16_t page = address / pagesize_;
    uint16_t paddress = address % pagesize_;
    uint16_t bufferPosition = 0;
    uint16_t bufferRemaining = n;

    //first we align
    if (paddress+bufferRemaining>pagesize_) {
      bufferPosition = pagesize_ - paddress;
      bufferRemaining -= bufferPosition;
      writeAligned(page*pagesize_+paddress, buffer, bufferPosition);
      if (paddress!=0) paddress = 0;
      page++;
    }

    while (bufferPosition<n) {
      uint8_t * temp = &buffer[bufferPosition];
      int toWrite = bufferRemaining;
      if (toWrite>64) toWrite = 64;
      writeAligned(page*pagesize_+paddress, temp, toWrite);
      if (paddress!=0) paddress = 0;
      bufferPosition += toWrite;
      bufferRemaining -= toWrite;
      page++;
    }
  }

  void NSPIEEPROM25AA::writeAligned(uint32_t address, uint8_t* buffer, uint16_t n)
  {
    selectChip();
    SPI.transfer(WREN);
    deselectChip();

    delay(delay_);

    selectChip();
    SPI.transfer(WRITE);
    SPI.transfer((uint8_t)(address>>8));
    SPI.transfer((uint8_t)(address));
    for (unsigned int i=0;i<n;++i) {
      SPI.transfer(buffer[i]);
    }
    deselectChip();

    delay(delay_);

    selectChip();
    SPI.transfer(WRDI);
    deselectChip();

    delay(delay_);
  }

  void NSPIEEPROM25AA::read(uint32_t address, uint8_t* buffer, uint16_t n)
  {
    selectChip();
    SPI.transfer(READ);
    SPI.transfer((uint8_t)(address>>8));
    SPI.transfer((uint8_t)(address));
    for (int i=0;i<n;++i) {
      buffer[i] = SPI.transfer(0xff);
    }
    deselectChip();

    delay(delay_);
  }

  NSPIEEPROM25AA128k::NSPIEEPROM25AA128k(const NSPIChipSelect& _cs, uint8_t _delay)
  : NSPIEEPROM25AA(_cs, 16384, 64, _delay)
  {

  }

}
