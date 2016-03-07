// Define the pitch/modulation wheel pins
#define MIDI_PITCH_PIN A10
#define MIDI_MOD_PIN A11

// Pitch and modulation values and change thresholds
unsigned int midiPitch = 0;
unsigned int midiMod = 0;
const int midiPitchThreshold = 192;

void midiInit() {
  pinMode(MIDI_PITCH_PIN, INPUT);
  pinMode(MIDI_MOD_PIN, INPUT);
  Serial1.begin(31250);
}

void midiNoteOn(int pitch, int velocity) {
  Serial1.write(0x90);
  Serial1.write(pitch);
  Serial1.write(velocity);
}

void midiNoteOff(int pitch) {
  Serial1.write(0x90);
  Serial1.write(pitch);
  Serial1.write(0x00);
}

void midiPitchBend(int bend) {
  Serial1.write(0xE0);
  Serial1.write((bend & 0x7f));
  Serial1.write((bend >> 7) & 0x7f);
}

void checkMidiPitch() {
  unsigned int pitch = constrain((analogRead(MIDI_PITCH_PIN) - 517) * 63 + 8192, 1, 16384); //Analog value 0-1023 subract half that range to make center 0, multiplied by 63, add 2^13 (half of 14-bit integer max)
  if (!((pitch >= midiPitch - midiPitchThreshold) && (pitch <= midiPitch + midiPitchThreshold))) {
    switch (outputMode) {
      case MODE_USBMIDI:
        usbMIDI.sendPitchBend(pitch, 1);
        break;
      case MODE_MIDI:
        midiPitchBend(pitch);
        break;
    }
    midiPitch = pitch;
  }
  // Fallback to 8192 (no pitch bend) if close enough
  else if ((pitch >= 8192 - midiPitchThreshold - 8) && (pitch <= 8192 + midiPitchThreshold + 8)) {
    midiPitch = 8192;
    switch (outputMode) {
      case MODE_USBMIDI:
        usbMIDI.sendPitchBend(midiPitch, 1);
        break;
      case MODE_MIDI:
        midiPitchBend(midiPitch);
        break;
    }
  }
}

void midiModulation(int value) {
  Serial1.write(0xB0);
  Serial1.write(0x00);
  Serial1.write(value);
}

void checkMidiMod() {
  unsigned int mod = constrain(map(analogRead(MIDI_MOD_PIN), 370, 615, 0, 127), 0, 127);
  if (mod != midiMod) {
    switch (outputMode) {
      case MODE_USBMIDI:
        usbMIDI.sendControlChange(0, mod, 1);
        break;
      case MODE_MIDI:
        midiModulation(mod);
        break;
    }
    midiMod = mod;
  }
}
