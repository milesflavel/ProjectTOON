// Define the mode selector pin
#define MODE_PIN A14

// Define the output modes
#define MODE_USBHID 0
#define MODE_USBMIDI 1
#define MODE_MIDI 2
int outputMode;

// Define mode analog thresholds
#define MODE_THRESHOLD 20
#define MODE_USBHID_VALUE 1
#define MODE_USBMIDI_VALUE 341
#define MODE_MIDI_VALUE 1014

void modeInit() {
  pinMode(MODE_PIN, INPUT);
  outputMode = MODE_USBHID;
}

bool isMode(int analogValue, int modeValue) {
  if (analogValue >= modeValue - MODE_THRESHOLD && analogValue <= modeValue + MODE_THRESHOLD) return true;
  return false;
}

int getMode(int analogValue) {
  if (isMode(analogValue, MODE_USBHID_VALUE)) return MODE_USBHID;
  else if (isMode(analogValue, MODE_USBMIDI_VALUE)) return MODE_USBMIDI;
  else if (isMode(analogValue, MODE_MIDI_VALUE)) return MODE_MIDI;
  else return outputMode;
}

void checkMode() {
  int mode = getMode(analogRead(MODE_PIN));
  if (outputMode != mode) outputMode = mode;
}

