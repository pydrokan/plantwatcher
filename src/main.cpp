#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
# include <stdlib.h>

// Project Files
#include <constants.h>

// Initialize stuff
Adafruit_SSD1306 display(OLED_SCREEN_WIDTH, OLED_SCREEN_HEIGHT, &Wire, OLED_RESET);

////////////// OLED DISPLAY //////////////
void oled_initialize(){
    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
      Serial.println(F("SSD1306 allocation failed"));
      for(;;); // Don't proceed, loop forever
    }
    display.setTextSize(1);
    display.setTextColor(WHITE);
}

void oled_printHeadline(String headline){
  // Clear Display 
  display.setCursor(0, 0);           // Start at top-left corner
  display.print(headline);       //the text
  display.display();
}

void oled_printInterface(int temp, int lux, int mois){
  // Settings for Display Text         
  // Print Temperature
  display.setCursor(OLED_TEMP_X_ICON, OLED_TEMP_Y);        
  display.print("Temp:");            
  display.setCursor(OLED_TEMP_X, OLED_TEMP_Y);
  display.print(temp);

  // Print Brightness
  display.setCursor(OLED_LUX_X_ICON, OLED_LUX_Y);           
  display.print("Hell:");            
  display.setCursor(OLED_LUX_X, OLED_LUX_Y);
  display.print(lux);

  // Print Moisture
  display.setCursor(OLED_MOIS_X_ICON, OLED_MOIS_Y);           
  display.print("Mois:");            
  display.setCursor(OLED_MOIS_X, OLED_MOIS_Y);
  display.print(mois);

  //Call to Display
  display.display();              
}

////////////// LEDs //////////////
void led_ON(String led){
  if(led=="red"){
    digitalWrite(LED_RED, HIGH);
  }else if(led=="green"){
    digitalWrite(LED_GREEN, HIGH);
  }
}

void led_OFF(String led){
  if(led=="red"){
    digitalWrite(LED_RED, LOW);
  }else if(led=="green"){
    digitalWrite(LED_GREEN, LOW);
  }
}

void test_led(){
  int delaytime = 500;
  led_ON("red");
  delay(delaytime);
  led_ON("green");
  delay(delaytime);
  led_OFF("red");
  delay(delaytime);
  led_OFF("green");
  delay(delaytime);
}

////////////// SETUP | LOOP //////////////
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_RED, OUTPUT); // Red LED
  digitalWrite(LED_RED, LOW);
  pinMode(LED_GREEN, OUTPUT); // Green LED
  digitalWrite(LED_GREEN, LOW);

  Serial.begin(BAUD_RATE);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  oled_initialize();


}

void loop() {
  int temp = rand() % 99+1;
  int lux = rand() % 99 +1;
  int mois = rand() % 99 +1;
  display.clearDisplay();
  oled_printHeadline("Plantwatching \\(^_^)/");
  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  oled_printInterface(temp, lux, mois);
  delay(REFRESH_TIME);
  
}