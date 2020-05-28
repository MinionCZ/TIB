#include <LiquidCrystal.h>
#define podsviceni 7
#define potenciometr A0
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
long posledniMillis = 0;
struct Hodiny {
  byte hodina;
  byte minuta;
  byte sekunda;
} cas;

void setup() {
  pinMode(7, OUTPUT);
  lcd.begin(16, 2);
  cas.hodina = 17;
  cas.minuta = 47;
  cas.sekunda = 0;
  digitalWrite(7, HIGH);
}

void loop() {
  lcd.setCursor(3, 0);
  lcd.print(cas.hodina);
  lcd.print(":");
  lcd.print(cas.minuta);
  lcd.print(":");
  lcd.print(cas.sekunda);
  tik();
  delay(1);
}
void tik() {
  if (millis() - posledniMillis >= 1000) {
    posledniMillis = millis();
    cas.sekunda++;
    if (cas.sekunda == 60) {
      cas.minuta++;
      cas.sekunda = 0;
      if (cas.minuta == 60) {
        cas.minuta = 0;
        cas.hodina++;
        if (cas.hodina == 24) {
          cas.hodina = 0;
        }
      }
    }
  }
}
