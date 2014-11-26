#include <ASTC_notes.h>

/* this is the 'structure' that the following data takes
   you can think of it as identifying the column headers used below */
struct tune {
  int octave;
  int note;
  int duration;
};

/* this is an array that holds our data
   when it is interpreted correctly, it will play a tune! */
struct tune tune[] = {
  {  5, NOTE_G, 250},
  {  6, NOTE_E, 250},
  {  6, NOTE_D, 250},
  {  6, NOTE_C, 250},
  {  5, NOTE_G, 450},
  { -1,     -1,  50},

  {  5, NOTE_G, 250},
  {  6, NOTE_E, 250},
  {  6, NOTE_D, 250},
  {  6, NOTE_C, 250},
  {  5, NOTE_A, 450},
  { -1,     -1,  50},

  {  5, NOTE_A, 250},
  {  6, NOTE_F, 250},
  {  6, NOTE_E, 250},
  {  6, NOTE_D, 250},
  {  5, NOTE_B, 350},
  {  6, NOTE_G, 150},
  {  6, NOTE_A, 250},
  {  6, NOTE_G, 250},
  {  6, NOTE_F, 250},
  {  6, NOTE_D, 250},
  {  6, NOTE_E, 450},
  { -1,     -1,  50},
};

void setup(void) {
  pinMode(11, OUTPUT); /* the buzzer */
  pinMode(13, OUTPUT); /* the on-board LED */
}

void loop(void) {
  /* these are 'variables', they can store information for us */
  int i;
  int freq;
  
  /* a 'for loop' allows us to do things over an over again, with different values of 'i' */
  for (i = 0; i < (sizeof(tune) / sizeof(tune[0])); i++) {
    
    /* check that neither the 'octave' or 'note' columns contain a '-1'
       don't forget we are looking at 'row i', so:
         the first time around the for loop, we use the values from the first row
         the second time, we use values from the second row, etc... */
    if (tune[i].octave != -1 && tune[i].note != -1) {
      
      /* here, we look up the note's frequency, which is stored in the array 'note' - see musical_notes.h */
      freq = note[ tune[i].octave ][ tune[i].note ];
      
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
    
    /* now, we must pause, for the duration indicated */
    delay(tune[i].duration);
  }
  
  /* after the tune has been played, we must remember to stop playing the tone! */
  noTone(11);
  /* and turn off the LED */
  digitalWrite(13, LOW);
  
  /* then, do nothing, forever! */
  for(;;);
}
