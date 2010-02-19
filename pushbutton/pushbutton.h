/*
 * pushbutton.h
 * Kyle Isom <isomk@kyleisom.net>
 *
 * Quick arduino library for momentary pushbuttons including debouncing and
 * using internal resistors.
 */
 
 #include "WProgram.h"
 
 
 // debounce time in milliseconds
 #define DEBOUNCE_DELAY           40
 
 class pushbutton {
    public:
        pushbutton(int new_pin, int new_active_state = HIGH);
        boolean isPressed(void);
        
    private:
        int pin;
        int active_state;
        int last_state, current_state;
        int last_debounce;
     
 };
