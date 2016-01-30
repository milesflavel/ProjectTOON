#define BOUNCELIMIT 8 //How many times the bounce check is performed before toggling the key

// Define the key structure
struct Key {
  int id;
  bool pressed;    //Actual pressed state of the key
  bool nowPressed; //Used to determine bounce - Is the key now pressed
  bool wasPressed; //Used to determine bounce - Was the key previously pressed
  int bounce;
  Key(int id) : id(id), pressed(false), nowPressed(false), wasPressed(false), bounce(0) {};
};

// Function to toggle the state of a key
void toggleKey(struct Key *key) {
  if (!key->pressed) key->pressed = true;
  else key->pressed = false;
}

// Function to check if the key is still bouncing and fire off a toggle if it has stopped
void bounceKey(struct Key *key) {
  //Changed and not checking for bounce OR Not changed and already checking for bounce
  if ((key->nowPressed != key->wasPressed && key->bounce == 0) ||
      (key->nowPressed == key->wasPressed && key->bounce > 0)) {
    key->bounce++;
  }
  else key->bounce = 0;
  if (key->bounce >= BOUNCELIMIT) toggleKey(key);
}

// Function to check if the key is still bouncing and fire off a toggle if it has stopped
void pressKey(struct Key *key, bool isPressed) {
  key->wasPressed = key->nowPressed;
  key->nowPressed = isPressed;
  bounceKey(key);
}
