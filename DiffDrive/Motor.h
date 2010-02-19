/*
 * Motor.h
 * Kyle Isom <isomk@kyleisom.net>
 *
 * A simple motor abstraction for use in the DiffDrive class.
 *
 */
 
 #ifndef __MOTOR_H
 #define __MOTOR_H
 
 #include "WProgram.h"
 
 
 class Motor {
    public:
        
    
        /* CONSTRUCTOR */ 
        Motor(void);
        
        /* MODIFIERS */
        void setPinA(int pin1) { pinA = pin1; }
        void setPinB(int pin2) { pinB = pin2; }
        void setPins(int pin1, int pin2) { pinA = pin1; pinB = pin2; }
        void setEnable(int enablePin);
        void setForward(boolean nleft) { left_forward = nleft; }
        void enable(void);
        void disable(void);
        
        /* ACCESSORS */
        int gpA(void) { return pinA; }
        int gpB(void) { return pinB; }
        int gEn(void) { return enPin; }
        
        /* MOTOR CONTROL */
        void forward(void);
        void backward(void);
        void stop(void);
 
    private:
        int pinA, pinB, enPin;
        boolean vcc_tied; 
        boolean left_forward;

 };
 
 #endif
