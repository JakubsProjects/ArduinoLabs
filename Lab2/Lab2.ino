//Jakub 
//Lab2
//WHEN COUNTER HITS 7, my code resets it back to 0, so the user can do it again. When counter hits 0 and you decerement it, then i reset the counter back to 0, to prevent errors or weird non-working bugs

int LED1 = 12;
int LED2 = 11;
int LED3 = 10;

int switchPin2 = 2; 
int switchPin4 = 4; 
int val;
int val2;

int counter = 0;
int flag = 0;
int flag2 = flag;

int decimaltoBin(){
  int counter2 = counter;
  int remainder; 
  int BinNum = 0;
  int a = 1;
  
    while(counter2 != 0) {
      
        remainder = counter2 % 2;
        
        counter2 = counter2 / 2;
        
        BinNum= BinNum + (remainder * a);
        
        a = a*10;
    }
   //Serial.println(binary);
    return BinNum;
  
}


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
 // pinMode(LED_BUILTIN, OUTPUT);
  
  Serial.begin(9600);           // set up Serial library at 9600 bps
  pinMode(switchPin2, INPUT);    // sets the digital pin as input to read switch

 // Serial.begin(9600);           // set up Serial library at 9600 bps
  pinMode(switchPin4, INPUT);    // sets the digital pin as input to read switch

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  
 // Serial.begin(9600);           // set up Serial library at 9600 bps
 // pinMode(switchPin4, intput);    // sets the digital pin as output to read switch
  
}

// the loop function runs over and over again forever
void loop() {

val = digitalRead(switchPin2);   // read input value and store it in val
val2 =  digitalRead(switchPin4);

if(counter > 7 || counter < 0){
  counter = 0;
}

  if (val == HIGH) 
  {
    if(flag != 1)
    {
     counter++;
      flag = 1;
    }
  }

    if (val2 == HIGH) 
    {
      if(flag2 != 1)
      {
        counter--;
        flag2 = 1;
      }
    }
    
   // val = LOW;
  

      
    if (flag == 1 || flag2 == 1){
      
    
    // check if the button is pressed
    int value = decimaltoBin();
    // Serial.print("Value ");
    //Serial.println(value);
    
    int ledlight1 = value / 100;
    //Serial.print("ledlight1 ");
    //Serial.println(ledlight1);
    
    int ledlight2 = (value /10) % 10;
//Serial.print("ledlight2 ");
   // Serial.println(ledlight2);
    
    int ledlight3 = value % 10;
  //  Serial.print("ledlight3 ");
  //  Serial.println(ledlight3);


  
    
   if(ledlight1 == HIGH){
    digitalWrite(LED1, HIGH);
   }

   else{
     digitalWrite(LED1, LOW);
   }

     if(ledlight2 == HIGH){
    digitalWrite(LED2, HIGH);
   }

   else{
     digitalWrite(LED2, LOW);
   }

     if(ledlight3 == HIGH){
    digitalWrite(LED3, HIGH);
   }

   else{
     digitalWrite(LED3, LOW);
   }
  
  if( val == LOW){
    //val = LOW;
    flag = 0;
  }

  if( val2 == LOW){
    //val = LOW;
    flag2 = 0;
  }
   Serial.print("Counteris: ");
  Serial.println(counter);
  }


  //Serial.print("Counteris: ");
  //Serial.println(counter);
 //  Serial.println(digitalRead(switchPin4));
 // delay(600);
  
 

}
