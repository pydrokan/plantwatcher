#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <DHT.h>
#include <BH1750.h>
#include <stdlib.h>

// Project Files
#include <constants.h>

// Initialize stuff
Adafruit_SSD1306 display(OLED_SCREEN_WIDTH, OLED_SCREEN_HEIGHT, &Wire, OLED_RESET); // OLED DIsplay
DHT dht(DHT_PIN, DHT22); //DHT Temperature and Humidity sensor
BH1750 gy30(GY30_ADDR); 

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

void oled_printInterface(float temperature, float humidity, int lux, float moisture){
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

////////////// BH1750 GY30 //////////////
void gy30_initialize(){
  if (gy30.begin(BH1750::CONTINUOUS_HIGH_RES_MODE)) {
    Serial.println(F("BH1750 Advanced begin"));
  }
  else {
    Serial.println(F("Error initialising BH1750"));
  }
}

float gy30_measure_lux(){
    if (gy30.measurementReady()) {
      return gy30.readLightLevel();
    }
    return -1;
}

////////////// Soil Moisture Sensor //////////////
float moist_read_voltage(){
  Serial.print("Soil Moisture Sensor Voltage: ");
  Serial.print((float(analogRead(MOIST_PIN))/1023.0)*3.3); // read sensor
  Serial.println(" V");
  return (float(analogRead(MOIST_PIN))/1023.0)*3.3;
}

float moist_calibrated_reading(){
    float voltage, vol_water_cont; // preallocation
    voltage = moist_read_voltage();
    vol_water_cont = ((1.0/voltage)*MOIST_SLOPE)+MOIST_INTERCEPT; 
    return vol_water_cont;
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
  // Initialize GY30
  gy30_initialize();
}

void loop() {
  // OLED
  float temp = dht22_read_temp();
  float humidity = dht22_read_humidity();
  int lux = gy30_measure_lux();
  float mois = moist_read_voltage();
  display.clearDisplay();
  oled_printHeadline("Plantwatching \\(^_^)/");
  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  oled_printInterface(temp, humidity, lux, mois);
  delay(REFRESH_TIME);

}