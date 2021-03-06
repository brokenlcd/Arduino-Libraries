/*
 * Motor.h
 * Kyle Isom <isomk@kyleisom.net>
 *
 * A simple motor abstraction for use in the DiffDrive class.
 *
 */
 
#include "Motor.h"

Motor::Motor() { }

void Motor::forward() {
    digitalWrite(pinA, left_forward ? HIGH : LOW);
    digitalWrite(pinB, left_forward ? LOW : HIGH);
}

void Motor::backward() {
    digitalWrite(pinA, left_forward ? LOW : HIGH);
    digitalWrite(pinB, left_forward ? HIGH : LOW);
}

void Motor::stop() {
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
}

void Motor::setEnable(int enablePin) {
    if ( enablePin == 0 ) {
        enPin == -1;
        vcc_tied = true;
    }
    
    else {
        enPin = enablePin;
        vcc_tied = false;
    }
    
    pinMode(pinA, OUTPUT);
    pinMode(pinB, OUTPUT);
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
}

void Motor::enable() {
    if (vcc_tied) { return; }
    else { digitalWrite(enPin, HIGH); }
    return;
}

void Motor::disable() {
    if (vcc_tied) { return; }
    else { digitalWrite(enPin, LOW); }
    return; 
}
        
