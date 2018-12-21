//Jakub 

// include the library code:
#include <LiquidCrystal.h>
#include <TimeLib.h>
#include <Time.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

int validinput = 0;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//String input;

int month1 = 0;
int day1 = 0;
int year1 = 0;

int hour1 = 0;
int minute1 = 0;
int seconds1 = 0;

void setup() {
  lcd.begin(16, 2);

  Serial.begin(9600);

  Serial.println("Enter time and Date");


}


void loop() {
  
  //Set the cursor
  lcd.setCursor(0, 0);
  // Print a message to the LCD.

  lcd.print("Date:");

  lcd.setCursor(0, 1);
  lcd.print("Time:");

  if (Serial.available() > 0) {


    hour1 = Serial.parseInt();
    minute1 = Serial.parseInt();
    seconds1 = Serial.parseInt();
    //lcd.print(month + day + year);
    //Serial.println(month + day + year);
    
    month1 = Serial.parseInt();
    day1 = Serial.parseInt();
    year1 = Serial.parseInt();

    if (hour1 <= 23 && hour1 != 0 &&  minute1 <= 59 && seconds1 <= 59 && month1 <= 12 && month1 != 0 && day1 <= 31 && day1 != 0 && year1 <= 9999 && day1 != 0) {
      setTime(hour1, minute1, seconds1, day1, month1, year1);
      validinput = 1;
    }
  }

  if (validinput == 1) {
    time_t t = now();
    lcd.setCursor(5, 1);
    // Serial.print("hour ");

    lcd.print(hour(t));
    lcd.print(":");
    lcd.print( minute(t));
    lcd.print(":");
    lcd.print(second(t));

    lcd.setCursor(5, 0);

    lcd.print(month(t));
    lcd.print("/");
    lcd.print( day(t));
    lcd.print("/");
    lcd.print(year(t));

    delay(1000);

    lcd.clear();
  }
}
