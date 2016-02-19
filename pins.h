// Define the rows, columns and associated pin mapping
#define ROWCOUNT 6
#define COLCOUNT 17
int rows[] = { 14, 13, 3, 2, 25, 0 };
int cols[] = { 23, 10, 9, 22, 5, 24, 21, 20, 19, 18, 17, 16, 12, 11, 6, 7, 8 };
//int rows[] = { 0, 1, 2, 3, 4, 5 };
//int cols[] = { 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 };

void pinsInit() {
  for (int r = 0; r < ROWCOUNT; r++) {
    pinMode(rows[r], INPUT_PULLUP);
    //digitalWrite(rows[r], HIGH);
  }
  for (int c = 0; c < COLCOUNT; c++) {
    pinMode(cols[c], OUTPUT);
    digitalWrite(cols[c], HIGH);
  }
}

