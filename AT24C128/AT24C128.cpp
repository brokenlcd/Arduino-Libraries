/*
 * AT24C128.cpp
 * Kyle Isom <isomk@kyleisom.net>
 *
 * Arduino library to use an AT24C128 I2C EEPROM
 *
 */
 
#include "AT24C128.h"



AT24C128::AT24C128(byte a0, byte a1, byte a2, byte size) {
    SIZE = size;
    A0 = a0;
    A1 = a1;
    A2 = a2;
    ADDR = AT24C128_BASE + (A2 << AT24C128_A2) + (A1 << AT24C128_A1) + (A0 << AT24C128_A0);
}


