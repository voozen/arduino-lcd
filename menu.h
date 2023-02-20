int choice = 1;
bool option_chosen = false;
bool menu_flag = false;

void menu() {
  while (!menu_flag) {
    lcd.clear();
    lcd.noBlink();
    char w1[16] = {"1. Motion sensor"};
      for (int i = 0; i < 16; i++) {
        lcd.setCursor(i, 0);
        lcd.print(w1[i]);
        delay(50);
      }
    char w2[20] = {"2. Ultrasonic sensor"};
    for (int i = 0; i < 20; i++) {
      lcd.setCursor(i, 1);
      lcd.print(w2[i]);
      delay(50);
    }
    char w3[16] = {"Current option: "};
    for (int i = 0; i < 15; i++) {
      lcd.setCursor(i, 2);
      lcd.print(w3[i]);
      delay(50);
    }
    lcd.setCursor(16, 2);
    lcd.print(String(choice));
    while (!option_chosen) {
      Serial.println(check_push(BUTTON_PIN1));
      if (check_push(BUTTON_PIN1) == 1) {
        choice = 1;
        lcd.setCursor(0, 2);
        lcd.print("Current option: ");
        lcd.setCursor(16, 2);
        lcd.print(String(choice));
      }
      if (check_push(BUTTON_PIN2) == 1) {
        choice = 2;
        lcd.setCursor(0, 2);
        lcd.print("Current option: ");
        lcd.setCursor(16, 2);
        lcd.print(String(choice));
      }
      if (check_push(BUTTON_PIN3) == 1) {
        option_chosen = true;
        menu_flag = true;
        lcd.clear();
      }
    }
  }
}