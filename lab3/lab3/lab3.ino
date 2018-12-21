//Jakub Glebocki
// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

int position1 = 0;

String myquote = "Knowledge comes, but wisdom lingers";


LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  //Set the cursor
  lcd.setCursor(0,0);
  // Print a message to the LCD.
  
  lcd.print("Jakub Glebocki");
}

void loop() {
  // set the cursor to column 0, line 1
  //lcd.setCursor(0, 1);
  // lcd.print("Hi this is the best freaking lab ever!!");
  
  lcd.setCursor(0, 1);

  int posCopy = position1;
  int i = 0;

  while(i < 16)
  {
    lcd.print(myquote[posCopy]);
    posCopy = posCopy + 1;
    i++;
  }
  
  position1 = (position1 + 1) % myquote.length();

  if (position1 == 20)
  {
    position1 = 0;
  }
  
  delay(300);

  /*
     for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
      // scroll one position left:
      lcd.scrollDisplayLeft();
      // wait a bit:
      delay(500);

    }
  */
}
