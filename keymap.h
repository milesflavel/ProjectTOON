#include "keycodes.h"

// Define the keymap
int keymap[][87] = {
  {
    ESC,        KF1,  KF2,  KF3,  KF4,  KF5,  KF6,  KF7,  KF8,  KF9,  KF10, KF11, KF12, PSCR, SLCK, PAUS, \
    TILD, K1,   K2,   K3,   K4,   K5,   K6,   K7,   K8,   K9,   K0,   MINS, EQL,  BSPC, INS,  HOME, PGUP, \
    TAB,  KQ,   KW,   KE,   KR,   KT,   KY,   KU,   KI,   KO,   KP,   LBRC, RBRC, BSLS, DEL,  END,  PGDN, \
    CAPS, KA,   KS,   KD,   KF,   KG,   KH,   KJ,   KK,   KL,   SCLN, QUOT,       ENT,                    \
    LSFT,       KZ,   KX,   KC,   KV,   KB,   KN,   KM,   COMM, DOT,  SLSH,       RSFT,       UP,         \
    LCTL, LGUI, LALT,                   SPC,                    RALT, RGUI, APP,  RCTL, LEFT, DOWN, RGHT  \
  },
  {
    NONE,       NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, \
    NONE, M079, M081, M083, M085, M087, M089, M091, M093, M095, M097, M099, M101, NONE, NONE, NONE, NONE, \
    NONE, M080, M082, M084, M086, M088, M090, M092, M094, M096, M098, M100, M102, NONE, NONE, NONE, NONE, \
    NONE, M059, M061, M063, M065, M067, M069, M071, M073, M075, M077, M079,       NONE,                   \
    NONE,       M060, M062, M064, M066, M068, M070, M072, M074, M076, M078,       NONE,       NONE,       \
    NONE, NONE, NONE,                   NONE,                   NONE, NONE, NONE, NONE, NONE, NONE, NONE  \
  }
};
