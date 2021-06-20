// Constants.h
#if !defined(MYLIB_CONSTANTS_H)
#define MYLIB_CONSTANTS_H 1


////// OLED Display constants //////
static const int OLED_SCREEN_WIDTH = 128; // OLED display width, in pixels
static const int OLED_SCREEN_HEIGHT = 32; // OLED display height, in pixels
static const int OLED_RESET = 4; //Reset for OLED 
static const int OLED_ADDR = 0x3C; // Oled Address

// OLED Data positions on Display 
static const int OLED_TEMP_X = 35; // X Position for showing temperature
static const int OLED_TEMP_Y = 10; // Y Position for showing temperature
static const int OLED_TEMP_X_ICON = 0; // Y Position for showing temperature icon
static const int OLED_LUX_X = OLED_TEMP_X; // X Position for showing brightness
static const int OLED_LUX_Y = 20; // y Position for showing brightness
static const int OLED_LUX_X_ICON = 0; // Y Position for showing lux icon
static const int OLED_MOIS_X = 95; // X Position for showing brightness
static const int OLED_MOIS_Y = 20; // y Position for showing brightness
static const int OLED_MOIS_X_ICON = 64; // Y Position for showing temperature icon
static const int OLED_HUM_X = OLED_MOIS_X; // X Position for showing brightness
static const int OLED_HUM_Y = 10; // y Position for showing brightness
static const int OLED_HUM_X_ICON = 70; // Y Position for showing temperature icon


////// DHT22 Sensor //////
static const int DHT_PIN = 11; // Digital Pin for DHT22


////// LEDs //////
static const int LED_RED = 13; // Pin for red LED
static const int LED_GREEN = 12; // Pin for green LED

/////// Other ///////
static const int BAUD_RATE = 9600; //Baud Rate
static const int REFRESH_TIME = 5000; //Refresh time in ms

// Symbols needed later 
static const unsigned char symbol_moisture[] ={
   0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x00, 0x00,
   0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00,
   0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00,
   0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00,
   0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00,
   0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00,
   0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

static const unsigned char symbol_temperature[] ={
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

static const unsigned char symbol_brightness[] ={
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

#endif
