/*
 * DiffDrive.cpp
 * Kyle Isom <isomk@kyleisom.net>
 *
 * Differential drive using a TI SN754410 quad half-h driver
 * 
 */
 
#include "DiffDrive.h"

DiffDrive::DiffDrive(int npinA, int npinB, int npinC, int npinD, boolean motorAleft, 
    boolean motorBright, boolean nvcc_tied, int enPinA, int enPinB) {

    pinA1 = npinA;
    pinA2 = npinB;
    pinB1 = npinC;
    pinB2 = npinD;
    leftA = motorAleft;
    rightB = motorBright;
    vcc_tied = nvcc_tied;
    
    motorA.setPins(pinA1, pinA2);
    motorB.setPins(pinB1, pinB2);
    motorA.setEnable(enPinA);
    motorB.setEnable(enPinB);
    
   
    if (!vcc_tied) {
        motorA.enable();
        motorB.enable();
    }
}

void DiffDrive::forward(void) {
    motorA.forward();
    motorB.forward();
}

void DiffDrive::backward(void) {
    motorA.backward();
    motorB.backward();
}

void DiffDrive::left(void) {
    motorA.backward();
    motorB.forward();
}

void DiffDrive::right(void) {
    motorA.forward();
    motorB.backward();
}

void DiffDrive::stop(void) { 
    motorA.stop();
    motorB.stop();
}
