#include <ThumbStick.h>

// initialize new joystick using analog pins 0 and 1
ThumbStick joystick(0, 1, 2);

void setup() { 
  Serial.begin(9600);

  // joystick has to be calibrated before use  
  joystick.calibrate();
}

void loop() { 

  // every second, print the position of the joystick
  if ( (millis() % 1000) == 0 ) {
    Serial.print("H: ");
    Serial.println(joystick.getH());
    Serial.print("V: ");
    Serial.println(joystick.getV());
    Serial.print("MAP (LOW / CENTER / HIGH): ");
    Serial.print(joystick.getMapLow());
    Serial.print(" / ");
    Serial.print(joystick.getCenter());
    Serial.print(" / ");
    Serial.println(joystick.getMapHigh());
  }

    // This shows that the joystick can be in both a horizontal and
    // vertical direction at once.
    if ( joystick.isLeft() ) { Serial.println("Left"); }
    else if ( joystick.isRight() ) { Serial.println("Right"); }
    
    if ( joystick.isUp() ) { Serial.println("Up"); }
    else if ( joystick.isDown() ) { Serial.println("Down"); }
    
    if ( joystick.isPressed() ) { Serial.println("Button pressed"); }
} 
