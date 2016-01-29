// Define the key structure
struct Key {
  int id;
  bool pressed;
  Key(int id) : id(id), pressed(false) {};
};

// Function to toggle the state of a key
void toggleKey(struct Key *key) {
  if (!key->pressed) key->pressed = true;
  else key->pressed = false;
}

