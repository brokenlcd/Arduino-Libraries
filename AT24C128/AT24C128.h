/*
 * AT24C128.h
 * Kyle Isom <isomk@kyleisom.net>
 *
 * Arduino library to use an AT24C128 I2C EEPROM
 *
 */
 
#ifndef __AT24C128_H
#define __AT24C128_H

#include "WProgram.h"

#define AT24C128_A0      0x00
#define AT24C128_A1      0x01
#define AT24C128_A2      0x02
#define AT24C128_BASE    0x50
#define AT24C128_SIZE    0x80

class AT24C128 {
    public:
        /****************
         * CONSTRUCTORS *
         ****************/
         AT24C128(byte a0 = 0, byte a1 = 0, byte a2 = 0, );
         
        /*******************
         * WRITE FUNCTIONS *
         *******************/
         byteWrite(byte word0, byte word1, byte data);
         pageWrite(
    
    private:
        byte A0;
        byte A1;
        byte A2;
        byte ADDR;
        byte SIZE;

};


#endif
