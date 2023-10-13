
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int moisture = A0;
int led_green = 13;
int led_red = 6;
int led_yellow = 10;
int moisture_value = 0;


void setup()
 {
  lcd.begin(16, 2);
  lcd.setCursor(4,0);
  lcd.print("welcome");
  lcd.setCursor(1,1);
  lcd.print("Irrigation S/m");
  Serial.begin(9600);
  pinMode(led_green,OUTPUT);
  pinMode(led_red,OUTPUT);
  pinMode(led_yellow,OUTPUT);

  digitalWrite(led_red,LOW);
  digitalWrite(led_green,LOW);
  digitalWrite(led_yellow,LOW);
 }

void loop() {
 delay(3000);
 moisture_value=analogRead(moisture);
 Serial.println(moisture_value);
 if(moisture_value>900)
 {
  digitalWrite(led_red,HIGH);
  digitalWrite(led_yellow,LOW);
  digitalWrite(led_green,LOW);
  lcd.clear();
  lcd.print("Soil is dry");
  lcd.setCursor(0,1);
  lcd.print("Water Please");

 }
 else if(moisture_value>600)
 {
  digitalWrite(led_red,LOW);
  digitalWrite(led_yellow,HIGH);
  digitalWrite(led_green,LOW);
  lcd.clear();
  lcd.print("Soil is Moderate");
  lcd.setCursor(0,1);
  lcd.print("Its good");
 }
 else
 {
  digitalWrite(led_red,LOW);
  digitalWrite(led_yellow,LOW);
  digitalWrite(led_green,HIGH);
  lcd.clear();
  lcd.print("Soil is wet");
  lcd.setCursor(0,1);
  lcd.print("No Worries");
 }
}
