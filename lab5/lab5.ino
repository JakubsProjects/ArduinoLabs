int lightPin = 0;  //define a pin for Photo resistor
int lightPin2 = 1;
int ledPin=11;     //define a pin for LED
#include <LiquidCrystal.h>

//Jakub 

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
int LED1 = 7;
int LED2 = 8;
int LED3 = 9;
int LED4 = 10;


int buzzer = 6;
int var;


LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int value;
int value2;

void setup()
{
    Serial.begin(9600);  //Begin serial communcation
     pinMode( ledPin, OUTPUT );


  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
 // lcd.print("Jakub Glebocki");
}

void loop()
{
        
        value = analogRead(lightPin);
        value2= analogRead(lightPin2);
       
        if(value2 <= 200){
          tone(buzzer, 200);
        }
        else if(value2 > 201 && value2 < 400){
           tone(buzzer, 700);
        }
        else if(value2 > 400 && value2 < 600){
           tone(buzzer, 1500);
        }
        else if(value2 >= 700){
          tone(buzzer, 3000);
        }
        
        if(value <= 200){
          digitalWrite(LED1, HIGH);
          digitalWrite(LED2, HIGH);
          digitalWrite(LED3, HIGH);
          digitalWrite(LED4, HIGH); 
        }
        
        else if(value > 201 && value <400){
          digitalWrite(LED1, HIGH);
          digitalWrite(LED2, HIGH);
          digitalWrite(LED3, HIGH);
          digitalWrite(LED4, LOW);
        }
         else if(value > 400 && value < 600){
          digitalWrite(LED1, HIGH);
          digitalWrite(LED2, HIGH);
          digitalWrite(LED3, LOW);
          digitalWrite(LED4, LOW);
        }
        else if(value > 600 && value < 800){
          digitalWrite(LED1, HIGH);
          digitalWrite(LED2, LOW);
          digitalWrite(LED3, LOW);
          digitalWrite(LED4, LOW);
        }
        else{
          digitalWrite(LED1, LOW);
          digitalWrite(LED2, LOW);
          digitalWrite(LED3, LOW);
          digitalWrite(LED4, LOW);
        }
                                                //you have  to divide the value. for example, 
                                                //with a 10k resistor divide the value by 2, for 100k resistor divide by 4.
   delay(500); //short delay for faster response to light.
}
