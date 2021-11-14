//ALib0-MultipleTasks5.ino
/* Demonstrates concurrent tasks with ALib0.
   Blink three LEDS asynchronously.
   (See Async3.jpg)
*/

#include <ALib0.h>

//LED pins
const int BLUE_LED = D1;    //Pin assignments for a Wemos D1 Mini
const int YELLOW_LED = D2;
const int GREEN_LED = D3;

#define ON true             //assume LED Cathode to Gnd
#define OFF !ON


void setup() {
  pinMode(BLUE_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  digitalWrite(BLUE_LED, OFF);
  digitalWrite(YELLOW_LED, OFF);
  digitalWrite(GREEN_LED, OFF);
}

void blue() {
  taskBegin();
  //Blue on for 500ms, then off for 2500ms.
  digitalWrite(BLUE_LED, ON);
  taskDelay(500);
  digitalWrite(BLUE_LED, OFF);
  taskDelay(2500);
  taskEnd();
}

void green() {
  taskBegin();
  //Green on for 1000ms, then off for 5000ms.
  digitalWrite(GREEN_LED, ON);
  taskDelay(1000);
  digitalWrite(GREEN_LED, OFF);
  taskDelay(500);
  taskEnd();
}

void yellow() {
  taskBegin();
  //Yellow on for 5000ms, then off for 1000ms.
  digitalWrite(YELLOW_LED, ON);
  taskDelay(5000);
  digitalWrite(YELLOW_LED, OFF);
  taskDelay(1000);
  taskEnd();
}


void loop() {
  blue();
  green();
  yellow();
}
