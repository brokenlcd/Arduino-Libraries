/*
 * ping.h
 * Kyle Isom <isomk@kyleisom.net>
 *
 * Library to use PARALLAX PING))) ultrasonic ranging sensor
 *
 *
 */

 #include "WProgram.h"
 
 // distance constants; gathered from a physics textbook and google's unit
 // converter using a speed of sound of 343 m/s or 1125 ft/s; these numbers
 // are multiplied by two to get the round trip time.
 #define    USECTOCM            58
 #define    USECTOIN           148

// state of pin on pulse return 
 #define    PULSERETURN       HIGH
  
 class Ping {
    public:
        /* CONSTRUCTOR */
        Ping(int pingPin = 2);
        
        int ping_cm(void);      // gets distance in centimeters
        int ping_in(void);      // gets distance in inches
        
    
    private:

        /* VARIABLES */
        int pin;
        
        long pulseTime;    // time in microseconds for pulse to return
 
        /* FUNCTIONS */
        void getPulse(void);
        void sendPulse(void);
  
 };
