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

void greenlightblick(){
  
}
void redlightblick(){
       digitalWrite(ledpin2,HIGH);
       delay(100);
       digitalWrite(ledpin2,LOW); 
}
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
void passwordsuccess(){
        digitalWrite(ledpin,HIGH);
        myservo.write(180);
        delay(2250);
        digitalWrite(ledpin,LOW);
        myservo.write(90);
       // limiter=0;
        correct=-1;
}
int passwordcheck(String input){
  if(combo==inputcombo){
    inputcombo="aaaa";
    return correct=1;
  }
  inputcombo="aaaa";
  return correct=0;
}
void soundthing(){
    digitalWrite(speaker, HIGH);
    delay(50);
    digitalWrite(speaker, LOW);
}
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
