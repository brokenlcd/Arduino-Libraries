ARDUINO DS1307 INTERFACE LIBRARY
Written by Kyle Isom <isomk@kyleisom.net>

Version 1.0
2010 FEB 10 1657 MST

The DS1307 RTC is a pretty easy to use realtime clock; it's small size 
(DIP8 / SOIC8) makes it easy to use in projects. Connecting it to the 
Arduino is similarly easy. It follows the standard I2C connection procedures:
connect the SDA pin (pin 5 on the DS1307) to analog pin 4 on the Arduino and
connect the SCL pin (pin 6 on the DS1307) to analog pin 5 on the Arduino. The
DS1307 uses a 32.768 kHz crystal with 12.5pF capacitance (which may be found on
Digikey for as cheap as a quarter, ex. 728-1001-ND) which is connected to
pins 1 and 2. Pin 4 goes to ground, pin 8 goes to Vcc (which must be between
4.5 and 5.5V). To keep time during poweroff states, a 3V lithium cell battery
can be used: the positive lead goes to pin 3, the negative lead to pin 4.


