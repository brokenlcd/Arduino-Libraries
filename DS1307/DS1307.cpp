/*
 * DS1307.cpp
 * Kyle Isom <isomk@kyleisom.net>
 *
 * Arduino library to use DS1307
 * I2C address is hardcoded as 110100 - the data sheet implicitly states
 * that only one DS1307 can be on the bus. I was inspired by some of the
 * code at http://www.glacialwanderer.com/hobbyrobotics/?p=12
 */

#include "Wire.h"
#include "DS1307.h"

    
DS1307::DS1307(boolean singleDevice, boolean twentyfourhour) {
    if (singleDevice) { Wire.begin(); }
    if (twentyfourhour) { twentyfour = true; }
}


void DS1307::enableClock() {
    Wire.beginTransmission(DS1307_ADDR);
    Wire.send(0x00);
    Wire.send( 0 << DS1307CH );
    Wire.endTransmission();
}

void DS1307::disableClock() {
    Wire.beginTransmission(DS1307_ADDR);
    Wire.send(0x00);
    Wire.send( 1 << DS1307CH );
    Wire.endTransmission();
}

boolean DS1307::isEnabled() {
    byte sec;
    
    Wire.beginTransmission(DS1307_ADDR);
    Wire.send(0x00);
    Wire.endTransmission();
    Wire.requestFrom(DS1307_ADDR, 1);
    
    sec = Wire.receive();
    return sec & (1 << DS1307CH) ? false : true;
}

void DS1307::getTime(boolean *AMPM, byte *seconds, byte *minute, byte *hour) {
    Wire.beginTransmission(DS1307_ADDR);
    Wire.send(0x00);
    Wire.endTransmission();
    
    Wire.requestFrom(DS1307_ADDR, 3);
    *seconds = bcd_to_dec(Wire.receive() & DS1307_SEC);
    *minute = bcd_to_dec(Wire.receive() );
    *hour = Wire.receive();
    
    check24Hour() ? getHour24(*hour) : getHour12(*AMPM, *hour);
    
    *hour = bcd_to_dec(*hour);
}

void DS1307::getHour12(boolean AMPM, byte hour) {
    AMPM = (hour | ( 1 << DS1307_AMPM )) ? true : false;  
    hour &= DS1307_12HR;
}

void DS1307::getHour24(byte hour) { hour = bcd_to_dec(hour & DS1307_24HR); }

byte DS1307::bcd_to_dec(byte data) { return (((data / 16) * 10) + (data % 16)); }

byte DS1307::dec_to_bcd(byte data) { return (((data / 10) * 16) + (data % 10)); }

 
boolean DS1307::check24Hour() {
    byte temp;
    Wire.beginTransmission(DS1307_ADDR);
    Wire.send(0x02);
    Wire.endTransmission();
    
    Wire.requestFrom(DS1307_ADDR, 1);
    temp = Wire.receive();
    return ( temp | (0 << DS1307_24HR) ? true : false ) ; 
}

void DS1307::setup() {
    if (!isEnabled()) { enableClock(); }
    if  ( (twentyfour == true) && (check24Hour() == false) ) { 
        set24();
        return;
    }
    
    if ( (twentyfour == false) && (check24Hour() == true) ) {
        set12();
        return;
    }
    
}

void DS1307::set24(void) {
    Wire.beginTransmission(DS1307_ADDR);
    Wire.send(0x02);
    Wire.send(0 << DS1307_24HR);
    Wire.endTransmission();
}

void DS1307::set12(void) {
    Wire.beginTransmission(DS1307_ADDR);
    Wire.send(0x02);
    Wire.send(1 << DS1307_MODE);
    Wire.endTransmission();
}

void DS1307::getDate(byte *day, byte *month, byte *year) {
    Wire.beginTransmission(DS1307_ADDR);
    Wire.send(0x04);
    Wire.endTransmission();
    
    Wire.requestFrom(DS1307_ADDR, 3);
    *day = bcd_to_dec(Wire.receive());
    *month = bcd_to_dec(Wire.receive());
    *year = bcd_to_dec(Wire.receive());
}

void DS1307::dayOfWeek(byte *weekday) {
    Wire.beginTransmission(DS1307_ADDR);
    Wire.send(0x03);
    Wire.endTransmission();
    
    Wire.requestFrom(DS1307_ADDR, 1);
    *weekday = bcd_to_dec(Wire.receive());
}

void DS1307::setDTC(byte *seconds, byte *minute, byte *hour, byte *weekday, byte *day, byte *month, byte *year) {
    setTime(seconds, minute, hour);
    setDayOfWeek(weekday);
    setDate(day, month, year);
}

void DS1307::setDTC(byte *seconds, byte *minute, byte *hour, byte *day, byte *month, byte *year) {
    setTime(seconds, minute, hour);
    setDate(day, month, year);
}


void DS1307::getDTC(byte *AMPM, byte *seconds, byte *minute, byte *hour, byte *weekday, byte *day, byte *month, byte *year) {
    getTime(AMPM, seconds, minute, hour);
    dayOfWeek(weekday);
    getDate(day, month, year);
}


void DS1307::getDTC(byte *seconds, byte *minute, byte *hour, byte *weekday, byte *day, byte *month, byte *year) { 
    getDTC(NULL, seconds, minute, hour, weekday, day, month, year); 
}

void DS1307::setTime(byte *seconds, byte *minute, byte *hour, byte *AMPM) {
    Wire.beginTransmission(DS1307_ADDR);
    Wire.send(0x00);
    Wire.send(dec_to_bcd(*seconds));
    Wire.send(dec_to_bcd(*minute));
    Wire.send(dec_to_bcd(*hour));
    Wire.endTransmission();
}

void DS1307::setDate(byte *day, byte *month, byte *year) {
    Wire.beginTransmission(DS1307_ADDR);
    Wire.send(0x04);
    Wire.send(dec_to_bcd(*day));
    Wire.send(dec_to_bcd(*month));
    Wire.send(dec_to_bcd(*year));
    Wire.endTransmission();
}

void DS1307::setDayOfWeek(byte *weekday) {
    Wire.beginTransmission(DS1307_ADDR);
    Wire.send(0x03);
    Wire.send(dec_to_bcd(*weekday));
    Wire.endTransmission();
}

