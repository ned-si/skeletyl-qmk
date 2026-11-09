# skeletyl-qmk

My QMK keymap for a handwired [BastardKB Skeletyl](https://github.com/Bastardkb/Skeletyl)
(3x5+3 split, Elite-C footprint controller).

It is cloned inside my
[qmk-userspace](https://github.com/ned-si/qmk-userspace) checkout, at
`keyboards/bastardkb/skeletyl/keymaps/nedsi` (git-ignored there). The shared
code (layer enum, row macros, custom keycodes, tap dances) lives in
qmk-userspace, in `users/nedsi`.

## Target

`bastardkb/skeletyl/promicro`, with the handwired wiring carried in the keymap:

- `config.h` replaces the matrix pins (rows B1 B3 B2 B6, columns D4 C6 D7 E6
  B4), the diode direction (COL2ROW) and the split serial pin (D0).
- `keymap.c` fills the matrix itself (`LAYOUT_handwired`), because the thumbs
  are wired to columns 2-4 on both halves, unlike the upstream PCB.

## Build and flash

From a machine set up as described in the qmk-userspace README:

```sh
qmk compile -kb bastardkb/skeletyl/promicro -km nedsi
qmk flash   -kb bastardkb/skeletyl/promicro -km nedsi
```

Flash each half: run `qmk flash`, then press its reset button (Atmel DFU
bootloader on an Elite-C). Handedness is stored in EEPROM (`EE_HANDS`): on a
fresh controller, flash with `-bl dfu-split-left` / `dfu-split-right` once.
