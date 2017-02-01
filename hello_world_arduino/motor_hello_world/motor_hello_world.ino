// a hello world for the motors
void setup() {
  // put your setup code here, to run once:
  pinMode(12,OUTPUT);
  pinMode(9,OUTPUT);

  pinMode(13,OUTPUT);
  pinMode(8,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(12,HIGH);
  digitalWrite(9,LOW);
  analogWrite(3,255);
  delay(2000);
  digitalWrite(9,HIGH);
  delay(2000);
}
