/*
 * ThumbStick_LCD
 * ThumbStick example using LCD
 */
 

#include <ThumbStick.h>
#include <LiquidCrystal.h>

// initialize new joystick using analog pins 0 and 1
ThumbStick joystick(0, 1);

// set up our LCD
LiquidCrystal lcd(8, 7, 3, 4, 5, 6);

void setup() { 
  lcd.begin(16, 2);

  // joystick has to be calibrated before use  
  joystick.calibrate();
}

void loop() { 

  // every second, print the position of the joystick
  if ( (millis() % 1000) == 0 ) {
    lcd.clear();
    lcd.home();
    lcd.print("H: ");
    lcd.print(joystick.getH());
    lcd.setCursor(0, 1);
    lcd.print("V: ");
    lcd.print(joystick.getV());
  }
} 
