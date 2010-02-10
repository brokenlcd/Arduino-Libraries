ARDUINO THUMBSTICK LIBRARY
Written by Kyle Isom <isomk@kyleisom.net>

Version 1.0
2010 FEB 09 0322 MST

The library was written using the Sparkfun breakout board as a reference for
which axis was horizontal and which was vertical, as well as which direction
was up and which was down. Essentially, the code assumes the following 
orientation of the thumbstick:

                 TOP
             ___________
      / \   |           |  R
    V  |    | P         |  I
    E  |    | O         |  G
    R  |    | T  POT    |  H
    T \ /   |___________|  T
        
           <- HORIZONTAL ->
    

For beginners:
Wiring the thumbstick to the Arduino is very easy: the select pin (for the
pushbutton) goes to a digital pin, while the middle pin on the two 
potentiometers (aka the vertical and horizontal pins) go to two analog pins.
The code defaults to the select button being on digital pin 2, the horizontal
axis being on analog pin 0, and the vertical axis being on analog pin 1. 

For more advanced users:           
The code uses an internal pullup for the select button, so no external pullup is
required. See the header file for important information should you choose to
use an external pullup. The select button is also debounced already, but
expects you to be periodically polling for inputs. See the next section for 
more information.
           


USING THE THUMBSTICK LIBRARY:

Make sure to include the library:
    #include <ThumbStick.h>

First, you need to declare a ThumbStick using one of the four constructors:

    ThumbStick(int HorizPin, int VertPin, int SelectPin);
    ThumbStick(int HorizPin, int VertPin);
    ThumbStick(int MapLow, int MapHigh, int HorizPin, int VertPin, int SelectPin);
    ThumbStick();

    Example:
    ThumbStick joystickA(2, 3, 13);
    
    This creates an object joystickA plugged into analog pins 2 and 3 with
    the digital pin on pin 13.
    
The variables you will need to use:
    HorizPin:   the pin the horizontal axis is plugged into (analog)
    VertPin:    the pin the vertical axis is plugged into (analog)
    SelectPin:  the pin the select button is plugged into (digital)
    MapHigh:    the value you want to use for the maximum value (i.e. all the
                way up or to the left). The default is 512.
    MapLow:     the value you want to use for the minimum value (i.e. all the
                way down or to the right). The default is -512.

A quick explanation of the map values: analog inputs range from 0 to 1023. This
means typical analog inputs center around 512. However, for convenience, the 
library uses a center value of 0.

In your setup() function, you should call the calibrate() function before using
the thumbstick:

    void setup() {
        // other code
        joystickA.calibrate();
    }

    
The functions available are:
    int getH(void); 
    int getV(void);

    int getMapLow(void) { return map_low; }
    int getMapHigh(void) { return map_high; }
    int getCenter(void) { return ( (map_low + map_high) / 2); }
    
    boolean isLeft(void) { return (getH() > getCenter() ? true : false); }
    boolean isRight(void) { return (getH() < getCenter() ? true : false); }
    boolean isUp(void) { return (getV() > getCenter() ? true : false); }
    boolean isDown(void) { return (getV() < getCenter() ? true : false); }
    boolean isPressed(void);

    getH() and getV() will return a value between MapLow and MapHigh. If you're
    using the thumbstick for a throttle, steering, or a similar use, you can
    pass this value to your filter or use it as is. The constrain() function
    is used on the return value, so the value is guaranteed to be in this range.
    
    If you are unsure of what MapLow and MapHigh are, or would like to use them
    in your code, there are the accessors getMapLow and getMapHigh; similarly,
    getCenter() will return the midpoint i.e. centered value. The calibrate()
    function will use this as the center point to calibrate the joystick to.
    
    If you want to check if the button is pressed, you can check isPressed() -
    it should be used by polling rather than a blocking wait. If you want to use
    a blocking wait then you must do something similar to:
    
        while (!(isPressed())) {
            delay(40);      // delay for debounce period
        }
    
    The boolean direction functions use the orientation used at the top of the
    header. These can be used for menu navigation usages.
    
If you have any questions or comments about the code (feedback is welcome),
send an email to brokenlcd@gmail.com or isomk@kyleisom.net.
