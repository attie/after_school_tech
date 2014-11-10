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

// the loop routine runs over and over again forever:
void loop() {
  int i;
  
  // loop the following code, setting 'i' to a value each time
  // 'i' will take the following values, matched against the LEDs that we want to be lit:
  //    0:  * . . .
  //    1:  . * . .
  //    2:  . . * .
  //    3:  . . . *
  //    4;  . . * .
  //    5:  . * . .
  for (i = 0; i < 6; i++) {
    // only turn on the on-board and first LEDs if we're at the first step (0)
    if (i == 0) {
      digitalWrite(led, HIGH);
      digitalWrite(3, HIGH);
    } else {
      digitalWrite(led, LOW);
      digitalWrite(3, LOW);
    }
    
    // only turn on the second LED if we're at the second or sixth steps (1 or 5)
    if (i == 1 || i == 5) {
      digitalWrite(5, HIGH);
    } else {
      digitalWrite(5, LOW);
    }
    
    // only turn on the third LED if we're at the third or fifth steps (2 or 4)
    if (i == 2 || i == 4) {
      digitalWrite(7, HIGH);
    } else {
      digitalWrite(7, LOW);
    }
    
    // only turn on the last LED if we're at the fourth step (3)
    if (i == 3) {
      digitalWrite(9, HIGH);
    } else {
      digitalWrite(9, LOW);
    }
    
    delay(150);                // wait for 150 milliseconds
  }
}

