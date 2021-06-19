#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define OLED_RESET 4
#define OLED_ADDR 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void oled_printHeadline(String headline){
  display.setTextSize(1);             // The fontsize
  display.setTextColor(WHITE);        // Draw white text
  display.setCursor(0, 0);           // Start at top-left corner
  display.print(headline);       //the text
  display.display();
}

void oled_printInterface(){
  display.setTextSize(1);             // The fontsize
  display.setTextColor(WHITE);        // Draw white text
  //display.setCursor(0, 0); 
  //display.print("Temp.: 10 C");
  display.setCursor(0, 10);           // Start at top-left corner
  display.print("Temp.: 10 C");       //the text
  display.setCursor(0, 20);           // Start at top-left corner
  display.print("Hell.: 200Lux");       //the text
  display.display();                  //call to display
}

void led_ON(String led){
  if(led=="red"){
    digitalWrite(13, HIGH);
  }else if(led=="green"){
    digitalWrite(12, HIGH);
  }
}

void led_OFF(String led){
  if(led=="red"){
    digitalWrite(13, LOW);
  }else if(led=="green"){
    digitalWrite(12, LOW);
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

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT); // Red LED
  digitalWrite(13, LOW);
  pinMode(12, OUTPUT); // Green LED
  digitalWrite(12, LOW);

  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
   // initialize with the I2C addr 0x3D (for the 128x64)
  display.clearDisplay();
  delay(1500);
  oled_printHeadline("Hallo Welt!");
  delay(1500);
  oled_printInterface();
  delay(1500);
  oled_printHeadline("CIAO Welt!");
}

void loop() {
}