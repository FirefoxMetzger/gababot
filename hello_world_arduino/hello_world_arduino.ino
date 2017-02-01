// A simple hello world programm for the arduino
// copied from the lecture slides

void setup() {
  // setup I/O
  pinMode(13, OUTPUT);
}

void loop() {
  // make it blink
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
}
