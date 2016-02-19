void midiInit() {
  Serial1.begin(31250);
}

void midiNoteOn(int cmd, int pitch, int velocity) {
  Serial1.write(cmd);
  Serial1.write(pitch);
  Serial1.write(velocity);
}

void midiNoteOff(int cmd, int pitch) {
  Serial1.write(cmd);
  Serial1.write(pitch);
  Serial1.write(0x00);
}
