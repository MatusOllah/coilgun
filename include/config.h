#ifndef CONFIG_H
#define CONFIG_H

// OLED display config
#define SCREEN_ADDRESS 0x3C

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET -1

// Button config
#define BACK_BUTTON_PIN 12 // D6
#define FORWARD_BUTTON_PIN 13 // D7
#define TRIGGER_BUTTON_PIN 15 // D8

// Relay config
#define RELAY_PIN 14 // D5

// Duration config
#define DEFAULT_DURATION 200
#define DURATION_STEP 50

#endif
