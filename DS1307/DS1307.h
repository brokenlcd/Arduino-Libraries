/*
 * DS1307.h
 * Kyle Isom <isomk@kyleisom.net>
 *
 * Arduino library to use DS1307
 * I2C address is hardcoded as 110100 - the data sheet implicitly states
 * that only one DS1307 can be on the bus
 */

#ifndef __DS1307_H
#define __DS1307_H
 
 #include "WProgram.h"
 #include "Wire.h"
 #include <utility/twi.h>

 
 
 #define    DS1307_ADDR     0x68
 
 class DS1307 {
    public:
        
    private:
             
 };
 
#endif
