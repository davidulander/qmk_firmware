# ErgoDox EZ

QMK configurator: https://config.qmk.fm/
QMK docs: https://docs.qmk.fm/

Keyboard layout editor: http://www.keyboard-layout-editor.com/#/

Where keys are place on different keyboard types: https://github.com/qmk/qmk_firmware/blob/master/docs/faq_keymap.md (ISO is default)

## Setup
install avr-gcc `brew install avr-gcc@8`
install teensy loader: `https://www.pjrc.com/teensy/loader_mac.html`



## Build
The Ez uses the [Teensy Loader](https://www.pjrc.com/teensy/loader.html).


Own firmware is placed in: `~/Projects/davidulander/qmk_firmware`
Build with: `make ergodox_ez:david_osx`

To flash the firmware:

  - Build the firmware with `make <keyboardname>:<keymapname>`, for example `make ergodox_ez:default`

  - This will result in a hex file called `ergodox_ez_keymapname.hex`, e.g.
    `ergodox_ez_default.hex`

  - Start the teensy loader.

  - Load the .hex file into it.

  - Press the Reset button by inserting a paperclip gently into the reset hole
    in the top right corner.

  - Click the button in the Teensy app to download the firmware.

See also [video demonstration](https://www.youtube.com/watch?v=9PyiGUO9_KQ) using Teensy in auto mode.

## Settings

You may want to enable QMK_KEYS_PER_SCAN because the Ergodox has a relatively
slow scan rate.
