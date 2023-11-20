# ErgoDox EZ

QMK configurator: https://config.qmk.fm/
QMK docs: https://docs.qmk.fm/

Keyboard layout editor: http://www.keyboard-layout-editor.com/#/

Where keys are place on different keyboard types: https://github.com/qmk/qmk_firmware/blob/master/docs/faq_keymap.md (ISO is default)

Key codes: https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
Macro definition: https://beta.docs.qmk.fm/using-qmk/advanced-keycodes/feature_macros

## Setup
Install dependencies
```
brew tap osx-cross/avr
brew install avr-gcc
```
Install teensy loader to load keymap into Ergodox: `https://www.pjrc.com/teensy/loader_mac.html`


## Build
The Ez uses the [Teensy Loader](https://www.pjrc.com/teensy/loader_mac.html).

Built firmware is placed in the root of this repo `~/Projects/davidulander/qmk_firmware` (might not be visable i VS Code for some reason)
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
