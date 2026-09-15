#include <Wire.h>                 // Enables I2C communication
#include <Adafruit_GFX.h>         // Graphics functions for the OLED
#include <Adafruit_SSD1306.h>     // SSD1306 OLED driver

#define SCREEN_WIDTH 128          // OLED width is 128 pixels
#define SCREEN_HEIGHT 64          // OLED height is 64 pixels

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1); // Create OLED object

void setup() {
  Wire.setSDA(20);                 // Use Pico GP0,GP4,GP16,GP20 for SDA
  Wire.setSCL(21);                 // Use Pico GP1,GP5,GP17,GP21 for SCL
  Wire.begin();                   // Start I2C

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Start OLED at address 0x3C
    while (true);                  // Stop if OLED is not found
  }

  display.clearDisplay();          // Clear the OLED screen
  display.setTextSize(2);          // Make text bigger
  display.setTextColor(SSD1306_WHITE); // Make text white
  display.setCursor(2, 20);       // Set text position
  display.println("Hello PICO");
  display.setTextSize(1);   
  display.setCursor(2,40); 
  display.println("Here, I2c OLED");          // Write Hello
  display.display();               // Actually send the text to OLED
}

void loop() {
  // Nothing needed here
}