/*
   neoTimer-BlinkAsync.ino
*/

#include "neotimer.h"

Neotimer yellowLED_onTime = Neotimer(5000);
Neotimer yellowLED_offTime = Neotimer(1000);
Neotimer blueLED_onTime = Neotimer(500);
Neotimer blueLED_offTime = Neotimer(2500);
Neotimer greenLED_onTime = Neotimer(1000);
Neotimer greenLED_offTime = Neotimer(5000);

const int LED_ON = 1;
const int LED_OFF = 0;

const int LED_BLUE_pin = D1;
const int LED_YELLOW_pin = D2;
const int LED_GREEN_pin = D3;


void setup() {
  pinMode(LED_BLUE_pin, OUTPUT);
  pinMode(LED_YELLOW_pin, OUTPUT);
  pinMode(LED_GREEN_pin, OUTPUT);

  //Start both LED timers
  digitalWrite(LED_BLUE_pin, LED_ON);
  digitalWrite(LED_YELLOW_pin, LED_ON);
  digitalWrite(LED_GREEN_pin, LED_ON);

  blueLED_onTime.start();
  yellowLED_onTime.start();
  greenLED_onTime.start();
}

void loop() {
  if (yellowLED_onTime.done()) {
    yellow_OFF();                    //Yellow on time expired, turn it off
  }
  if (yellowLED_offTime.done()) {
    yellow_ON();                     // Yellow off time expired, turn it on
  }

  if (blueLED_onTime.done()) {
    blue_OFF();                    //Blue on time expired, turn it off
  }
  if (blueLED_offTime.done()) {
    blue_ON();                     //Blue off time expired, turn it on
  }

  if (greenLED_onTime.done()) {
    green_OFF();                    //Green on time expired, turn it off
  }
  if (greenLED_offTime.done()) {
    green_ON();                     //Green off time expired, turn it on
  }
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
