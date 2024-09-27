#include <Wire.h>
#include <U8g2lib.h>
#include "avdweb_Switch.h"

#define OLED_RESET -1 // No reset pin used for U8g2
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

const byte buttonPin = 7;
int i = 0;
bool isButtonReleased = true;  // To track if the button is released

Switch button = Switch(buttonPin);  // Switch between a digital pin and GND

void setup() {
  Serial.begin(115200);
  
  // Initialize the OLED object
  u8g2.begin();
  u8g2.setFont(u8g2_font_ncenB08_tr);  // Use a default font
  
}

void loop() {
  button.poll();
  
  // Clear the display buffer
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);  // Set font size for consistency

  if (button.pushed()) {
    u8g2.setCursor(45, 35);
    u8g2.print("Pushed ");
    u8g2.print(++i);
    u8g2.sendBuffer();
    isButtonReleased = false;  // Button was just pressed
  }

  if (button.longPress()) {
    u8g2.setCursor(45, 35);
    u8g2.print("Long Press");
    u8g2.sendBuffer();
    isButtonReleased = false;  // Button was just pressed
  }

  if (button.doubleClick()) {
    u8g2.setCursor(45, 35);
    u8g2.print("Double Click");
    u8g2.sendBuffer();
    isButtonReleased = false;  // Button was just pressed
  }

  if (button.released()) {
    u8g2.setCursor(45, 35);
    u8g2.print("Released");
    u8g2.sendBuffer();
    isButtonReleased = true;  // Button is released
  }

}
