//
// Lucky Resistor's Data Logger (Minimal Version)
// ---------------------------------------------------------------------------
// (c)2015 by Lucky Resistor. See LICENSE for details.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
#include "Storage.h"


// This is the EEPROM implementation for storage.
#include <EEPROM.h>



Storage::Storage()
{
}


Storage::~Storage()
{
}


void Storage::begin()
{
    // nothing required for EEPROM.
}


uint32_t Storage::size()
{
    return EEPROM.length();
}


void Storage::writeByte(uint32_t index, uint8_t data)
{
#ifdef LR_STORAGE_DEBUG
    Serial.print(F("Write to index "));
    Serial.print(index, HEX);
    Serial.print(F(" data "));
    Serial.println(data, HEX);
#endif
    EEPROM.update(index, data);
}


uint8_t Storage::readByte(uint32_t index)
{
    return EEPROM.read(index);
}


