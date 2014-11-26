#include <ASTC_notes.h>

/* this is the 'structure' that the following data takes
   you can think of it as identifying the column headers used below */
struct pattern {
  int octave;
  int note;
  int duration;
  
  int led0;
  int led1;
  int led2;
  int led3;
};

/* this is an array that holds our data
   when it is interpreted correctly, it will play a tune, and flash the LEDs in a pattern! */
struct pattern pattern[] = {
  {  5, NOTE_G, 250, HIGH, HIGH, HIGH, HIGH},
  {  6, NOTE_E, 250, LOW , LOW , LOW , LOW },
  {  6, NOTE_D, 250, HIGH, HIGH, HIGH, HIGH},
  {  6, NOTE_C, 250, LOW , LOW , LOW , LOW },
  {  5, NOTE_G, 450, HIGH, HIGH, HIGH, HIGH},
  { -1,     -1,  50, LOW , LOW , LOW , LOW },

  {  5, NOTE_G, 250, HIGH, HIGH, LOW , LOW },
  {  6, NOTE_E, 250, LOW , LOW , HIGH, HIGH},
  {  6, NOTE_D, 250, HIGH, HIGH, LOW , LOW },
  {  6, NOTE_C, 250, LOW , LOW , HIGH, HIGH},
  {  5, NOTE_A, 450, HIGH, HIGH, HIGH, HIGH},
  { -1,     -1,  50, LOW , LOW , LOW , LOW },

  {  5, NOTE_A, 250, HIGH, LOW , LOW , LOW },
  {  6, NOTE_F, 250, LOW , HIGH, LOW , LOW },
  {  6, NOTE_E, 250, LOW , LOW , HIGH, LOW },
  {  6, NOTE_D, 250, LOW , LOW , LOW , HIGH},
  {  5, NOTE_B, 350, LOW , LOW , HIGH, LOW },
  {  6, NOTE_G, 150, LOW , HIGH, LOW , LOW },
  {  6, NOTE_A, 250, HIGH, LOW , LOW , LOW },
  {  6, NOTE_G, 250, LOW , HIGH, LOW , HIGH},
  {  6, NOTE_F, 250, HIGH, LOW , HIGH, LOW },
  {  6, NOTE_D, 250, LOW , HIGH, LOW , HIGH},
  {  6, NOTE_E, 450, LOW , HIGH, HIGH, LOW },
  { -1,     -1,  50, LOW , LOW , LOW , LOW },
};

void setup(void) {
  pinMode(2, OUTPUT);  /* led0 + */
  pinMode(3, OUTPUT);  /* led0 - */
  pinMode(4, OUTPUT);  /* led1 + */
  pinMode(5, OUTPUT);  /* led1 - */
  pinMode(6, OUTPUT);  /* led2 + */
  pinMode(7, OUTPUT);  /* led2 - */
  pinMode(8, OUTPUT);  /* led3 + */
  pinMode(9, OUTPUT);  /* led3 - */
  
  pinMode(11, OUTPUT); /* buzzer */
  pinMode(13, OUTPUT); /* on-board led */
  
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}

void loop(void) {
  /* these are 'variables', they can store information for us */
  int i;
  int freq;
  
  /* a 'for loop' allows us to do things over an over again, with different values of 'i' */
  for (i = 0; i < (sizeof(pattern) / sizeof(pattern[0])); i++) {
    
    /* check that neither the 'octave' or 'note' columns contain a '-1'
       don't forget we are looking at 'row i', so:
         the first time around the for loop, we use the values from the first row
         the second time, we use values from the second row, etc... */
    if (pattern[i].octave != -1 && pattern[i].note != -1) {
      
      /* here, we look up the note's frequency, which is stored in the array 'note' - see musical_notes.h */
      freq = note[ pattern[i].octave ][ pattern[i].note ];
      
      /* next, we play the tone on our buzzer's pin */
      tone(11, freq);
      /* and turn on the LED */
      digitalWrite(13, HIGH);
      
    } else {
      
      /* if the 'octave' or 'note' values were '-1', then we stop playing a tone */
      noTone(11);
      /* and turn off the LED */
      digitalWrite(13, LOW);
      
    }
    
    /* we also set the LED outputs to match the current sequence step */
    digitalWrite(2, pattern[i].led0);
    digitalWrite(4, pattern[i].led1);
    digitalWrite(6, pattern[i].led2);
    digitalWrite(8, pattern[i].led3);
   
    /* now, we must pause, for the duration indicated */
    delay(pattern[i].duration);
  }
  
  /* after the tune has been played, we must remember to stop playing the tone! */
  noTone(11);
  /* and turn off all the LEDs */
  digitalWrite(13, LOW);
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  digitalWrite(6, LOW);
  digitalWrite(8, LOW);
  
  /* then, do nothing, forever! */
  for(;;);
}
