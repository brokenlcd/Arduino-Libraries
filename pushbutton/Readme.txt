ARDUINO PUSHBUTTON LIBRARY
Written by Kyle Isom <isomk@kyleisom.net>

Version 1.0
2010 FEB 16 2000 MST

.:[ INTRO / HARDWARE INTERFACE ]:.
This is a library to interface with a standard pushbutton. Wiring is pretty
simple: for an active low switch, wire the pushbutton so one leg is wired to
ground and wire a connection between the other leg and a digital pin on the
arduino. The library uses an internal pull up so an external pull up is not 
required in this case.

.:[ USING THE LIBRARY ]:.
Declare a new instance:

    pushbutton myButton(int pin, int active_state);

Here, pin is the digital pin the pushbutton is connected to, and active_state
is the state of the switch when pressed. In our wiring example before, it would
be LOW. If the pushbutton is connected to digital pin 2, it would be 
instantiated as

    pushbutton myButton(2, LOW);
    
Checking the state of the button is done with the function

    myButton.isPressed();

This function is non-blocking and employs debouncing (by default with a 40 ms
debounce delay, modifiable in the header). It will return true if the button has
been pressed and false otherwise.

Questions and feedback may be sent to isomk@kyleisom.net or brokenlcd@gmail.com.


