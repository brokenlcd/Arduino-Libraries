/*
 * DiffDrive.h
 * Kyle Isom <isomk@kyleisom.net>
 *
 * Differential drive using a TI SN754410 quad half-h driver
 * 
 */
 

#ifndef __DIFFDRIVE_H
#define __DIFFDRIVE_H
 
#include "Motor.h"
#include "WProgram.h"

 class DiffDrive {
    public:
        DiffDrive(int pinA, int pinB, int pinC, int pinD, boolean motorAleft = true, 
            boolean motorBright = true, boolean vcc_tied = true, int enPinA = 0, 
            int enPinB = 0);
        void forward(void);
        void backward(void);
        void left(void);
        void right(void);
        void stop(void);
    
    private:
        Motor motorA, motorB;
        int pinA1, pinA2;
        int pinB1, pinB2;
        boolean leftA, rightB, vcc_tied;
 };
 
 
 #endif
