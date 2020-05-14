int piny[8];
bool blik = false;
bool sviti = false;
uint32_t posledniMillis = millis();
void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 8; i++) {
    piny[i] = i + 6;
    pinMode(piny[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() != 0) {
    char ch = (char) Serial.read();
    switch (ch) {
      case 'r':
        rozsvit(8);
        break;
      case 'z':
        zhasni();
        break;
      case 'b':
        blik = !blik;
        break;
      default:
        break;
    }
  }
  blikej();
  delay(1);
}
void rozsvit(uint8_t pocetLedek) {
  for (uint16_t i = 0; i < 8; i++) {
    digitalWrite(piny[i], i < pocetLedek);
  }
}
void zhasni() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(piny[i], LOW);
  }
}
void blikej() {
  if (!blik) {
    return;
  }
  if (abs(millis() - posledniMillis) >= 1000) {
    posledniMillis = millis();
    sviti = !sviti;
    if (sviti) {
      rozsvit(8);
    } else {
      zhasni();
    }
  }
}



