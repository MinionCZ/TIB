# TIB
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
  lcd.begin(16, 2);
  cas.hodina = 17;
  cas.minuta = 47;
  cas.sekunda = 0;
}

void loop() {
  lcd.setCursor(3, 0);


}
void tik() {
  if (millis() - posledniMillis >= 1000) {
    cas.sekunda++;
    if (sekunda == 60) {
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


