#include "keymap_ansi.h"

// Define the PhantomPCB key matrix
Key * const keyMatrix[COLCOUNT][ROWCOUNT] = {
    //This row
  { new Key( 0), new Key(17), new Key(33), new Key(50), new Key(63), new Key(76) },
  { new Key(16), new Key(18), new Key(34), new Key(51), new Key( 0), new Key(77) },
  { new Key( 1), new Key(19), new Key(35), new Key(52), new Key(64), new Key(78) },
  { new Key( 2), new Key(20), new Key(36), new Key(53), new Key(65), new Key( 0) },
  { new Key( 3), new Key(21), new Key(37), new Key(54), new Key(66), new Key( 0) },
  { new Key( 4), new Key(22), new Key(38), new Key(55), new Key(67), new Key( 0) }, //This column 5
  { new Key( 5), new Key(23), new Key(39), new Key(56), new Key(68), new Key( 0) },
  { new Key( 6), new Key(24), new Key(40), new Key(57), new Key(69), new Key(79) },
  { new Key( 7), new Key(25), new Key(41), new Key(58), new Key(70), new Key( 0) },
  { new Key( 8), new Key(26), new Key(42), new Key(59), new Key(71), new Key( 0) },
  { new Key( 9), new Key(27), new Key(43), new Key(60), new Key(72), new Key(80) },
  { new Key(10), new Key(28), new Key(44), new Key(61), new Key(73), new Key(81) },
  { new Key(11), new Key( 0), new Key(45), new Key( 0), new Key( 0), new Key(82) },
  { new Key(12), new Key(29), new Key(46), new Key(62), new Key(74), new Key(83) },
  { new Key(13), new Key(30), new Key(47), new Key( 0), new Key( 0), new Key(84) },
  { new Key(14), new Key(31), new Key(48), new Key( 0), new Key(75), new Key(85) },
  { new Key(15), new Key(32), new Key(49), new Key( 0), new Key( 0), new Key(86) }
};

int getKey(int layer, int column, int row) {
  return keymap[layer][keyMatrix[column][row]->id];
}

