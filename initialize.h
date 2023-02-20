LiquidCrystal_I2C lcd(0x27, 20, 4);

int x = 0;
int y = 0;
int var = 0;
int steps_count = 0;
bool initialized = false;

void initialize() {
  if (!initialized) {
    for (int i = 0; i < 3; i++) {
      lcd.setCursor(4, 1);
      lcd.print("Initializing");
      lcd.setCursor(8, 2);
      lcd.print(".");
      delay(250);
      lcd.setCursor(9, 2);
      lcd.print(".");
      delay(250);
      lcd.setCursor(10, 2);
      lcd.print(".");
      delay(250);
      lcd.setCursor(11, 2);
      lcd.print(".");
      delay(250);
      lcd.clear();
    }
    initialized = true;
  }
  while (steps_count != 4) {
    uint8_t block_char[8] = {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
    lcd.createChar(0, block_char);
    if (var == 0) {
      lcd.setCursor(x, y);
      lcd.print((char)0);
      delay(5);
      x++;
      if (x == 19) {
        lcd.print((char)0);
        var = 1;
        y++;
        steps_count++;
      }
    }
    if (var == 1) {
      lcd.setCursor(x, y);
      lcd.print((char)0);
      delay(5);
      x--;
      if (x == -1) {
        lcd.print((char)0);
        var = 0;
        y++;
        steps_count++;
      }
    }
    if (steps_count == 4) {
      delay(250);
      lcd.clear();
    }
  }
}

bool greeted = false;

void welcome() {
  if (!greeted) {
    lcd.blink();
    delay(1500);
    lcd.home();
    char w1[10] = {"Welcome to"};
    for (int i = 0; i < 10; i++) {
      lcd.setCursor(i, 0);
      lcd.print(w1[i]);
      delay(50);
    }
    lcd.setCursor(0, 1);
    char w2[10] = {"my program"};
    for (int i = 0; i < 10; i++) {
      lcd.setCursor(i, 1);
      lcd.print(w2[i]);
      delay(50);
    }
    delay(1500);
    lcd.clear();
    lcd.home();
    char w3[14] = {"What would you"};
    for (int i = 0; i < 14; i++) {
      lcd.setCursor(i, 0);
      lcd.print(w3[i]);
      delay(50);
    }
    char w4[11] = {"like to do?"};
    for (int i = 0; i < 11; i++) {
      lcd.setCursor(i, 1);
      lcd.print(w4[i]);
      delay(50);
    }
    greeted = true;
    delay(1500);
    lcd.clear();
  }
}
