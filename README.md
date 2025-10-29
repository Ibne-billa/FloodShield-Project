# 🌊 Flood Shield – ESP32 Flood Detection System

**Flood Shield** is an IoT-based flood detection and monitoring system built using an **ESP32**, **DHT11 sensor**, **Ultrasonic sensor**, and a **Water Level sensor**.  
The project provides real-time feedback on **temperature**, **humidity**, **distance (water level)**, and **flood risk** using a **16x2 I2C LCD display**.

---

## ⚙️ Features
- 🌡️ Measures temperature and humidity using the **DHT11** sensor.  
- 📏 Detects water level via an **ultrasonic sensor** (JSN-SR04T or HC-SR04).  
- 💧 Detects moisture/flooding using a **water level sensor**.  
- 🖥️ Displays real-time readings and flood warnings on a **16x2 LCD screen**.  
- 🔍 Outputs all readings through **Serial Monitor** for debugging or data logging.  

---

## 🧩 Hardware Components
| Component | Quantity | Description |
|------------|-----------|-------------|
| ESP32 DevKit V4 | 1 | Main controller board |
| DHT11 Sensor | 1 | Measures temperature and humidity |
| JSN-SR04T / HC-SR04 Ultrasonic Sensor | 1 | Measures distance to water surface |
| Water Level Sensor | 1 | Detects presence of water |
| 16x2 I2C LCD | 1 | Displays system data |
| Jumper Wires | — | For connections |
| Breadboard / PCB | 1 | Optional for prototyping |

---

## 🧠 Working Principle
The ESP32 continuously reads data from three sensors:
1. **Ultrasonic Sensor** → Detects distance to water surface to estimate level.
2. **DHT11 Sensor** → Provides temperature and humidity data.
3. **Water Sensor** → Determines if water is present (wet/dry condition).  

All the readings are shown on an LCD and printed in the Serial Monitor. If the water level or moisture crosses a set threshold, it indicates potential flooding.

---

## 🧰 Libraries Used
```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
```

Install these libraries from the Arduino Library Manager before uploading.

---

## 🔧 Pin Connections (ESP32)
| Module | ESP32 Pin | Description |
|--------|------------|-------------|
| Ultrasonic TRIG | D5 | Trigger pin |
| Ultrasonic ECHO | D18 | Echo pin |
| DHT11 | D4 | Data pin |
| Water Sensor | D34 | Analog input |
| LCD (I2C) | SDA/SCL | Default ESP32 I2C pins (21/22) |

---

## 🖼️ LCD Display Layout
```
D:12 T:29C H:72%
Water:WET
```
**D** = Distance (cm)  
**T** = Temperature (°C)  
**H** = Humidity (%)  
**Water** = Wet/Dry Status  

---

## ⚙️ Calibration
Adjust the water sensor threshold:
```cpp
int waterThreshold = 1500; // Tune based on test readings
```
Increase or decrease this value depending on your sensor’s output in dry/wet conditions.

---

## 🚀 Future Improvements
- Add **Wi-Fi alerts** via ESP32 web server or mobile notification.  
- Store readings on a cloud dashboard (Firebase or ThingSpeak).  
- Include a **buzzer or relay** for automatic flood alerts.  
- Use **solar power** for self-sustained flood monitoring in remote areas.  
- Add **AI-based water level prediction** using collected data.  

---

## 👨‍💻 Authors
- **Waleed Ajmal** – Robotics & IoT Developer, ESP32 and hardware integration.  
- **Saad Farooq** – System design, debugging, and data optimization.

---

## 🏷️ Tags
`#ESP32` `#IoT` `#FloodDetection` `#Arduino` `#DHT11` `#UltrasonicSensor` `#WaterSensor` `#LCD` `#Robotics` `#ClimateTech`
