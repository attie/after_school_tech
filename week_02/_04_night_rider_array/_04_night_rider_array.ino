/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pins as an outputs.
  pinMode(led, OUTPUT);     
  pinMode(2, OUTPUT);     
  pinMode(3, OUTPUT);     
  pinMode(4, OUTPUT);     
  pinMode(5, OUTPUT);     
  pinMode(6, OUTPUT);     
  pinMode(7, OUTPUT);     
  pinMode(8, OUTPUT);     
  pinMode(9, OUTPUT);     
  
  // setup the even pins as LOW (0v)
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  digitalWrite(6, LOW);
  digitalWrite(8, LOW);
}

const int SEQUENCE_LENGTH = 6;

// the following variable has a list of which pin should be set high in each step
// this creates the following pattern for us
//    0:  * . . .
//    1:  . * . .
//    2:  . . * .
//    3:  . . . *
//    4;  . . * .
//    5:  . * . .
int sequence[SEQUENCE_LENGTH] = {
  3, 5, 7, 9, 7, 5
};

// the loop routine runs over and over again forever:
void loop() {
  int i;
  
  // loop the following code, setting 'i' to a value each time
  for (i = 0; i < SEQUENCE_LENGTH; i++) {
    // only turn on the on-board LED if we're at the first step (0)
    if (i == 0) {
      digitalWrite(led, HIGH);
    } else {
      digitalWrite(led, LOW);
    }
    
    // reset all of the pins, to turn off all of the LEDs
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    digitalWrite(7, LOW);
    digitalWrite(9, LOW);
    
    // turn on the one LED that the array specifies
    digitalWrite(sequence[i], HIGH);
    
    delay(150);                // wait for 150 milliseconds
  }
}

