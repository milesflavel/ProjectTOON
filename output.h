// Define the output modes
#define MODE_USBHID 0
#define MODE_USBMIDI 1
#define MODE_MIDI 2
int outputMode;

void outputInit() {
  outputMode = MODE_USBHID;
}

// Checks if a key's state has changed and performs the associated output function
void checkKey(int c, int r) {
  digitalWrite(cols[c], LOW);
  if (pressKey(keyMatrix[c][r], (digitalRead(rows[r]) == LOW ? true : false))) {
    if (keyMatrix[c][r]->pressed) {
      switch (outputMode) {
        case MODE_USBHID:
          Keyboard.press(getKey(0, c, r));
          break;
        case MODE_USBMIDI:
          usbMIDI.sendNoteOn(getKey(1, c, r), 99, 1);
          break;
        case MODE_MIDI:
          break;
      }
    }
    else {
      switch (outputMode) {
        case MODE_USBHID:
          Keyboard.release(getKey(0, c, r));
          break;
        case MODE_USBMIDI:
          usbMIDI.sendNoteOff(getKey(1, c, r), 99, 1);
          break;
        case MODE_MIDI:
          break;
      }
    }
  }
  digitalWrite(cols[c], HIGH);
}

