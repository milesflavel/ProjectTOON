/*
  Project TOON (The Other Other Norseboard)
  Mechanical keyboard and MIDI controller hybrid
  
  Code started January 25th 2016
  Loosely referencing prior work on the original Norseboard and TMK Keyboard
 */

#include "pins.h"
#include "key.h"
#include "matrix.h"

void setup() {
  pinsInit();
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
