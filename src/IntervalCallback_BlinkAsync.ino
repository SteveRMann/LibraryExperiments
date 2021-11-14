/*
   IntervalCallback_BlinkAsync.ino
*/

#include "IntervalCallback.h"
//Prototypes (required)
void yellow_OFF();
void yellow_ON();
void blue_OFF();
void blue_ON();
void green_OFF();
void green_ON();

IntervalCallback yellowLED_onTime(5000, yellow_OFF);  // Turn off Yellow LED after this interval
IntervalCallback yellowLED_offTime(1000, yellow_ON);
IntervalCallback blueLED_onTime(500, blue_OFF);
IntervalCallback blueLED_offTime(2500, blue_ON);
IntervalCallback greenLED_onTime(1000, green_OFF);
IntervalCallback greenLED_offTime(5000, green_ON);


const int LED_ON = 1;
const int LED_OFF = 0;
const int LED_BLUE_pin = D1;
const int LED_YELLOW_pin = D2;
const int LED_GREEN_pin = D3;

void setup() {
  pinMode(LED_BLUE_pin, OUTPUT);
  pinMode(LED_YELLOW_pin, OUTPUT);
  pinMode(LED_GREEN_pin, OUTPUT);

  //Start the LED timers
  digitalWrite(LED_BLUE_pin, LED_ON);
  digitalWrite(LED_YELLOW_pin, LED_ON);
  digitalWrite(LED_GREEN_pin, LED_ON);
  blueLED_onTime.start();
  yellowLED_onTime.start();
  greenLED_onTime.start();
}

void loop() {
  yellowLED_onTime.loop();
  yellowLED_offTime.loop();
  blueLED_onTime.loop();
  blueLED_offTime.loop();
  greenLED_onTime.loop();
  greenLED_offTime.loop();
}

void yellow_ON() {
  //Turn on the YELLOW LED, stop the OFF timer then start the ON timer.
  digitalWrite(LED_YELLOW_pin, LED_ON);     //Turn on the yellow LED
  yellowLED_offTime.stop();                 //Stop the OFF timer
  yellowLED_onTime.start();                 //Start the ON timer
}

void yellow_OFF() {
  //Turn off the YELLOW LED, stop the ON timer then start the OFF timer.
  digitalWrite(LED_YELLOW_pin, LED_OFF);    //Turn off the yellow LED
  yellowLED_onTime.stop();                  //Stop the ON timer
  yellowLED_offTime.start();                //Start the OFF timer
}

void blue_ON() {
  //Turn on the BLUE LED, stop the OFF timer then start the ON timer.
  digitalWrite(LED_BLUE_pin, LED_ON);     //Turn on the blue LED
  blueLED_offTime.stop();                 //Stop the OFF timer
  blueLED_onTime.start();                 //Start the ON timer
}

void blue_OFF() {
  //Turn off the BLUE LED, stop the ON timer then start the OFF timer.
  digitalWrite(LED_BLUE_pin, LED_OFF);    //Turn off the blue LED
  blueLED_onTime.stop();                  //Stop the ON timer
  blueLED_offTime.start();                //Start the OFF timer
}

void green_ON() {
  //Turn on the GREEN LED, stop the OFF timer then start the ON timer.
  digitalWrite(LED_GREEN_pin, LED_ON);     //Turn on the green LED
  greenLED_offTime.stop();                 //Stop the OFF timer
  greenLED_onTime.start();                 //Start the ON timer
}

void green_OFF() {
  //Turn off the GREEN LED, stop the ON timer then start the OFF timer.
  digitalWrite(LED_GREEN_pin, LED_OFF);    //Turn off the green LED
  greenLED_onTime.stop();                  //Stop the ON timer
  greenLED_offTime.start();                //Start the OFF timer
}
