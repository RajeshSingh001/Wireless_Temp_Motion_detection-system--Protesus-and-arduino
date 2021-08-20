#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
}
void loop()
{
  if (Serial.available() < 1)  return;
  char R = Serial.read();
  if (R != '\r')                 return;
  int motion = Serial.parseInt();
  int temp = Serial.parseInt();
  Serial.print('\r');
  Serial.print(motion);
  Serial.print('|');
  Serial.print(temp);
  Serial.print('\n');
  if (motion == 1)
  {
    lcd.clear();
    lcd.print("motion occured");
    lcd.setCursor(0, 1);
    lcd.print("TEMP:");
    lcd.setCursor(6, 1);
    lcd.print(temp);
    delay(20);
  }
  else
  {
    lcd.clear();
    lcd.print(" no motion   ");
    lcd.setCursor(0, 1);
    lcd.print("TEMP:");
    lcd.setCursor(6, 1);
    lcd.print(temp);
    delay(20);
  }
}
