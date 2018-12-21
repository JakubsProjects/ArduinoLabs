
//Eric and Jakub 
//Lab 7 partner program

int ledPin = 12;
int buttonPin = 13;

int buttonState = LOW;
int PrevButton = LOW;
int readInfo = LOW;

bool toggleLEDS = false;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

}

void loop() {

  buttonState = digitalRead(buttonPin);

  if (Serial.read() == HIGH) {
    readInfo = HIGH;
  }
  else {
    readInfo = LOW;
  }

  if (buttonState == PrevButton) {
    //DO NOTHING AT ALL
  }

  else if (buttonState == HIGH) {
    Serial.write(HIGH);
  }


  if (readInfo == HIGH) {
    toggleLEDS = !toggleLEDS;
  }

  if (toggleLEDS == false) {
    digitalWrite(ledPin, LOW);
  }
  else if(toggleLEDS == true){
    digitalWrite(ledPin, HIGH);
  }
  PrevButton = buttonState;


}
