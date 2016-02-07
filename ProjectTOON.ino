/*
  Project TOON (The Other Other Norseboard)
  Mechanical keyboard and MIDI controller hybrid
  
  Code started January 25th 2016
  Loosely referencing prior work on the original Norseboard and TMK Keyboard
 */

#include "pins.h"
#include "key.h"
#include "matrix.h"
#include "output.h"

void setup() {
  pinsInit();
  outputInit();
  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  for (int c = 0; c < COLCOUNT; c++) {
    for (int r = 0; r < ROWCOUNT; r++) {
      checkKey(c, r);
    }
  }
}
