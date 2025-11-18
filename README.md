# QMK Userspace

This is a template repository which allows for an external set of QMK keymaps to be defined and compiled. This is useful for users who want to maintain their own keymaps without having to fork the main QMK repository.

## Howto configure your build targets

1. Run the normal `qmk setup` procedure if you haven't already done so -- see [QMK Docs](https://docs.qmk.fm/#/newbs) for details.
1. Fork this repository
1. Clone your fork to your local machine using ssh
1. Enable userspace in QMK config using `qmk config user.overlay_dir="$(realpath qmk_userspace)"`
1. Add a new keymap for your board using `qmk new-keymap`
    * This will create a new keymap in the `keyboards` directory, in the same location that would normally be used in the main QMK repository. For example, if you wanted to add a keymap for the Planck, it will be created in `keyboards/planck/keymaps/<your keymap name>`
    * You can also create a new keymap using `qmk new-keymap -kb <your_keyboard> -km <your_keymap>`
    * Alternatively, add your keymap manually by placing it in the location specified above.
1. Add default keyboard and keymap
    ```bash
    qmk config user.keyboard=lily58
    qmk config user.keymap=<github_username>
    ```

1. Add your keymap(s) to the build by running `qmk userspace-add -kb <your_keyboard> -km <your_keymap>`
    * This will automatically update your `qmk.json` file
    * Corresponding `qmk userspace-remove -kb <your_keyboard> -km <your_keymap>` will delete it
    * Listing the build targets can be done with with `qmk userspace-list`

1. Commit your changes

## Blok Flashing
1. Within `rules.mk`, add the following:
    ```
    BOOTLOADER = rp2040
    CONVERT_TO = blok
    ```
1. Within `config.h`, the following line adds the option to double tap `RESET` to enter bootloader
    ```C
    #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
    ```
    Otherwise, must hold the boot key (left button on MCU) when pluggin into PC.

1. Must compile using 
    ```bash
    qmk compile -e CONVERT_TO=blok
    ```
    If default paths aren't set, the full command is 
    ```bash
    qmk compile -kb <keyboard> -km <keymap> -e CONVERT_TO=blok
    ```
    Take the `.uf2` file and copy to board
As far as I know, the workflow on github doesn't work, but could just need some updating.