/*
 * pushbutton.h
 * Kyle Isom <isomk@kyleisom.net>
 *
 * Quick arduino library for momentary pushbuttons including debouncing and
 * using internal resistors.
 */
 
 #include "pushbutton.h"
 
 pushbutton::pushbutton(int new_pin, int new_active_state) {
     pin = new_pin;
     active_state = new_active_state;
     last_state = !active_state;
     pinMode(pin, INPUT);
     digitalWrite(pin, HIGH);
 }
 
 boolean pushbutton::isPressed() {
      int current_state = digitalRead(pin);
    
    if ( current_state != last_state ) {
        last_debounce = millis();
        last_state = current_state;
        return false;
    }
    
    if ( current_state == active_state ) {
        if ( ( millis() - last_debounce ) > DEBOUNCE_DELAY ) {
            return true;
            last_debounce = millis();
        }
        
        return false;
    }

    return false;
}

