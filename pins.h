// Define the rows, columns and associated pin mapping
#define ROWCOUNT 6
#define COLCOUNT 17
int rows[] = { 14, 13, 3, 2, 1, 0 };
int cols[] = { 23, 10, 9, 22, 5, 24, 21, 20, 19, 18, 17, 16, 12, 11, 6, 7, 8 };

void pinsInit() {
  for (int r = 0; r < ROWCOUNT; r++)
    pinMode(r, INPUT);
  for (int c = 0; c < COLCOUNT; c++)
    pinMode(c, OUTPUT);
}

