int piny[8];
bool blik = false;
bool sviti = false;
uint32_t posledniMillis = millis();
String hi = "Ahoj";

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 8; i++) {
    piny[i] = i + 6;
    pinMode(piny[i], OUTPUT);
  }
  Serial.begin(9600);
  Serial.println(hi);
}

void loop() {
  // put your main code here, to run repeatedly:
  String s = prectiString();
  if(!s.equals("")){
    Serial.println(s);
    vyhodnot(s);
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
String prectiString(){
  if(Serial.available() == 0){
    return "";
  }
  String packet = "";
  int pocitadlo = 0;
  while(pocitadlo<Serial.available()){
    pocitadlo = Serial.available();
    delay(2);
  }
  while(Serial.available()!=0){
    packet += (char)Serial.read();
  }
  return packet;
}
void vyhodnot(String prikaz){
  if(prikaz.length()<2){
    Serial.println("Error");
    return;
  }
  if(prikaz.length()==2 && prikaz.equals("AT")){
    Serial.println("OK");
    return;
  }
  String atHlavicka = prikaz.substring(0, 3);
  if(atHlavicka.equals("AT+")){
    prikaz.remove(0,3);
    if(prikaz.equals("ON")){
      rozsvit(8);
    }else if(prikaz.equals("OFF")){
      zhasni();
    }
    
  }else{
    Serial.println("Error");
  }
  
  
}
