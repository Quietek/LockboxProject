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
#define ledpin 12
#define ledpin2 13
String combo="1234";
int i=0;
int limiter=0;
char key;


void setup()
{
  pinMode(ledpin,OUTPUT);
  pinMode(ledpin2,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  key=keypad.getKey();
  if(key)
  {
    if(key==combo[i]&&limiter==i){
      i++;
      limiter++;
      if(i>3&&limiter>3){
        digitalWrite(ledpin,HIGH);
        delay(1000);
        digitalWrite(ledpin,LOW);
        i=0;
        limiter=0;
      }
    } 
    else{
      limiter++;
      if(limiter>3){
       digitalWrite(ledpin2,HIGH);
       delay(1000);
       digitalWrite(ledpin2,LOW);  
       i=0;
       limiter=0;
      }  
    }
  }
}
