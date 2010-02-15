/*
 * ThumbStick.cpp
 * Kyle Isom <brokenlcd@gmail.com>
 *
 * Arduino library to abstract use of the thumb joystick sold on Sparkfun.
 * The vertical and horizontal axis are indicated on the breakout board.
 *
 * Released under a BSD license. The full header is available in the header.
 */


#include "ThumbStick.h"



/****************
 * CONSTRUCTORS *
 ****************/

ThumbStick::ThumbStick(int HorizPin, int VertPin, int SelectPin) {
    hpin = HorizPin;
    vpin = VertPin;
    spin = SelectPin;
    hcen = 0;
    vcen = 0;
    map_high = DEFAULT_MAP_HIGH;
    map_low = DEFAULT_MAP_LOW;
    sel_last_state = SWITCH_STATE_NOTPRESSED;
    _setup();
    calibrate();
}
        
ThumbStick::ThumbStick(int HorizPin, int VertPin) {
    hpin = HorizPin;
    vpin = VertPin;
    spin = -1;
    hcen = 0;
    vcen = 0;
    map_high = DEFAULT_MAP_HIGH;
    map_low = DEFAULT_MAP_LOW;
    sel_last_state = SWITCH_STATE_NOTPRESSED;
    _setup();
    calibrate();
}
        
ThumbStick::ThumbStick(int MapLow, int MapHigh, int HorizPin, int VertPin, int SelectPin) {
    hpin = HorizPin;
    vpin = VertPin;
    spin = SelectPin;
    hcen = 0;
    vcen = 0;
    map_high = MapHigh;
    map_low = MapLow;
    sel_last_state = SWITCH_STATE_NOTPRESSED;
    _setup();
    calibrate();
}
    

ThumbStick::ThumbStick(void) {
    hpin = DEFAULT_HORIZ_PIN;
    vpin = DEFAULT_VERT_PIN;
    spin = DEFAULT_SEL_PIN;
    map_high = DEFAULT_MAP_HIGH;
    map_low = DEFAULT_MAP_LOW;
    hcen = 0;
    vcen = 0;
    sel_last_state = SWITCH_STATE_NOTPRESSED;
    _setup();
    calibrate();
}

void ThumbStick::_setup() {
   
    hcen = 0;
    vcen = 0;
    
    
    if ( spin != -1 ) { 
        pinMode(spin, INPUT); 
        digitalWrite(spin, HIGH);   // use internal pullup
    }
    return;
}

void ThumbStick::calibrate() {
    hcen = 0;
    vcen = 0;
    hcen = map(analogRead(hpin), analogLow, analogHigh, map_low, map_high);
    vcen = map(analogRead(vpin), analogLow, analogHigh, map_low, map_high);
    return;
} 

int ThumbStick::getH(void) { 
  int H = analogRead(hpin) - hcen;
  H = map(H, analogLow - hcen, analogHigh + hcen, map_low, map_high);
  return constrain(H, map_low, map_high);
}

int ThumbStick::getV(void) { 
  int V = analogRead(vpin) - vcen;
  V = map(V, analogLow - vcen, analogHigh + vcen, map_low, map_high);
  return constrain(V, map_low, map_high);
}

boolean ThumbStick::isPressed() {
    if ( spin == -1 ) { return false; }
    
    int currentState = digitalRead(spin);
    
    if ( currentState != sel_last_state ) {
        sel_last_debounce = millis();
        sel_last_state = currentState;
        return false;
    }
    
    if ( currentState == SWITCH_STATE_PRESSED ) {
        if ( ( millis() - sel_last_debounce ) > DEBOUNCE_DELAY ) {
            return true;
            sel_last_debounce = millis();
        }
        
        return false;
    }

    return false;
}
