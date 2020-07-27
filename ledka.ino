void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(2) == 0){
    digitalWrite(13, HIGH);
  }else{
    digitalWrite(13, LOW);
  }
}
