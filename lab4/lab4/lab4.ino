int lightPin = 0;  //define a pin for Photo resistor
int ledPin=11;     //define a pin for LED
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int value;
void setup()
{
    Serial.begin(9600);  //Begin serial communcation
    pinMode( ledPin, OUTPUT );

    lcd.begin(16, 2);
  
  //Set the cursor
  //lcd.setCursor(0,0);
  // Print a message to the LCD.
  
 // lcd.print("Jakub Glebocki");
}

void loop()
{
  
   lcd.setCursor(0, 0);
  
   // Serial.println(analogRead(lightPin)); //Write the value of the photoresistor to the serial monitor.
    //analogWrite(ledPin, analogRead(lightPin)/4);  //send the value to the ledPin. Depending on value of resistor 
        
        value = analogRead(A0);

        if(value <= 200){
          lcd.clear();
         lcd.print("dark");
          
        }
        else if(value > 201 && value <400){
          lcd.clear();
           lcd.print("partially dark ");
        }
         else if(value > 400 && value < 600){
          lcd.clear();
           lcd.print("medium");
        }
        else if(value > 600 && value < 800){
          lcd.clear();
           lcd.print("partially light");
        }
        else{
          lcd.clear();
          lcd.print("fully lit");
        }
        //Serial.println("value: " + value);
                                                //you have  to divide the value. for example, 
                                                //with a 10k resistor divide the value by 2, for 100k resistor divide by 4.
   delay(10); //short delay for faster response to light.
}
