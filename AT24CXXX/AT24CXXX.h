/*
 * AT24CXXX.h
 * Kyle Isom <isomk@kyleisom.net>
 *
 * Arduino library to use an AT24CXXX I2C EEPROM
 *
 */
 
#ifndef __AT24CXXX_H
#define __AT24CXXX_H

#include "WProgram.h"

#define AT24CXX_A0      0x00
#define AT24CXX_A1      0x01
#define AT24CXX_A2      0x02
#define AT24CXX_BASE    0x50

class AT24CXXC {
    public:
        /****************
         * CONSTRUCTORS *
         ****************/
         AT24CXXX(byte a0 = 0, byte a1 = 0, byte a2 = 0, byte size);
    
    private:
        byte A0;
        byte A1;
        byte A2;
        byte ADDR;
        byte SIZE;




#endif
