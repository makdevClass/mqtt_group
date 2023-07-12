int ledPin = 7;


void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int x;
  for(x = 0; x < 255;x ++){
    analogWrite(ledPin,x);
    delay(20);
  }
   
}
