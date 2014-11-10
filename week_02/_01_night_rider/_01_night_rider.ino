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
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(3, HIGH);     // turn the LED on  (acts in conjunction with pin 2)
  digitalWrite(5, LOW);      // turn the LED off (acts in conjunction with pin 4)
  digitalWrite(7, LOW);      // turn the LED off (acts in conjunction with pin 6)
  digitalWrite(9, LOW);      // turn the LED off (acts in conjunction with pin 8)
  delay(150);                // wait for 150 milliseconds
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(3, LOW);      // turn the LED off (acts in conjunction with pin 2)
  digitalWrite(5, HIGH);     // turn the LED on  (acts in conjunction with pin 4)
  digitalWrite(7, LOW);      // turn the LED off (acts in conjunction with pin 6)
  digitalWrite(9, LOW);      // turn the LED off (acts in conjunction with pin 8)
  delay(150);                // wait for 150 milliseconds
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(3, LOW);      // turn the LED off (acts in conjunction with pin 2)
  digitalWrite(5, LOW);      // turn the LED off (acts in conjunction with pin 4)
  digitalWrite(7, HIGH);     // turn the LED on  (acts in conjunction with pin 6)
  digitalWrite(9, LOW);      // turn the LED off (acts in conjunction with pin 8)
  delay(150);                // wait for 150 milliseconds
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(3, LOW);      // turn the LED off (acts in conjunction with pin 2)
  digitalWrite(5, LOW);      // turn the LED off (acts in conjunction with pin 4)
  digitalWrite(7, LOW);      // turn the LED off (acts in conjunction with pin 6)
  digitalWrite(9, HIGH);     // turn the LED on  (acts in conjunction with pin 8)
  delay(150);                // wait for 150 milliseconds
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(3, LOW);      // turn the LED off (acts in conjunction with pin 2)
  digitalWrite(5, LOW);      // turn the LED off (acts in conjunction with pin 4)
  digitalWrite(7, HIGH);     // turn the LED on  (acts in conjunction with pin 6)
  digitalWrite(9, LOW);      // turn the LED off (acts in conjunction with pin 8)
  delay(150);                // wait for 150 milliseconds
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(3, LOW);      // turn the LED off (acts in conjunction with pin 2)
  digitalWrite(5, HIGH);     // turn the LED on  (acts in conjunction with pin 4)
  digitalWrite(7, LOW);      // turn the LED off (acts in conjunction with pin 6)
  digitalWrite(9, LOW);      // turn the LED off (acts in conjunction with pin 8)
  delay(150);                // wait for 150 milliseconds
}

