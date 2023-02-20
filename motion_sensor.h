#define SENSOR_PIN 8

int state = LOW;
int val = 0;

void motion_sensor() {
  val = digitalRead(SENSOR_PIN);
  if (val == HIGH) {         
    delay(100);                
    if (state == LOW) {
      lcd.clear();
      lcd.setCursor(2, 1);
      lcd.print("Motion detected!");
      state = HIGH;     
    }
  } 
  else {
    delay(100);              
    if (state == HIGH){
      lcd.clear();
      lcd.setCursor(2, 1);
      lcd.print("Motion stopped!");
      state = LOW; 
    }
  }
}