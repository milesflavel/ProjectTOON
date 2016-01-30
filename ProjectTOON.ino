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
  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  for (int c = 0; c < COLCOUNT; c++) {
    digitalWrite(cols[c], LOW);
    for (int r = 0; r < ROWCOUNT; r++) {
      //delay(10);
      bool keyPressed = (digitalRead(rows[r]) == LOW) ? true : false;
      /*
      Serial.print("[");
      Serial.print(c);
      Serial.print(",");
      Serial.print(r);
      Serial.print("] ");
      Serial.println(keyPressed);
      */
      pressKey(keyMatrix[c][r], keyPressed);
    }
    digitalWrite(cols[c], HIGH);
  }
}
