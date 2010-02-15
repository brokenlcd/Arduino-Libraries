/*
 * DS1307.h
 * Kyle Isom <isomk@kyleisom.net>
 *
 * Arduino library to use DS1307
 * I2C address is hardcoded as 110100 - the data sheet implicitly states
 * that only one DS1307 can be on the bus.
 *
 * Should load the Wire library if it is not already loaded. The Wire library
 * is released under the LGPL, and was written by Nicholas Zambetti.
 *
 * released under a BSD license
 *
 *  Copyright 2010 Kyle Isom. All rights reserved.
 *  
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions are met:
 *  
 *     1. Redistributions of source code must retain the above copyright notice, 
 *        this list of conditions and the following disclaimer.
 *  
 *     2. Redistributions in binary form must reproduce the above copyright 
 *        notice, this list of conditions and the following disclaimer in the 
 *        documentation and/or other materials provided with the distribution.
 *  
 *  THIS SOFTWARE IS PROVIDED BY KYLE ISOM ``AS IS'' AND ANY EXPRESS OR IMPLIED
 *  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
 *  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO 
 *  EVENT SHALL KYLE ISOM OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, 
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
 *  OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
 *  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
 *  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
 *  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *  
 *  The views and conclusions contained in the software and documentation are 
 *  those of the authors and should not be interpreted as representing official 
 *  policies, either expressed or implied, of Kyle Isom. 
 */

#ifndef __DS1307_H
#define __DS1307_H

#include "WProgram.h"



#define    DS1307_ADDR     0x68
#define    DS1307CH        0x07
#define    DS1307_SEC      0x7F
#define    DS1307_MODE     0x06
#define    DS1307_24HR     0x3F   
#define    DS1307_AMPM     0x20
#define    DS1307_12HR     0x1F
#define    DS1307_EPOCH    2000

 
 class DS1307 {
    public:
        /* constructor */
        // Pass a true if the DS1307 is the only I2C device on the bus
        DS1307(boolean singleDevice = false, boolean twentyfourhour = true);
        
        /* read function */
        boolean isEnabled(void);
        boolean check24Hour(void);
        void getTime(boolean *AMPM, byte *seconds, byte *minute, byte *hour);
        void getTime(byte *seconds, byte *minute, byte *hour) { getTime(NULL, seconds, minute, hour); }
        void getDate(byte *day, byte *month, byte *year);
        void dayOfWeek(byte *weekday);
        void getDTC(byte *AMPM, byte *seconds, byte *minute, byte *hour, byte *weekday, byte *day, byte *month, byte *year);
        void getDTC(byte *seconds, byte *minute, byte *hour, byte *weekday, byte *day, byte *month, byte *year);
        
        /* write functions */
        void enableClock(void);
        void disableClock(void);
        void set24(void);
        void set12(void);
        void setup(void);
        void setTime(byte *seconds, byte *minute, byte *hour, byte *AMPM);
        void setTime(byte *seconds, byte *minute, byte *hour) { setTime(seconds, minute, hour, NULL); }
        void setDate(byte *day, byte *month, byte *year);
        void setDayOfWeek(byte *weekday);
        void setDTC(byte *seconds, byte *minute, byte *hour, byte *weekday, byte *day, byte *month, byte *year);
        void setDTC(byte *seconds, byte *minute, byte *hour, byte *day, byte *month, byte *year);
        
        /* conversion functions */
        byte bcd_to_dec(byte data);
        byte dec_to_bcd(byte data);

    private:
        boolean twentyfour;
        
        void getHour24(byte hour);
        void getHour12(boolean AMPM, byte hour);
 };
 
#endif
