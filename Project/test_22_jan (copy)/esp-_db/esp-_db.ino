#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>

const char *ssid = "INDRAYANI";
const char *password = "33335555";

String user_id = "4";
String sugar= "10";
String wheat= "10";
String oil= "10";
String rice= "10";
String str;
char ch;
int i = 0;

void setup() {
  Serial.begin(9600);
  Serial.flush();

  // set the pin mode
  //pinMode(A0, INPUT);

  // STA: station
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  // wait till the connection gets successful
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("connecting...");
  }

  Serial.println("Connected... ");
  Serial.println("IP Address:");
  Serial.println(WiFi.localIP());
}

void loop() {
  
  // get the temperature
  //float temperature = analogRead(A0);
  //while(!Serial.available());
  
  if(Serial.available() > 0)
  { 
  
    ch = char(Serial.read());
    if(ch != '\r')
    {
      str = str + ch;
    } 
  user_id = str;
  }
 
  // get the json string
 // String body = "{ \"user_id\" : " + user_id +"}";
  String body = "{ \"user_id\" : " + String(user_id) +","+ "\"sugar\" : " + String(sugar)+ "," + "\"wheat\" : " + String(wheat) + "," + "\"oil\" : " + String(oil) + ","  "\"rice\" : " + String(rice) +"}";
  Serial.println("sending : " + body);

  // create the HTTP Client
  HTTPClient httpClient;

  // send the request
  httpClient.begin("http://172.18.5.14:4000/update_data");
  httpClient.addHeader("Content-Type", "application/json");
  int statusCode = httpClient.POST(body);
  
  Serial.println("status code: " + String(statusCode));
  

  // add delay
  delay(1000);
}
