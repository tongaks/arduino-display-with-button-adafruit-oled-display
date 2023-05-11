#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "woof.h"

#define OLED_RESET 4
int button_display_pin = 3;
int buttonCount = 0;
int display_count = 2;
int display_option = 0;
int button_menu_pin = 2;
int focused = 1;
bool menu_focused = true;
Adafruit_SSD1306 display(OLED_RESET);

// void button_menu() {    
//   int buttonState = digitalRead(button_menu_pin);
//   if (buttonState == LOW) {
//     display_option ++;
//     focused = 1;
//     Serial.println(focused);
//   }

//   if (display_option == 1) {
//     display.clearDisplay();
//     display.drawBitmap(0, 0, display1, 132, 32, WHITE);
//     display.display();
//   } else if (display_option == 2) {
//     display.clearDisplay();
//     display.drawBitmap(0, 0, display2, 132, 32, WHITE);
//     display.display();
//   } else {
//     display_option = 0;
//   }
// }

// void displaying_images() {
//   int buttonState = digitalRead(button_display_pin);
//   if (buttonState == LOW) {
//     display_count ++;    
//     focused = 2;
//     Serial.println(focused);
//   }

//   if (display_count == 1) {
//     display.clearDisplay();
//     display.drawBitmap(0, 0, woof1, 132, 32, WHITE);
//     display.display();
//   } else if (display_count == 2) {
//     display.clearDisplay();
//     display.drawBitmap(0, 0, woof2, 132, 32, WHITE);
//     display.display();    
//   } else {
//     display_count = 0;
//   }
// }

void pinagsama() {    
  int button_menu_state = digitalRead(button_menu_pin);
  int button_display_state = digitalRead(button_display_pin);
  
  if (button_menu_state == LOW) {
    display_option ++;
    focused ++;
    menu_focused = true;
    Serial.println(focused);
  }

  if (display_option == 1 && menu_focused == true) {
    display.clearDisplay();
    display.drawBitmap(0, 0, display1, 132, 32, WHITE);
    display.display();
  } else if (display_option == 2 && menu_focused == true) {
    display.clearDisplay();
    display.drawBitmap(0, 0, display2, 132, 32, WHITE);
    display.display();
  } else {
    display_option = 0;
    focused = 0;
  }

  // if display button is clicked and focused is 1
  if (button_display_state == LOW && focused == 1) {
    menu_focused = false;
    display.clearDisplay();
    display.drawBitmap(0, 0, woof1, 132, 32, WHITE);
    display.display();
  } else if (button_display_state == LOW && focused == 2) {
    menu_focused = false;
    display.clearDisplay();
    display.drawBitmap(0, 0, woof2, 132, 32, WHITE);
    display.display();
  }
}

void setup()   { 
  Serial.begin(9600);
  pinMode(button_display_pin, INPUT_PULLUP);       
  pinMode(button_menu_pin, INPUT_PULLUP);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  display.display();
}


void loop() {
  pinagsama();
}


//by tongaks from https://github.com/tongaks/arduino-display-with-button-adafruit-oled-display