#include <Keyboard.h>

// constants won't change. They're used here to set pin numbers:
const int dir1 = 7;
const int dir2 = 9;
const int dir3 = 10;
const int dir4 = 11;

const int button1 = 0;
const int button2 = 1;
const int button3 = 2;
const int button4 = 3;

//const int ledPin =  LED_BUILTIN;      // the number of the LED pin

// These are the debounce variables for the joystick
// jcs = joystick current state
// jps = joystick previous state
// bcs = button current state
// bps = button previous state
//joystick
int jcs1 = 0;
int jcs2 = 0;
int jcs3 = 0;
int jcs4 = 0;

int jps1 = 0;
int jps2 = 0;
int jps3 = 0;
int jps4 = 0;
//buttons
int bcs1 = 0;
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

  //using internal pullup resistors to cut down on parts!
  // initialize the joystick input pins:
  pinMode(dir1, INPUT_PULLUP);
  pinMode(dir2, INPUT_PULLUP);
  pinMode(dir3, INPUT_PULLUP);
  pinMode(dir4, INPUT_PULLUP);
  //digitalWrite(ledPin, LOW);

  //initialize the button input pins
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);

  Keyboard.begin();
}

void loop() {

    // read the state of the pushbutton value:
    jcs1 = digitalRead(dir1);
    jcs2 = digitalRead(dir2);
    jcs3 = digitalRead(dir3);
    jcs4 = digitalRead(dir4);

    bcs1 = digitalRead(button1);
    bcs2 = digitalRead(button2);
    bcs3 = digitalRead(button3);
    bcs4 = digitalRead(button4);

    if( (millis() - lastDebounceTime) > debounceDelay){
      //check if the joystick input changed
      //note that these are flipped because we are pulling out digital pins high and testing if they drop low

      //right
      if(jcs1 == 0){
          Keyboard.press('a');
      } else if (jcs1 == 1){
          Keyboard.release('a');
      }
      //left
      if(jcs2 == 0){
          Keyboard.press('d');
      } else if (jcs2 == 1){
          Keyboard.release('d');
      }
      //down
      if(jcs3 == 0){
          Keyboard.press('s');
      } else if (jcs3 == 1){
          Keyboard.release('s');
      }
      //up
      if(jcs4 == 0){
          Keyboard.press('w');
      } else if (jcs4 == 1){
          Keyboard.release('w');
      }

      //check if the button input changed
      //pinky button
      if(bcs1 == 0){
          Keyboard.press('q');
      } else if (bcs1 == 1){
          Keyboard.release('q');
      }
      //ring finger button
      if(bcs2 == 0){
          Keyboard.press('x');
      } else if (bcs2 == 1){
          Keyboard.release('x');
      }
      //middle finger
      if(bcs3 == 0){
          Keyboard.press(KEY_LEFT_SHIFT);
      } else if (bcs3 == 1){
          Keyboard.release(KEY_LEFT_SHIFT);
      }
      //pointer finger button
      if(bcs4 == 0){
          Keyboard.press('z');
      } else if (bcs4 == 1){
          Keyboard.release('z');
      }
//lshift, is focus move, z is shoot, x is bomb

      lastDebounceTime = millis();

      //save current state to the previous state since the next thing we do is read a new current state
      jps1 = jcs1;
      jps2 = jcs2;
      jps3 = jcs3;
      jps4 = jcs4;

      bps1 = bcs1;
      bps2 = bcs2;
      bps3 = bcs3;
      bps4 = bcs4;
    }
}
