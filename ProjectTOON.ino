/*
  Project TOON (The Other Other Norseboard)
  Mechanical keyboard and MIDI controller hybrid
  
  Code started January 25th 2016,
  loosely referencing prior work on the original Norseboard
 */
#define ROWCOUNT 6
#define COLCOUNT 17
#include "key.h"
#include "matrix.h"
 
int rows[] = { 14, 13, 3, 2, 1, 0 };
int cols[] = { 23, 10, 9, 22, 5, 24, 21, 20, 19, 18, 17, 16, 12, 11, 6, 7, 8 };

void setup() {                
  for (int r = 0; r < ROWCOUNT; r++)
    pinMode(r, INPUT);
  for (int c = 0; c < COLCOUNT; c++)
    pinMode(c, OUTPUT); 
}

// the loop routine runs over and over again forever:
void loop() {
  usbMIDI.sendNoteOn(60, 99, 1);  // 60 = C4
  usbMIDI.sendNoteOn(60, 99, 1);  // 60 = C4
  usbMIDI.sendNoteOn(60, 99, 1);  // 60 = C4
  delay(1000);               // wait for a second
  usbMIDI.sendNoteOff(60, 0, 1);  // 60 = C4
  delay(1000);               // wait for a second
}
