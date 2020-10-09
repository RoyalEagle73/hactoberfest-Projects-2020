int led = 13;
void setup() {
  pinMode(led, OUTPUT);  //make 13th pin as output
}

void loop() {
  digitalWrite(led, HIGH);   // turn the led pin high
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the led pin low
  delay(1000);                       // wait for a second
}