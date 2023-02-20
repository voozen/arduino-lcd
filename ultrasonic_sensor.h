#define TRIG_PIN 9
#define ECHO_PIN 10

void ultrasonic_sensor() {
  long duration;
  int distance;
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;
  lcd.setCursor(0, 1);
  lcd.print("Distance in cm: ");
  lcd.setCursor(16, 1);
  lcd.print(distance);
  delay(250);
  lcd.clear();
}