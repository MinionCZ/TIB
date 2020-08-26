#define red 3
#define blue 5
#define green 6


void setup() {
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(green, LOW);
  digitalWrite(red, HIGH);
  delay(1000);
  digitalWrite(red, LOW);
  digitalWrite(blue, HIGH);
  delay(1000);
  digitalWrite(blue, LOW);
  digitalWrite(green, HIGH);
  delay(1000);

}
