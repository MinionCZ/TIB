# TIB
#include <LiquidCrystal.h>
#define podsviceni 7
LiquidCrystal lcd(13,12,11,10,9,8);

void setup() {
lcd.begin(16, 2);
pinMode(podsviceni, 7);
digitalWrite(podsviceni, HIGH);

}

void loop() {
lcd.setCursor(0,0);
  lcd.print("Ahoj");
}
