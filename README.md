# Raspberry Pi Pico SSD1306 OLED Display

This repository contains a simple Arduino sketch demonstrating how to interface a Raspberry Pi Pico with a 128x64 I2C SSD1306 OLED display. It displays custom text ("Hello PICO" and "Here, I2c OLED") using the Adafruit graphics libraries.

## 🛠 Hardware Requirements

*   **Raspberry Pi Pico** (or Pico W)
*   **SSD1306 OLED Display** (128x64 resolution, I2C interface)
*   **Jumper wires** and a breadboard

## 🔌 Wiring Guide

This code uses specific custom I2C pins on the Raspberry Pi Pico (GP20 for SDA and GP21 for SCL). Connect your OLED to the Pico as follows:

| SSD1306 OLED Pin | Raspberry Pi Pico Pin | Description |
| :--- | :--- | :--- |
| **VCC** | **3V3(OUT)** (Pin 36) | 3.3V Power |
| **GND** | **GND** (Any Ground Pin) | Ground |
| **SDA** | **GP20** (Pin 26) | I2C Data |
| **SCL** | **GP21** (Pin 27) | I2C Clock |

## 📦 Software Dependencies

To run this code, you will need the Arduino IDE with Raspberry Pi Pico support installed, along with the following libraries (installable via the Arduino Library Manager):

1.  **Adafruit GFX Library**: Core graphics library for drawing text, lines, circles, etc.
2.  **Adafruit SSD1306**: Hardware-specific driver for the SSD1306 OLED.
3.  **Wire**: Built-in library for I2C communication.

## 🚀 How to Run

1.  Open the Arduino IDE and select your **Raspberry Pi Pico** board.
2.  Ensure you have installed the required Adafruit libraries.
3.  Copy the code into a new sketch.
4.  Compile and upload the sketch to your Pico.
5.  The OLED should instantly display "Hello PICO" followed by "Here, I2c OLED".

## 📝 Code Overview

*   `Wire.setSDA(20)` & `Wire.setSCL(21)`: Re-routes the default I2C pins to GP20 and GP21 on the Pico.
*   `display.begin(SSD1306_SWITCHCAPVCC, 0x3C)`: Initializes the display at I2C address `0x3C` (the most common address for these modules).
*   `display.setTextSize()` & `display.setCursor()`: Formats and positions the text on the 128x64 grid.
*   `display.display()`: Pushes the data from the buffer to the screen.
