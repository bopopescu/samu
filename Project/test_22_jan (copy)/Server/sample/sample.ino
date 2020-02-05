void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
Serial.flush();
Serial.println("inside setup");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("inside loop");

}
