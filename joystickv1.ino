#include <Keyboard.h>

// constants won't change. They're used here to set pin numbers:
const int dir1 = 2;
const int dir2 = 3;
const int dir3 = 4;
const int dir4 = 5;

const int shoot = 6;
const int shift = 7;
const int bomb = 8;

//const int ledPin =  LED_BUILTIN;      // the number of the LED pin

// variables will change:
int bcs1 = 0;         // variable for reading the pushbutton status
int bcs2 = 0;
int bcs3 = 0;
int bcs4 = 0;

int bps1 = 0;
int bps2 = 0;
int bps3 = 0;
int bps4 = 0;

long lastDebounceTime = 0;
long debounceDelay = 50; //extend if input flickers

void setup() {

  // initialize the pushbutton pin as an input:
  pinMode(dir1, INPUT);
  pinMode(dir2, INPUT);
  pinMode(dir3, INPUT);
  pinMode(dir4, INPUT);
  //digitalWrite(ledPin, LOW);



  Keyboard.begin();
}

void loop() {

    // read the state of the pushbutton value:
    bcs1 = digitalRead(dir1);
    bcs2 = digitalRead(dir2);
    bcs3 = digitalRead(dir3);
    bcs4 = digitalRead(dir4);

    if( (millis() - lastDebounceTime) > debounceDelay){

      if(bcs1 == 1){
          Keyboard.press('s');
      } else if (bcs1 == 0){
          Keyboard.release('s');
      }

      if(bcs2 == 1){
          Keyboard.press('w');
      } else if (bcs2 == 0){
          Keyboard.release('w');
      }

      if(bcs3 == 1){
          Keyboard.press('d');
      } else if (bcs3 == 0){
          Keyboard.release('d');
      }

      if(bcs4 == 1){
          Keyboard.press('a');
      } else if (bcs4 == 0){
          Keyboard.release('a');
      }

      /*
      else if (bcs2 != bps2){
          Serial.println("Down Toggle!");
      } else if (bcs3 != bps3){
          Serial.println("Left Toggle!");
      } else if (bcs4 != bps4){
          Serial.println("Right Toggle!");
      }*/

      lastDebounceTime = millis();

      bps1 = bcs1;
      bps2 = bcs2;
      bps3 = bcs3;
      bps4 = bcs4;
    }
}
