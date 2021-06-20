#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <DHT.h>
#include <stdlib.h>

// Project Files
#include <constants.h>

// Initialize stuff
Adafruit_SSD1306 display(OLED_SCREEN_WIDTH, OLED_SCREEN_HEIGHT, &Wire, OLED_RESET); // OLED DIsplay
DHT dht(DHT_PIN, DHT22); //DHT Temperature and Humidity sensor

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

void oled_printInterface(float temperature, float humidity, int lux, int moisture){
  // Settings for Display Text         
  // Print Temperature
  display.setCursor(OLED_TEMP_X_ICON, OLED_TEMP_Y);        
  display.print("Temp:");            
  display.setCursor(OLED_TEMP_X, OLED_TEMP_Y);
  display.print(temperature);

  // Print Humidity
  display.setCursor(OLED_HUM_X_ICON, OLED_HUM_Y);        
  display.print("Hum:");            
  display.setCursor(OLED_HUM_X, OLED_HUM_Y);
  display.print(humidity);

  // Print Brightness
  display.setCursor(OLED_LUX_X_ICON, OLED_LUX_Y);           
  display.print("Hell:");            
  display.setCursor(OLED_LUX_X, OLED_LUX_Y);
  display.print(lux);

  // Print Moisture
  display.setCursor(OLED_MOIS_X_ICON, OLED_MOIS_Y);           
  display.print("Mois:");            
  display.setCursor(OLED_MOIS_X, OLED_MOIS_Y);
  display.print(moisture);

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

////////////// DHT22 //////////////
float dht22_read_temp(){
    float temp = dht.readTemperature();
    if(isnan(temp)){
      Serial.println("Fehler beinm auslesen des Sensors(Temperature)");
      return -1;
    }
    return temp;
}

float dht22_read_humidity(){
    float hum = dht.readHumidity();
    if(isnan(hum)){
      Serial.println("Fehler beinm auslesen des Sensors (Humidity)");
      return -1;
    }
    return hum;
}


////////////// SETUP | LOOP //////////////
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_RED, OUTPUT); // Red LED
  digitalWrite(LED_RED, LOW);
  pinMode(LED_GREEN, OUTPUT); // Green LED
  digitalWrite(LED_GREEN, LOW);

  Serial.begin(BAUD_RATE);

  // Initialize OLED Display
  oled_initialize();
  // Initialize DHT22
  dht.begin();
}

void loop() {

  // OLED
  
  float temp = dht22_read_temp();
  int humidity = dht22_read_humidity();
  int lux = rand() % 99 +1;
  int mois = rand() % 99 +1;
  display.clearDisplay();
  oled_printHeadline("Plantwatching \\(^_^)/");
  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  oled_printInterface(temp, humidity, lux, mois);
  delay(REFRESH_TIME);
  

  /*
 // DHT22
    delay(2500);
    float h = dht.readHumidity();
    float t = dht.readTemperature();

    if (isnan(h) ||isnan(t)){
      Serial.println("Fehler beinm auslesen des Sensors");
      return;
    }
    Serial.print("Luftfeuchtigkeit: ");
    Serial.print(h);
    Serial.print("%\t");
    Serial.print("Temperatur: ");
    Serial.print(t);
    Serial.println("C");
    */
}