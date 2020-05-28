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
  Serial.begin(9600);
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
  nastaveni();
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
void nastaveni() {
  if (Serial.available() == 0) {
    return;
  }
  String s = "";
  while (Serial.available() > 0) {
    s += (char) Serial.read();
  }
  int vysledek = over(s);
  switch (vysledek) {
    case -1:
      Serial.println("Error");
      return;
    case 1:
      // to do
      break;
    case 2:
      Serial.println(vratInfo(s));
      break;
    default:
      break;
  }

}
/*
   param prikaz - textovy retezec od uzivatele
   return pokud je prikaz nespravny -> -1
          pokud je prikaz set -> 1
          pokud je prikaz get -> 2
*/
int over(String prikaz) {
  if (prikaz.length() >= 3) {
    String substr = prikaz.substring(0, 3);
    if (substr.equals("set")) {
      return 1;
    } else if (substr.equals("get")) {
      return 2;
    } else {
      return -1;
    }
  } else {
    return -1;
  }
}
/*
   param prikaz - string co se ma udelat
   return String -> pokud je prikaz time -> cas
                 -> pokud je prikaz text -> text
                 -> pokud neco jineho -> error
*/

String vratInfo(String prikaz) {
  String substr = prikaz.substring(3);
  if (substr.length() != 4) {
    return "Error";
  }
  if (substr.equals("text")) {
    return "Donde esta la biblioteca?";
  } else if (substr.equals("time")) {
    String tim = "";
    tim += cas.hodina;
    tim += ":";
    tim += cas.minuta;
    tim += ":";
    tim += cas.sekunda;
    return tim;
  } else {
    return "Error";
  }

}
