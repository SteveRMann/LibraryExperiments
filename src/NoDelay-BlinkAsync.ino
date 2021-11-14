#define SKETCH "NoDelay-BlinkAsync.ino"

#include<NoDelay.h>

/* To create a NoDelay object:
   noDelay object(1000);                    //Makes an object of given time in ms
   noDelay object(1000, function_to_call);  //Makes an object in ms that will call the given function
   noDelay object(1000,false);              //Makes an object of given time in ms but keeps it from running
   noDelay object(1000, function, false);   //Makes object in ms that will call function but keep it from running

    Methods
    update() : When called it will check if the amount of time set has passed.
    setdelay() : This function is used to adjust the amount of time it takes for NoDelay to wait for.
    start() : Start is used to reset the timer or to start NoDelay again when it has been stopped.
    stop() : This function will keep NoDelay from returning true or running a function when calling update().
*/

noDelay blueLED_onTime(500, false);           //Create a noDelay objects
noDelay blueLED_offTime(2500, false);
noDelay yellowLED_onTime(5000, false);
noDelay yellowLED_offTime(1000, false);
noDelay greenLED_onTime(1000, false);
noDelay greenLED_offTime(5000, false);


const int LED_ON = 1;
const int LED_OFF = !LED_ON;

const int LED_BLUE_pin = D1;
const int LED_YELLOW_pin = D2;
const int LED_GREEN_pin = D3;


void setup() {
  pinMode(LED_BLUE_pin, OUTPUT);
  pinMode(LED_YELLOW_pin, OUTPUT);
  pinMode(LED_GREEN_pin, OUTPUT);

  digitalWrite(LED_YELLOW_pin, LED_OFF);
  digitalWrite(LED_BLUE_pin, LED_OFF);
  digitalWrite(LED_GREEN_pin, LED_OFF);

  //Start LED timers
  yellowLED_onTime.start();                  //Start the yellow ON timer
  blueLED_onTime.start();                    //Start the blue ON timer
  greenLED_onTime.start();                    //Start the green ON timer
}


void loop() {
  //---------- Toggle the yellow LED ----------
  if (yellowLED_onTime.update()) {           //Yellow on time ends?
    digitalWrite(LED_YELLOW_pin, LED_OFF);   //Yes, turn off yellow LED
    yellowLED_onTime.stop();                 //Stop the yellow on timer
    yellowLED_offTime.start();               //Start the yellow off timer
  }

  if (yellowLED_offTime.update()) {          //Yellow off time ends?
    digitalWrite(LED_YELLOW_pin, LED_ON);    //Yes, turn on yellow LED
    yellowLED_offTime.stop();                //Stop the yellow off timer
    yellowLED_onTime.start();                //Start the yellow on timer
  }


  //---------- Toggle the blue LED ----------
  if (blueLED_onTime.update()) {           //blue on time ends?
    digitalWrite(LED_BLUE_pin, LED_OFF);   //Yes, turn off blue LED
    blueLED_onTime.stop();                 //Stop the blue on timer
    blueLED_offTime.start();               //Start the blue off timer
  }

  if (blueLED_offTime.update()) {          //blue off time ends?
    digitalWrite(LED_BLUE_pin, LED_ON);    //Yes, turn on blue LED
    blueLED_offTime.stop();                //Stop the blue off timer
    blueLED_onTime.start();                //Start the blue on timer
  }


  //---------- Toggle the green LED ----------
  if (greenLED_onTime.update()) {           //green on time ends?
    digitalWrite(LED_GREEN_pin, LED_OFF);   //Yes, turn off green LED
    greenLED_onTime.stop();                 //Stop the green on timer
    greenLED_offTime.start();               //Start the green off timer
  }

  if (greenLED_offTime.update()) {          //green off time ends?
    digitalWrite(LED_GREEN_pin, LED_ON);    //Yes, turn on green LED
    greenLED_offTime.stop();                //Stop the green off timer
    greenLED_onTime.start();                //Start the green on timer
  }

}
