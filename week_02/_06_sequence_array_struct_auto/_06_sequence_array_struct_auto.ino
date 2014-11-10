/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */

#define ARRAY_SIZE(x)  (sizeof(x) / sizeof((x)[0]))
 
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

struct pattern {
  int pin3_state;
  int pin5_state;
  int pin7_state;
  int pin9_state;
  int duration;
};

// the following variable has a list of which pin should be set high in each step
// this creates the following pattern for us
//    0:  * . . .
//    1:  . * . .
//    2:  . . * .
//    3:  . . . *
//    4;  . . * .
//    5:  . * . .
struct pattern sequence[] = {
  { HIGH,  LOW,  LOW,  LOW,  250 },
  { HIGH, HIGH,  LOW,  LOW,   75 },
  { HIGH, HIGH, HIGH,  LOW,   75 },
  { HIGH, HIGH, HIGH, HIGH,  250 },
  { HIGH, HIGH, HIGH,  LOW,   75 },
  { HIGH, HIGH,  LOW,  LOW,   75 },
  { HIGH,  LOW,  LOW,  LOW,  250 },
  {  LOW, HIGH,  LOW,  LOW,   75 },
  {  LOW,  LOW, HIGH,  LOW,   75 },
  {  LOW,  LOW,  LOW, HIGH,  250 },
  {  LOW,  LOW, HIGH, HIGH,   75 },
  {  LOW, HIGH, HIGH, HIGH,   75 },
  { HIGH, HIGH, HIGH, HIGH,  250 },
  {  LOW, HIGH, HIGH, HIGH,   75 },
  {  LOW,  LOW, HIGH, HIGH,   75 },
  {  LOW,  LOW,  LOW, HIGH,  250 },
  {  LOW,  LOW, HIGH,  LOW,   75 },
  {  LOW, HIGH,  LOW,  LOW,   75 },
};

// the loop routine runs over and over again forever:
void loop() {
  int i;
  
  // loop the following code, setting 'i' to a value each time
  for (i = 0; i < ARRAY_SIZE(sequence); i++) {
    
    // set all of the pins to their defined state for this step
    digitalWrite(3, sequence[i].pin3_state);
    digitalWrite(5, sequence[i].pin5_state);
    digitalWrite(7, sequence[i].pin7_state);
    digitalWrite(9, sequence[i].pin9_state);
    
    delay(sequence[i].duration);                // wait for the specified duration
  }
}

