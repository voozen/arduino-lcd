#include "includes.h"
#include "initialize.h"
#include "buttons.h"
#include "menu.h"
#include "motion_sensor.h"
#include "ultrasonic_sensor.h"

void setup() {
  pinMode(BUTTON_PIN1, INPUT_PULLUP);
  pinMode(BUTTON_PIN2, INPUT_PULLUP);
  pinMode(BUTTON_PIN3, INPUT_PULLUP);
  pinMode(SENSOR_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT); 
  lcd.init();
  lcd.clear();
  lcd.backlight();
}

void loop() {
  initialize();
  welcome();
  menu();
  if (choice == 1) motion_sensor();
  else ultrasonic_sensor();
}