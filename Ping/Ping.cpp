/*
 * ping.cpp
 * Kyle Isom <isomk@kyleisom.net>
 *
 * Library to use PARALLAX PING))) ultrasonic ranging sensor
 *
 *
 */

 #include "Ping.h"
 
 Ping::Ping(int pingPin) {
     pin = pingPin;
 }
 
 void Ping::sendPulse() {
     pulseTime = 0;
     pinMode(pin, OUTPUT);
     digitalWrite(pin, LOW);
     delayMicroseconds(3);          // minimum time that delayMicroseconds 
                                    // function is known to be accurate for
                                    // (see Caveats / Known issues at
                                    // http://is.gd/8xupi
     digitalWrite(pin, HIGH);
     delayMicroseconds(5);          // max pulse send time according to 
                                    // datasheet
     digitalWrite(pin, LOW);        // end pulse
 }
 
 void Ping::getPulse() {     
     pinMode(pin, INPUT);
     pulseTime = pulseIn(pin, PULSERETURN);
     delay(5);                      // delay long enough to allow URS to reset
 }
 
 int Ping::ping_cm() {
     sendPulse();
     getPulse();
     return pulseTime / USECTOCM;
 }
 
 int Ping::ping_in() {
     sendPulse();
     getPulse();
     return pulseTime / USECTOIN;
 }
     
