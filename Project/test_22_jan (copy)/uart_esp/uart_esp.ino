
char ch;
String str;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  while(!Serial.available());
  if(Serial.available() > 0)
  {
    ch = char(Serial.read());
    if(ch != '\r')
    {
	    str = str + ch;
    } 
    else
    {
      Serial.println(str);
      //Serial.write(ch);
      str = "";  
    }
  }
  else
  {
    Serial.print(".");
    delay(1000);  
  }
}
