# Copyright 2022 LucW (@luc-languagetools)
# SPDX-License-Identifier: GPL-2.0-or-later

# SPLIT_KEYBOARD = yes
# USE_SERIAL = yes
SERIAL_DRIVER = vendor
MOUSEKEY_ENABLE = yes    # Mouse keys
RGBLIGHT_ENABLE = yes    # Enable WS2812 RGB underlight.
RGB_MATRIX_ENABLE = no
OLED_ENABLE     = no
OLED_DRIVER     = SSD1306
# LTO_ENABLE      = yes
SRC += features/achordion.c
MCU = RP2040
# CONVERT_TO = kb2040
