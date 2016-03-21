#include <Servo.h>
#include <Key.h>
#include <Keypad.h>
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {8, 7, 6, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {4, 3, 2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
#define speaker 9
#define ledpin 12
#define ledpin2 13
String combo="1234";
int i=0;
int limiter=0;
char key;
Servo myservo;
bool correct;

void passwordfailure(){
       digitalWrite(ledpin2,HIGH);
       delay(100);
       digitalWrite(ledpin2,LOW); 
       delay(100);
       digitalWrite(ledpin2, HIGH); 
       delay(100);
       digitalWrite(ledpin2, LOW);
       delay(100);
       digitalWrite(ledpin2, HIGH);
       delay(100);
       digitalWrite(ledpin2, LOW);
       i=0;
       limiter=0;
}
void passwordsuccess(){
        digitalWrite(ledpin,HIGH);
        myservo.write(180);
        delay(2250);
        digitalWrite(ledpin,LOW);
        myservo.write(90);
        i=0;
        limiter=0;
}
void passwordlogic(){
  key=keypad.getKey();
  if(key)  
  {
    digitalWrite(speaker, HIGH);
    delay(50);
    digitalWrite(speaker, LOW);
    
    if(key==combo[i]&&limiter==i){
      i++;
      limiter++;
      if(i>3&&limiter>3){
        correct=1;
      }
    } 
    else{
      limiter++;
      if(limiter>3){
        correct=0;
      }  
    }
  }
}
void setup()
{
  pinMode(speaker,OUTPUT);
  pinMode(ledpin,OUTPUT);
  pinMode(ledpin2,OUTPUT);
  Serial.begin(9600);
  myservo.attach(11);
}

void loop()
{
  passwordlogic();
  if(correct==1){
    passwordsuccess();
  }
  else{
    passwordfailure();
  }
}
