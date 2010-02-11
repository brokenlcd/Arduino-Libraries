/*
 * AT24CXXX.cpp
 * Kyle Isom <isomk@kyleisom.net>
 *
 * Arduino library to use an AT24CXXX I2C EEPROM
 *
 */
 
#include "AT24CXXX.h"

AT24CXXX(byte a0 = 0, byte a1 = 0, byte a2 = 0, byte size) {
    SIZE = size;
    ADDR = 0x50 + (a2 << AT24CXX_A2) + (a1 << AT24CXX_A1) + (a0 << AT24CXX_A0);
}
    
