// include the library code:
#include <LiquidCrystal.h>
#include <TimeLib.h>
#include <Time.h>


//*************Jakub
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4;

int validinput = 0;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

unsigned long time;
int button1 = 2;
int button2 = 3;
int State = LOW;

int interruptbutton1;
int interruptbutton2;
int flag = 1;

void setup() {

  Serial.begin(9600);
  //intialize screen
  lcd.begin(16, 2);

  //Set cursor
  lcd.setCursor(0, 0);
  //button as inputs
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);

  //button intterupt
  interruptbutton1 = digitalPinToInterrupt(button1);
  interruptbutton2 = digitalPinToInterrupt(button2);

  //interrupt action
  attachInterrupt(interruptbutton1, statetoggle1 , CHANGE);
  attachInterrupt(interruptbutton2, statetoggle2 , CHANGE);

}

void loop() {


  // put your main code here, to run repeatedly:
  if (State == LOW) {
   
    lcd.clear();
    lcd.print("Been waiting for");
    time = time + 1;
    
    if(flag)
    {
      time = 0;
      flag = 0;
    }
    lcd.setCursor(0,1);
    lcd.print(time);
    lcd.print(" seconds");
    //flag= 0;
   
  }
  else if(State == HIGH){
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Interrupt receiv");
    lcd.setCursor(0,1);
    lcd.print("ed!Press button2");
    flag = 1;
  }

  delay(1000);
}

void statetoggle1() {
  State = HIGH;
}

void statetoggle2() {
  State = LOW;
}


