/****************************************************************************
 **
 **  Copyright (C) 2013, 2014 Andreas Mussgiller
 **
 **  based on libmcp23s17 by Thomas Preston
 **           http://github.com/piface/libmcp23s17
 **
 **  Datasheet: http://ww1.microchip.com/downloads/en/DeviceDoc/21919e.pdf
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

#include <SPI.h>

#include "NMCP23S08.h"

namespace Neguino {

  NMCP23S08Pin::NMCP23S08Pin(NMCP23S08* _mcp, uint8_t _pin)
  :mcp_(_mcp),
   pin_(_pin)
  {

  }

  void NMCP23S08Pin::setMode(uint8_t mode)
  {
    if (pin_>7) return;
    mcp_->writeBit(pin_, NMCP23S08::IODIR, mode);
  }

  void NMCP23S08Pin::write(uint8_t data)
  {
    if (pin_>7) return;
    mcp_->writeBit(pin_, NMCP23S08::GPIO, data);
  }

  uint8_t NMCP23S08Pin::read()
  {
    if (pin_>7) return -1;
    return mcp_->readBit(pin_, NMCP23S08::GPIO);
  }

  NMCP23S08::NMCP23S08(const NSPIChipSelect& _cs, uint8_t _address)
  :NSPIDevice(_cs),
   address_(_address)
  {
    SPI.begin();                // Start up the SPI bus<C9> crank'er up Charlie!
    SPI.setClockDivider(2);     // Sets the SPI bus speed
    SPI.setBitOrder(MSBFIRST);  // Sets SPI bus bit order (this is the default, setting it for good form!)
    SPI.setDataMode(SPI_MODE0);

    for (uint8_t i=0;i<8
    ;++i) {
      pins_[i] = 0;
    }
  }

  uint8_t NMCP23S08::readRegister(uint8_t reg)
  {
    uint8_t control_byte = getSPIControlByte(READ_CMD);
    uint8_t value = 0;

    selectChip();

    SPI.transfer(control_byte);
    SPI.transfer(reg);
    value = SPI.transfer(0x00);

    deselectChip();

    return value;
  }

  void NMCP23S08::writeRegister(uint8_t reg, uint8_t data)
  {
    uint8_t control_byte = getSPIControlByte(WRITE_CMD);

    selectChip();

    SPI.transfer(control_byte);
    SPI.transfer(reg);
    SPI.transfer(data);

    deselectChip();
  }

  uint8_t NMCP23S08::readBit(uint8_t bit, uint8_t reg)
  {
    return (readRegister(reg) >> bit) & 1;
  }

  void NMCP23S08::writeBit(uint8_t bit, uint8_t reg, uint8_t data)
  {
    uint8_t reg_data = readRegister(reg);
    if (data) {
      reg_data |= 1 << bit; // set
    } else {
      reg_data &= 0xff ^ (1 << bit); // clear
    }

    writeRegister(reg, reg_data);
  }

  void NMCP23S08::init()
  {
    const uint8_t ioconfig = SEQOP_OFF | HAEN_ON;
    writeRegister(IOCON, ioconfig);

    // I/O direction
    writeRegister(IODIR, IOINPUT);
 }

  NMCP23S08Pin* NMCP23S08::getPin(uint8_t pin)
  {
    if (pin>7) return 0;
    if (pins_[pin]==0) pins_[pin] = new NMCP23S08Pin(this, pin);
    return pins_[pin];
  }

  /**
   * Returns an SPI control byte.
   *
   * The MCP23S08 is a slave SPI device. The slave address contains four
   * fixed bits (0b0100) and three user-defined hardware address bits
   * (if enabled via IOCON.HAEN; pins A1 and A0) with the
   * read/write command bit filling out the rest of the control byte::
   *
   *     +-------------------+
   *     |0|1|0|0|0|A1|A0|R/W|
   *     +-------------------+
   *     |fixed |hw_addr |R/W|
   *     +-------------------+
   *     |7|6|5|4|3|2 |1 | 0 |
   *     +-------------------+
   *
   */
  uint8_t NMCP23S08::getSPIControlByte(COMMAND cmd)
  {
    uint8_t addr = (address_ << 1) & 0x6;
    uint8_t rw_cmd = cmd;
    rw_cmd &= 1; // just 1 bit long
    return 0x40 | addr | cmd;
  }

};
