#pragma once

// Handwired Skeletyl: same 8x5 split matrix as bastardkb/skeletyl/promicro,
// wired differently. These replace the upstream values.
#undef MATRIX_ROW_PINS
#define MATRIX_ROW_PINS { B1, B3, B2, B6 }
#undef MATRIX_COL_PINS
#define MATRIX_COL_PINS { D4, C6, D7, E6, B4 }
#undef DIODE_DIRECTION
#define DIODE_DIRECTION COL2ROW
#undef SOFT_SERIAL_PIN
#define SOFT_SERIAL_PIN D0
