#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int motionsensor=7;
int temperaturesensor=A0;
void setup() 
{
 lcd.begin(16,2); 
 pinMode(motionsensor, INPUT);
 Serial.begin(9600);
}

void loop() 
{
 int motion=digitalRead(motionsensor);
 int temp1=analogRead(temperaturesensor);
 int temp=temp1/2;
if (motion==HIGH)
{
 lcd.clear();
 lcd.print("Motion Occured");
 lcd.setCursor(0,1);
 lcd.print("TEMP:");
 lcd.setCursor(6,1);
 lcd.print(temp);
 Serial.print('\r');
 Serial.print(motion);
 Serial.print('|');
 Serial.print(temp);
 Serial.print('\n');
 delay(20);
}
else
{
 lcd.clear();
 lcd.print(" no fire ");
 lcd.clear();
 lcd.print("No Motion   ");
 lcd.setCursor(0,1);
 lcd.print("TEMP:");
 lcd.setCursor(6,1);
 lcd.print(temp);
 Serial.print('\r');
 Serial.print(motion);
 Serial.print('|');
 Serial.print(temp);
 Serial.print('\n');
 delay(20);
 }

}
