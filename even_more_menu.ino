#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "woof.h"

#define OLED_RESET 4
int button_menu_pin = 2;
int button_image_pin = 3;
bool isMenu = true;
int item_count = 1;
int focused_item = 1;

Adafruit_SSD1306 display(OLED_RESET);

void more_menu() {
  int button_menu_state = digitalRead(button_menu_pin);
  int button_image_state = digitalRead(button_image_pin);

  //Menu
  if (button_menu_state == LOW) {
    item_count ++;
    focused_item ++;
    isMenu = true;
  } else if (item_count > 4) {
    item_count = 0;
  } else if (focused_item > 5) {
    focused_item = 0;
  }

  if (item_count == 1 && isMenu == true) {
    display.clearDisplay();
    display.drawBitmap(0, 0, item1, 132, 32, WHITE);
    display.display();
  } else if (item_count == 2 && isMenu == true) {
    display.clearDisplay();
    display.drawBitmap(0, 0, item2, 132, 32, WHITE);
    display.display();    
  }  else if (item_count == 3 && isMenu == true) {
    display.clearDisplay();
    display.drawBitmap(0, 0, item3, 132, 32, WHITE);
    display.display();    
  }  else if (item_count == 4 && isMenu == true) {
    display.clearDisplay();
    display.drawBitmap(0, 0, item4, 132, 32, WHITE);
    display.display();    
  }

  //Images
  if (button_image_state == LOW && focused_item == 2) {
    isMenu = false;
    display.clearDisplay();
    display.drawBitmap(0, 0, gif_uwu, 132, 32, WHITE);
    display.display();
    delay(1000);
    display.clearDisplay();
    display.drawBitmap(0, 0, gif_owo, 132, 32, WHITE);
    display.display();
    delay(1000);
  } else if (button_image_state == LOW && item_count == 3) {
    isMenu = false;
    display.clearDisplay();
    display.drawBitmap(0, 0, woof1, 132, 32, WHITE);
    display.display();
  } else if (button_image_state == LOW && item_count == 4) {
    isMenu = false;
    display.clearDisplay();
    display.drawBitmap(0, 0, woof2, 132, 32, WHITE);
    display.display();
  }
}

void setup() {
  Serial.begin(9600);       
  pinMode(button_menu_pin, INPUT_PULLUP);
  pinMode(button_image_pin, INPUT_PULLUP);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  display.display();
}


void loop() {
  more_menu();
}


//by tongaks from https://github.com/tongaks/arduino-display-with-button-adafruit-oled-display