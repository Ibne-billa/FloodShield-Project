#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// ---- LCD ----
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ---- Ultrasonic ----
#define TRIG_PIN 5
#define ECHO_PIN 18

// ---- DHT11 ----
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// ---- Water Sensor ----
#define WATER_SENSOR_PIN 34
int waterThreshold = 1500; // Adjust this value after testing

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  dht.begin();

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(WATER_SENSOR_PIN, INPUT);

  lcd.setCursor(0, 0);
  lcd.print("System Ready...");
  delay(2000);
  lcd.clear();
}

void loop() {
  // --- Ultrasonic ---
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  float distance = duration * 0.034 / 2;

  // --- DHT11 ---
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  // --- Water Sensor ---
  int waterValue = analogRead(WATER_SENSOR_PIN);
  String waterStatus = (waterValue > waterThreshold) ? "WET " : "DRY ";

  // --- Serial Output ---
  Serial.print("Distance: "); Serial.print(distance); Serial.print(" cm | ");
  Serial.print("Temp: "); Serial.print(temp); Serial.print(" C | ");
  Serial.print("Humidity: "); Serial.print(hum); Serial.print(" % | ");
  Serial.print("Water: "); Serial.print(waterValue);
  Serial.print(" | Status: "); Serial.println(waterStatus);

  // --- LCD Output ---
  lcd.clear();  // Clear full screen each time to prevent character overlap
  lcd.setCursor(0, 0);
  lcd.print("D:");
  lcd.print((int)distance);
  lcd.print(" T:");
  lcd.print((int)temp);
  lcd.print("C H:");
  lcd.print((int)hum);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("Water:");
  lcd.print(waterStatus);

  delay(1500);
}
