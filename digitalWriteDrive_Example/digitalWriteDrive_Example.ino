
int outPin = 3;
void setup() {
  // put your setup code here, to run once:
  pinMode(outPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(outPin,HIGH);
  delay(1500);
  digitalWrite(outPin,LOW);
  delay(1500);

}
