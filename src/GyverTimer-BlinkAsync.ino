/*
   GyverTimer-GTimer_BlinkAsync.ino
*/

// пример параллельной работы нескольких таймеров
// example of parallel operation of several timers

#include "GyverTimer.h"


//Create the timer objects
GTimer yellowLED_onTime(MS, 500);
GTimer yellowLED_offTime(MS, 2500);
GTimer blueLED_onTime(MS, 5000);
GTimer blueLED_offTime(MS, 1000);
GTimer greenLED_onTime(MS, 1000);
GTimer greenLED_offTime(MS, 5000);

const int LED_ON = 1;
const int LED_OFF = !LED_ON;

const int LED_BLUE_pin = D1;
const int LED_YELLOW_pin = D2;
const int LED_GREEN_pin = D3;


void setup() {
  pinMode(LED_YELLOW_pin, OUTPUT);
  pinMode(LED_BLUE_pin, OUTPUT);
  pinMode(LED_GREEN_pin, OUTPUT);

  //Stop the timers. They automatically start when the object is created
  yellowLED_onTime.stop();
  yellowLED_offTime.stop();
  blueLED_onTime.stop();
  blueLED_offTime.stop();
  greenLED_onTime.stop();
  greenLED_offTime.stop();

  //Start all timers
  digitalWrite(LED_YELLOW_pin, LED_ON);
  digitalWrite(LED_BLUE_pin, LED_ON);
  digitalWrite(LED_GREEN_pin, LED_ON);
  yellowLED_onTime.reset();
  blueLED_onTime.reset();
  greenLED_onTime.reset();
  yellowLED_onTime.start();
  blueLED_onTime.start();
  greenLED_onTime.start();
}


void loop() {
  if (yellowLED_onTime.isReady()) {
    digitalWrite(LED_YELLOW_pin, LED_OFF);    //Turn off the yellow LED
    yellowLED_onTime.stop();                  //Stop the ON timer
    yellowLED_offTime.start();                //Start he OFF timer
  }

  if (yellowLED_offTime.isReady()) {
    digitalWrite(LED_YELLOW_pin, LED_ON);     //Turn on the yellow LED
    yellowLED_offTime.stop();                 //Stop the OFF timer
    yellowLED_onTime.start();                 //Start the ON timer
  }

  if (blueLED_onTime.isReady()) {
    digitalWrite(LED_BLUE_pin, LED_OFF);    //Turn off the blue LED
    blueLED_onTime.stop();                  //Stop the ON timer
    blueLED_offTime.start();                //Start he OFF timer
  }

  if (blueLED_offTime.isReady()) {
    digitalWrite(LED_BLUE_pin, LED_ON);     //Turn on the blue LED
    blueLED_offTime.stop();                 //Stop the OFF timer
    blueLED_onTime.start();                 //Start the ON timer
  }

  if (greenLED_onTime.isReady()) {
    digitalWrite(LED_GREEN_pin, LED_OFF);    //Turn off the green LED
    greenLED_onTime.stop();                  //Stop the ON timer
    greenLED_offTime.start();                //Start he OFF timer
  }

  if (greenLED_offTime.isReady()) {
    digitalWrite(LED_GREEN_pin, LED_ON);     //Turn on the green LED
    greenLED_offTime.stop();                 //Stop the OFF timer
    greenLED_onTime.start();                 //Start the ON timer
  }
}
