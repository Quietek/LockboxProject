/*! \file keypadwithchangepassword.ino

 */
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
String inputcombo="aaaa";
//int limiter=0;
char key;
Servo myservo;
bool correct;
bool passwordchange=false;


//! A function.
/!
 function used to indicate a wrong password was implemented, having a red LED flash several times
*/
void passwordfailure(){ 
       digitalWrite(ledpin2,HIGH);
       delay(100);
       digitalWrite(ledpin2,LOW);
       delay(100);
       digitalWrite(ledpin2,HIGH);
       delay(100);
       digitalWrite(ledpin2,LOW);
       delay(100);
       digitalWrite(ledpin2,HIGH);
       delay(100);
       digitalWrite(ledpin2,LOW);
      // limiter=0;
       correct=-1;
       passwordchange=false;
}
//! Function used to indicate a correct password was received
void passwordsuccess(){ 
        digitalWrite(ledpin,HIGH);
        myservo.write(180);
        delay(2250);
        digitalWrite(ledpin,LOW);
        myservo.write(90);
       // limiter=0;
        correct=-1;
}

//!checks if the inputted the password is the correct password
int passwordcheck(String input){
  if(combo==inputcombo){
    inputcombo="aaaa";
    return correct=1;
  }
  inputcombo="aaaa";
  return correct=0;
}

//!used to play a sound from a speaker to indicate a keypress was received
void soundthing(){
    digitalWrite(speaker, HIGH);
    delay(50);
    digitalWrite(speaker, LOW);
}
//!used to get user input for a combo to be compared to the password on the arduino
String password(){
  int i=0;
  while(true){
    key=keypad.getKey();
    if(key=='#'){
      passwordchange=1;  
    }
    if(key && key!= '#'){
     inputcombo[i]=key;
     i++;
     if(i>=4){
      return inputcombo;
     }
    }
  }
}
//!used to reset and change the password on the arduino
String newpassword(){
  digitalWrite(ledpin2,HIGH);
  digitalWrite(ledpin,HIGH);
  delay(200);
  digitalWrite(ledpin2,LOW);
  digitalWrite(ledpin,LOW);
  int i=0;  
  while(true){
    key=keypad.getKey();
    if(key && key!='*'&& key!='#'){
      combo[i]= key;
      i++;
      if(i>=4){
        passwordchange=false;
        return combo;  
      }
    }
  }
}

//!setup for servo and LEDs
void setup()
{
  pinMode(speaker,OUTPUT);
  pinMode(ledpin,OUTPUT);
  pinMode(ledpin2,OUTPUT);
  Serial.begin(9600);
  myservo.attach(11);
}
//!loop used to loop through password checks and different functions
void loop()
{
  password();
  passwordcheck(inputcombo);
  if(correct==1){
    passwordsuccess();
    if(passwordchange){
      newpassword();
    }
  }
  else{
    passwordfailure();
  }
}

