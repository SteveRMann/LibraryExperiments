/*
   BlockNot-BlinkAsync.ino
   Coded for Wemos D1 Mini
*/

#include <Arduino.h>
#include <BlockNot.h>

BlockNot blueTimerON(500);
BlockNot blueTimerOFF(2500);
BlockNot yellowTimerON(5000);
BlockNot yellowTimerOFF(1000);
BlockNot greenTimerON(1000);
BlockNot greenTimerOFF(5000);

const int BLUE_PIN = D1;          //Data pins on Wemos D1 Mini
const int YELLOW_PIN = D2;
const int GREEN_PIN = D3;

const int LEDOFF = LOW;
const int LEDON = HIGH;

bool blueON = false;
bool yellowON = false;
bool greenON = false;

//State handlers
bool blueIsOff() {
  return !blueON;
}
bool blueIsOn() {
  return blueON;
}
bool yellowIsOff() {
  return !yellowON;
}
bool yellowIsOn() {
  return yellowON;
}
bool greenIsOff() {
  return !greenON;
}
bool greenIsOn() {
  return greenON;
}


void turnBlueOn() {
  digitalWrite(BLUE_PIN, LEDON);
  blueTimerON.RESET;
  blueON = true;
}

void turnBlueOff() {
  digitalWrite(BLUE_PIN, LEDOFF);
  blueTimerOFF.RESET;
  blueON = false;
}

void turnYellowOn() {
  digitalWrite(YELLOW_PIN, LEDON);
  yellowTimerON.RESET;
  yellowON = true;
}

void turnYellowOff() {
  digitalWrite(YELLOW_PIN, LEDOFF);
  yellowTimerOFF.RESET;
  yellowON = false;
}

void turnGreenOn() {
  digitalWrite(GREEN_PIN, LEDON);
  greenTimerON.RESET;
  greenON = true;
}

void turnGreenOff() {
  digitalWrite(GREEN_PIN, LEDOFF);
  greenTimerOFF.RESET;
  greenON = false;
}


// ---------- setup() ----------
void setup() {
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);

  resetAllTimers();

  //Start with all LEDs on
  turnBlueOn();
  turnYellowOn();
  turnGreenOn();
}

// ---------- loop() ----------
void loop() {

  if (blueTimerON.TRIGGERED && blueIsOn()) turnBlueOff();
  if (blueTimerOFF.TRIGGERED && blueIsOff()) turnBlueOn();
  if (yellowTimerON.TRIGGERED && yellowIsOn()) turnYellowOff();
  if (yellowTimerOFF.TRIGGERED && yellowIsOff()) turnYellowOn();
  if (greenTimerON.TRIGGERED && greenIsOn()) turnGreenOff();
  if (greenTimerOFF.TRIGGERED && greenIsOff()) turnGreenOn();
}
