/*
   millis_BlinkAsync3.ino
   Use millis to blink three LEDs asynchronously.
   Testing was done on a Wemos D1 Mini.
*/

#define LEDOFF LOW
#define LEDON HIGH


//--------------- blue ---------------
const int blueLedpin = D1;
const long blueOnDuration = 500;
const long blueOffDuration = 2500;
int blueLedState = LEDON;
long rememberBlueTime = 0;

//--------------- yellow ---------------
const int yellowLedpin = D2;
const long yellowOnDuration = 5000;
const long yellowOffDuration = 1000;
int yellowLedState = LEDON;                   // initial state of LEDs
long rememberYellowTime = 0;

//--------------- green ---------------
const int greenLedpin = D3;
const long greenOnDuration = 500;
const long greenOffDuration = 2500;
int greenLedState = LEDON;
long rememberGreenTime = 0;



//--------------- setup() ---------------
void setup() {
  Serial.begin(115200);
  while (!Serial);
  Serial.println();
  Serial.println(F("millis_BlinkAsync.ino"));
  Serial.println();

  pinMode(yellowLedpin, OUTPUT);               // define Led pins as output
  pinMode(blueLedpin, OUTPUT);
  pinMode(greenLedpin, OUTPUT);
  
  digitalWrite(yellowLedpin, yellowLedState);  // set initial state
  digitalWrite(blueLedpin, blueLedState);
  digitalWrite(blueLedpin, greenLedState);
}


//--------------- loop() ---------------
void loop() {
  if ( yellowLedState == LEDON ) {
    if ( (millis() - rememberYellowTime) >= yellowOnDuration) {
      yellowLedState = LEDOFF;              //change the state of LED
      rememberYellowTime = millis();        //remember Current millis() time
    }
  } else {                                  //Current state is OFF
    if ( (millis() - rememberYellowTime) >= yellowOffDuration) {
      yellowLedState = LEDON;               //change the state of LED
      rememberYellowTime = millis();        //remember Current millis() time
    }
  }
  digitalWrite(yellowLedpin, yellowLedState);     //turn the yellow LED ON or OFF


  if ( blueLedState == LEDON ) {
    if ( (millis() - rememberBlueTime) >= blueOnDuration) {
      blueLedState = LEDOFF;              //change the state of LED
      rememberBlueTime = millis();        //remember Current millis() time
    }
  } else {
    if ( (millis() - rememberBlueTime) >= blueOffDuration) {
      blueLedState = LEDON;               //change the state of LED
      rememberBlueTime = millis();        //remember Current millis() time
    }
  }
  digitalWrite(blueLedpin, blueLedState);     //turn the blue LED ON or OFF


  if ( greenLedState == LEDON ) {
    if ( (millis() - rememberGreenTime) >= greenOnDuration) {
      greenLedState = LEDOFF;              //change the state of LED
      rememberGreenTime = millis();        //remember Current millis() time
    }
  } else {
    if ( (millis() - rememberGreenTime) >= greenOffDuration) {
      greenLedState = LEDON;               //change the state of LED
      rememberGreenTime = millis();        //remember Current millis() time
    }
  }
  digitalWrite(greenLedpin, greenLedState);     //turn the green LED ON or OFF
}
