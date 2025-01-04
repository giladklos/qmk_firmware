#pragma once

#undef MASTER_LEFT
#undef EE_HANDS
#undef MASTER_RIGHT

#define SERIAL_USART_TX_PIN GP1

#ifdef POINTING_DEVICE_CONFIGURATION_TRACKPOINT_TRACKBALL
    #define MASTER_LEFT
    #define POINTING_DEVICE_ROTATION_90_RIGHT
#elif POINTING_DEVICE_CONFIGURATION_TRACKBALL_TRACKPOINT
    #define MASTER_RIGHT
    #define POINTING_DEVICE_ROTATION_270
#elif defined(POINTING_DEVICE_CONFIGURATION_TRACKPOINT_CIRQUE35) || defined(POINTING_DEVICE_CONFIGURATION_TRACKPOINT_CIRQUE40)
    #define MASTER_LEFT
#elif defined(POINTING_DEVICE_CONFIGURATION_CIRQUE35_TRACKPOINT) || defined(POINTING_DEVICE_CONFIGURATION_CIRQUE40_TRACKPOINT)
    #define MASTER_RIGHT
#elif defined(POINTING_DEVICE_CONFIGURATION_PIMORONI_CIRQUE35) || defined(POINTING_DEVICE_CONFIGURATION_PIMORONI_CIRQUE40)
    #define MASTER_RIGHT
    // The pimoroni needs frequest updates, set a value so the Cirque configs don't set it to 10ms.
    #define POINTING_DEVICE_TASK_THROTTLE_MS 1
    // A pimoroni on the left side can only go in this orientation.
    #define POINTING_DEVICE_ROTATION_270
#elif defined(POINTING_DEVICE_CONFIGURATION_CIRQUE35_PIMORONI) || defined(POINTING_DEVICE_CONFIGURATION_CIRQUE40_PIMORONI)
    #define MASTER_LEFT
    // The pimoroni needs frequest updates, set a value so the Cirque configs don't set it to 10ms.
    #define POINTING_DEVICE_TASK_THROTTLE_MS 1
    // Determine right side rotation based on POINTING_DEVICE_POSITION flag.
    #if POINTING_DEVICE_POSITION_THUMB_OUTER
      #define POINTING_DEVICE_ROTATION_270_RIGHT
    #elif defined(POINTING_DEVICE_POSITION_THUMB) || defined(POINTING_DEVICE_POSITION_THUMB_INNER)
    #else
       #define POINTING_DEVICE_ROTATION_90_RIGHT
    #endif
#elif POINTING_DEVICE_CONFIGURATION_PIMORONI_PIMORONI
    #define MASTER_RIGHT
    // A pimoroni on the left side can only go in this orientation.
    #define POINTING_DEVICE_ROTATION_270
    // Determine right side rotation based on POINTING_DEVICE_POSITION flag.
    #if POINTING_DEVICE_POSITION_THUMB_OUTER
      #define POINTING_DEVICE_ROTATION_270_RIGHT
    #elif defined(POINTING_DEVICE_POSITION_THUMB) || defined(POINTING_DEVICE_POSITION_THUMB_INNER)
    #else
       #define POINTING_DEVICE_ROTATION_90_RIGHT
    #endif
#elif POINTING_DEVICE_CONFIGURATION_PIMORONI
    #ifdef POINTING_DEVICE_POSITION_LEFT
        #define MASTER_LEFT
        #define POINTING_DEVICE_ROTATION_270
    #elif POINTING_DEVICE_POSITION_RIGHT
        #define MASTER_RIGHT
        #define POINTING_DEVICE_ROTATION_90
    #elif POINTING_DEVICE_POSITION_THUMB_OUTER
        #define MASTER_RIGHT
        #define POINTING_DEVICE_ROTATION_270
    #elif defined(POINTING_DEVICE_POSITION_THUMB) || defined(POINTING_DEVICE_POSITION_THUMB_INNER) || defined(POINTING_DEVICE_POSITION_MIDDLE)
        #define MASTER_RIGHT
    #endif
#elif defined(POINTING_DEVICE_CONFIGURATION_CIRQUE40) || defined(POINTING_DEVICE_CONFIGURATION_CIRQUE35) || defined(POINTING_DEVICE_CONFIGURATION_TRACKPOINT)
    #ifdef POINTING_DEVICE_POSITION_LEFT
        #define MASTER_LEFT
    #elif POINTING_DEVICE_POSITION_RIGHT
        #define MASTER_RIGHT
    #endif
#elif defined(POINTING_DEVICE_CONFIGURATION_CIRQUE40_CIRQUE40)
    #define MASTER_RIGHT
    #define POINTING_DEVICE_ROTATION_180
#else
    // No pointing device, default to right.
    #define MASTER_RIGHT
#endif


// Cirque 40mm on the left side of a split keyboard is rotated 180 degrees.
#if defined(POINTING_DEVICE_CONFIGURATION_CIRQUE40) && defined(POINTING_DEVICE_POSITION_LEFT)
    #define POINTING_DEVICE_ROTATION_180
#endif
#if defined(POINTING_DEVICE_CONFIGURATION_CIRQUE40_PIMORONI) || defined(POINTING_DEVICE_CONFIGURATION_CIRQUE40_TRACKPOINT)
    #define POINTING_DEVICE_ROTATION_180
#endif

// Generic Cirque configuration.
#ifdef POINTING_DEVICE_DRIVER_cirque_pinnacle_i2c
    #if defined(POINTING_DEVICE_CONFIGURATION_CIRQUE35) || defined(POINTING_DEVICE_CONFIGURATION_CIRQUE35_CIRQUE35) || defined(POINTING_DEVICE_CONFIGURATION_PIMORONI_CIRQUE35) || defined(POINTING_DEVICE_CONFIGURATION_CIRQUE35_PIMORONI) || defined(POINTING_DEVICE_CONFIGURATION_TRACKPOINT_CIRQUE35) || defined(POINTING_DEVICE_CONFIGURATION_CIRQUE35_TRACKPOINT)
        #define CIRQUE_PINNACLE_DIAMETER_MM 35
    #elif defined(POINTING_DEVICE_CONFIGURATION_CIRQUE40) || defined(POINTING_DEVICE_CONFIGURATION_CIRQUE40_CIRQUE40) || defined(POINTING_DEVICE_CONFIGURATION_PIMORONI_CIRQUE40) || defined(POINTING_DEVICE_CONFIGURATION_CIRQUE40_PIMORONI) || defined(POINTING_DEVICE_CONFIGURATION_TRACKPOINT_CIRQUE40) || defined(POINTING_DEVICE_CONFIGURATION_CIRQUE40_TRACKPOINT)
        #define CIRQUE_PINNACLE_DIAMETER_MM 40
    #else
        #error "Unknown Cirque configuration."
    #endif

    // Tap for left click.
    #define CIRQUE_PINNACLE_TAP_ENABLE
    // Corner tap for right click.
    // #define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE // Unfortunatly this doesn't seem to work.
    // Enable circular scroll.
    #define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
#endif

#ifdef POINTING_DEVICE_DRIVER_ps2
    // The default streaming mode is flaky and doesn't always work. This setting doesn't seem to affect performance.
    #define PS2_MOUSE_USE_REMOTE_MODE

    // Serial uses PIO0, change PS2 to PIO1.
    #define PS2_PIO_USE_PIO1

    #define PS2_MOUSE_INVERT_X
    #define PS2_MOUSE_INVERT_Y

    #define PS2_DATA_PIN    GP2
    #define PS2_CLOCK_PIN   GP3

    // Start faster when keyboard resets.
    #define PS2_MOUSE_INIT_DELAY 500
#endif

#ifdef OLED_ENABLE
    #define SPLIT_LAYER_STATE_ENABLE
#endif

#define RETRO_TAPPING

#define DUMMY_MOD_NEUTRALIZER_KEYCODE KC_RIGHT_CTRL

#define MODS_TO_NEUTRALIZE { MOD_BIT(KC_LEFT_ALT), MOD_BIT(KC_LEFT_GUI) }