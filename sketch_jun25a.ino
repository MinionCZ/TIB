#define ser 13
#define rclk 12
#define srclk 11
bool online = true;
bool numbers [10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, //0
  {0, 1, 1, 0, 0, 0, 0}, //1
  {1, 1, 0, 1, 1, 0, 1}, //2
  {1, 1, 1, 1, 0, 0, 1}, //3
  {0, 1, 1, 0, 0, 1, 1}, //4
  {1, 0, 1, 1, 0, 1, 1}, //5
  {1, 0, 1, 1, 1, 1, 1}, //6
  {1, 1, 1, 0, 0, 0, 0}, //7
  {1, 1, 1, 1, 1, 1, 1}, //8
  {1, 1, 1, 1, 0, 1, 1} //9
};
bool packet [32];
void setup() {
  // put your setup code here, to run once:
  pinMode(ser, OUTPUT);
  pinMode(rclk, OUTPUT);
  pinMode(srclk, OUTPUT);
  for (int i = 0; i < 32; i++) {
    packet[i] = false;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  zobraz("1234");
  delay(1000);
}
void zobraz(String cislo) {
  if (cislo.length() > 4) {
    return;
  }
  int pocitadlo = 0;
  for (int i = 0; i < cislo.length(); i++) {
    char ch = cislo.charAt(i);
    int cifra = (int)ch - 48;
    for (int j = 0; j < 7; j++) {
      packet[pocitadlo] = numbers[cifra][j];
      pocitadlo++;
    }
    packet[pocitadlo] = false;
    pocitadlo++;
  }
  digitalWrite(rclk, LOW);
  for (int i = 31; i >=0; i++) {
    digitalWrite(srclk, LOW);
    digitalWrite(ser, !packet[i]);
    digitalWrite(srclk, HIGH);
  }
  digitalWrite(rclk, HIGH);
}
