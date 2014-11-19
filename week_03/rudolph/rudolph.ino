void setup() {
  pinMode(2, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  
  tone(2, 1568); delay(150);
  tone(2, 1760); delay(200);
  noTone(2);     delay(50);
  tone(2, 1568); delay(100);
  tone(2, 1319); delay(200);
  noTone(2);     delay(50);
  tone(2, 2093); delay(250);
  tone(2, 1760); delay(250);
  tone(2, 1568); delay(500);
  noTone(2);     delay(25);
  tone(2, 1568); delay(150);
  tone(2, 1760); delay(100);
  tone(2, 1568); delay(150);
  tone(2, 1760); delay(100);
  tone(2, 1568); delay(250);
  noTone(2);     delay(10);
  tone(2, 2093); delay(250);
  tone(2, 1976); delay(500);
  noTone(2);
  
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
}

