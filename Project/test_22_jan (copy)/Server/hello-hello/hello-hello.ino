#include<uart.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //pinMode(LED_BUILTIN, OUTPUT);
  Serial.flush();
  //uart.setup(0, 9600, 8, uart.PARITY_NONE, uart.STOPBITS_1, 1);
}

void loop(){
  // put your main code here, to run repeatedly:
    while (Serial.available()) {
    char data = Serial.read();
    delay(10);
    Serial.write(data);



    
    //Serial.println(data);
    /*uart.alt(0);
    uart.on(data, 0, function1(data), 1);
    
    uart.write(0, "Hello, world\n");
    Serial.println(data); */
    } 
}

/*void function1(int data)
{

for(int i=0;i<data;i++)
{
digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(750);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(750);                       // wait for a second

}
}*/

