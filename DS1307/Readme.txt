ARDUINO DS1307 INTERFACE LIBRARY
Written by Kyle Isom <isomk@kyleisom.net>

Version 1.0
2010 FEB 10 1657 MST

.:[ INTRO / HARDWARE INTERFACE ]:.
The DS1307 RTC is a pretty easy to use realtime clock; it's small size 
(DIP8 / SOIC8) makes it easy to use in projects. Connecting it to the 
Arduino is similarly easy. It follows the standard I2C connection procedures:
connect the SDA pin (pin 5 on the DS1307) to analog pin 4 on the Arduino and
connect the SCL pin (pin 6 on the DS1307) to analog pin 5 on the Arduino. The
DS1307 uses a 32.768 kHz crystal with 12.5pF capacitance (which may be found on
Digikey for as cheap as a quarter, ex. 728-1001-ND) which is connected to
pins 1 and 2. Pin 4 goes to ground, pin 8 goes to Vcc (which must be between
4.5 and 5.5V). To keep time during poweroff states, a 3V lithium cell battery
can be used: the positive lead goes to pin 3, the negative lead to pin 4. If
you're not using a battery (which means anytime the DS1307 loses power, it loses
time), you need to ground pin 3.

.:[ CAVEATS ]:.
The DS1307 library will load Wire.h I had to include the Wire libraries in
with the DS1307 library to get it to work, version 2.0 hopefully won't require
this but I'm not as familiar with Arduino development so that might take some
time. 

The concept of 12 hour time is almost alien to me, I've been using 24 hour time
since middle school and now convert 12-hour times to 24 hour times in my head.
So 12 hour time support in this library is sketchy at best. If there's interest,
email me to get me to work on it.

.:[ BASIC USE OF THE LIBRARY ]:.
The constructor takes at most two arguments:
    DS1307(boolean singleDevice, boolean twentyfourhour);
    
The rest of this document will assume your DS1307 instance is called RTC.

By default, singleDevice is false and twentyfourhour is true - this means that
    A. singleDevice is a flag indicating whether the DS1307 is the only I2C
    device on the bus. In the constructor, if singleDevice is true, then
    Wire.begin() is called in the constructor so you don't need to. 
    
    B. If you just want to use 24 hour time and the DS1307 isn't the only device
    on the I2C bus, you can do the following:
        DS1307 RTC;

In your setup() loop, or at least before you use the DS1307, you should call
RTC.setup(), which just makes sure the clock is enabled and ensures the clock is 
in the right time mode (i.e. 12/24 hour). If the DS1307 is not the only device 
on the bus, you need to call Wire.begin() before calling the setup() function. 

Getting the date and time is easy:
    // initialize variables to hold the time data
    byte seconds, minutes, hours, day, month, year;
    
    RTC.getTime(seconds, minutes, hours);
    RTC.getDate(day, month, year);
    
The RTC also includes a register for the day of the week, so if you have
a variable to store day of week you can get that as well:
    // initialize variables to hold the time data
    byte seconds, minutes, hours, weekday, day, month, year;
    
    RTC.getDTC(seconds, minutes, hours, weekday, day, month, year);
    
    or to get just the weekday:
    
    RTC.getDayofWeek(weekday);

Printing values requires a cast to integer because the values returned are 
bytes: 
    lcd.print((int) seconds);
    or similarly,
    lcd.print(seconds, DEC);
    
Setting the date and time is similarly easy:
    RTC.setTime(seconds, minutes, hours);
    RTC.setDate(day, month, year);
    RTC.setDTC(seconds, minutes, hours, day, month, year);
    RTC.setDTC(seconds, minutes, hours, weekday, day, month, year);

That's basically all you need to get and set the date and time on the RTC in
your project.

.:[ ADVANCED USE OF THE LIBRARY ]:.
The DS1307 has a feature called "Clock Halt." If you don't need the oscillator,
you can turn it off to conserve power. Note that this will make you lose time
and you will need to reset the time when power comes back on. The functions
for this are:

    boolean RTC.isEnabled();
    
    which returns true if the clock is enabled and the RTC is keeping time.
    
    RTC.disableClock();
    RTC.enableClock();
    
    These two functions disable and enable the clock, respectively.
    
If you want to change between 12 and 24 hour time, which requires the hour to 
be reset, there are two functions to do that:
    RTC.set24();
    RTC.set12();

As was mentioned in the introduction, I don't personally use 12-hour time, so
support in the library as of the time of this writing is sketchy at best. I
don't know that it will work properly. If there is interest, I will work on 
support for 12 hour time.

The RTC uses a binary coded decimal (BCD) for its values. The library will 
automatically convert between BCD and decimal as needed, but if you need a 
number in either format, you can use the following functions appropriately:
    byte RTC.bcd_to_dec(byte data);
    byte RTC.dec_to_bcd(byte data);


If you have any questions or comments about the code (feedback is welcome),
send an email to brokenlcd@gmail.com or isomk@kyleisom.net.

