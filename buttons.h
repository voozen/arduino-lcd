#define BUTTON_PIN1 2
#define BUTTON_PIN2 4
#define BUTTON_PIN3 7

int check_push(int pin) {
  int buttonState = digitalRead(pin);
  if (buttonState == 0) {
      return 1;
  }
  delay(100);
}