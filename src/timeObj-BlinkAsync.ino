/*
 * timeObj-BlinkAsync.ino
 * Use the timeObj library to blink three LEDS asynchronously
 */
const long Seconds = 1000;                     //ms per second
long blueOnTime = 0.5 * Seconds;
long blueOffTime = 2.5 * Seconds;
long yellowOnTime = 5 * Seconds;
long yellowOffTime = 1 * Seconds;
long greenOnTime = 1 * Seconds;
long greenOffTime = 5 * Seconds;


#include "timeObj.h"
//Create timer objects, don't start them.
timeObj blueOnTimer(blueOnTime, false);
timeObj blueOffTimer(blueOffTime, false);
timeObj yellowOnTimer(yellowOnTime, false);
timeObj yellowOffTimer(yellowOffTime, false);
timeObj greenOnTimer(greenOnTime, false);
timeObj greenOffTimer(greenOffTime, false);


int bluePin = D1;               // The LEDs we want to blink.
int yellowPin = D2;
int greenPin = D3;

bool blueState = false;         // Save the state of the LED here.
bool yellowState = false;
bool greenState = false;


void setup() {
  pinMode(bluePin, OUTPUT);       // Initialize the LED pins as an output.
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  digitalWrite(bluePin, HIGH);    // Turn the blue on.
  blueOnTimer.start();            // Start the blue timer.
  digitalWrite(yellowPin, HIGH);  // Turn the yellow on.
  yellowOnTimer.start();          // Start the yellow timer.
  digitalWrite(greenPin, HIGH);    // Turn the green on.
  greenOnTimer.start();            // Start the green timer.
}

void loop() {
  if (blueOnTimer.ding()) blueOff();      //When the blue on timer dings, turn the blue off.
  if (blueOffTimer.ding()) blueOn();      //When the blue off timer dings, turn the blue on.
  if (yellowOnTimer.ding()) yellowOff();  //When the yellow on timer dings, turn the yellow off.
  if (yellowOffTimer.ding()) yellowOn();  //When the yellow off timer dings, turn the yellow on.
  if (greenOnTimer.ding()) greenOff();    //When the green on timer dings, turn the green off.
  if (greenOffTimer.ding()) greenOn();    //When the green off timer dings, turn the green on.
}



void blueOff() {
  blueOnTimer.reset();                  // Turn off the blue on timer
  digitalWrite(bluePin, LOW);           // Turn the blue off.
  blueState = false;                    // Remember the state
  blueOffTimer.setTime(blueOffTime);
  blueOffTimer.stepTime();              // Start the blue off timer
}

void blueOn() {
  blueOffTimer.reset();                 // Turn off the blue off timer
  digitalWrite(bluePin, HIGH);          // Turn the blue on.
  blueState = true;                     // Remember the state
  blueOnTimer.setTime(blueOnTime);
  blueOnTimer.stepTime();               // Start the blue on timer
}

void yellowOff() {
  yellowOnTimer.reset();                  // Turn off the yellow on timer
  digitalWrite(yellowPin, LOW);           // Turn the yellow off.
  yellowState = false;                    // Remember the state
  yellowOffTimer.setTime(yellowOffTime);
  yellowOffTimer.stepTime();              // Start the off timer
}

void yellowOn() {
  yellowOffTimer.reset();                 // Turn off the yellow off timer
  digitalWrite(yellowPin, HIGH);          // Turn the yellow on.
  yellowState = true;                     // Remember the state
  yellowOnTimer.setTime(yellowOnTime);
  yellowOnTimer.stepTime();               // Start the yellow on timer
}

void greenOff() {
  greenOnTimer.reset();
  digitalWrite(greenPin, LOW);           // Turn the green off.
  greenState = false;                    // Remember the state
  greenOffTimer.setTime(greenOffTime);
  greenOffTimer.stepTime();              // Start the green off timer
}

void greenOn() {
  greenOffTimer.reset();                 // Turn off the green off timer
  digitalWrite(greenPin, HIGH);          // Turn the green on.
  greenState = true;                     // Remember the state
  greenOnTimer.setTime(greenOnTime);
  greenOnTimer.stepTime();               // Start the green on timer
}
