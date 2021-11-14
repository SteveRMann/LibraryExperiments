/*
  TickerAsync.ino
*/

#include <Ticker.h>
Ticker yellowON;
Ticker yellowOFF;
Ticker blueOn;
Ticker blueOff;
Ticker greenOn;
Ticker greenOff;

const int LED_ON = 1;
const int LED_OFF = !LED_ON;

const int LED_BLUE = D1;
const int LED_YELLOW = D2;
const int LED_GREEN = D3;


void yellowLedOn() {
  digitalWrite(LED_YELLOW, LED_ON);
  yellowON.detach();                      // Stop the on timer
  yellowOFF.attach(5, yellowLedOff);      // Turn off the Yellow LED in 5 seconds
}

void yellowLedOff() {
  digitalWrite(LED_YELLOW, LED_OFF);
  yellowOFF.detach();
  yellowON.attach(1, yellowLedOn);        // Turn on the Yellow LED in 1 second
}

void blueLedOn() {
  digitalWrite(LED_BLUE, LED_ON);
  blueOn.detach();
  blueOff.attach(0.5, blueLedOff);
}

void blueLedOff() {
  digitalWrite(LED_BLUE, LED_OFF);
  blueOff.detach();
  blueOn.attach(2.5, blueLedOn);
}

void greenLedOn() {
  digitalWrite(LED_GREEN, LED_ON);
  greenOn.detach();
  greenOff.attach(1, greenLedOff);
}

void greenLedOff() {
  digitalWrite(LED_GREEN, LED_OFF);
  greenOff.detach();
  greenOn.attach(5, greenLedOn);
}


//---------- setup() ----------
void setup() {
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  
  blueLedOn();
  yellowLedOn();
  greenLedOn();
}

//---------- loop() ----------
void loop() {
}
