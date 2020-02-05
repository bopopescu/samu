#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>
#include <string.h>

const char *ssid = "INDRAYANI";
const char *password = "33335555";

String user_id;
String sugar;
String wheat;
String oil;
String rice;
String str;
char ch;
int i = 0,flag=0;

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
 
  //do{
  //while(!Serial.available());
  
  if(Serial.available() > 0)
  { 
    ch = char(Serial.read());
    if(ch != '\r')
      {
        str = str + ch;
      }
    else
    {
	user_id = str[9];
	sugar = str[16];
	wheat = str[23];
	oil = str[28];
	rice = str[34];
  Serial.println(str);
  Serial.println(user_id);
  Serial.println(sugar);
  Serial.println(wheat);
  Serial.println(oil);
  Serial.println(rice);
	http_send(user_id, sugar, wheat, oil, rice);
  str = "";
    }
      
    
  //}while(Serial.available());
 
  
  /*if(str[0] == 'u')
  {
    flag++;
    //Serial.println("Hiiii\r\n");
    //Serial.println(str); 
    user_id = str[8];
    Serial.println(user_id); 
    str = "";
    //break;
  }
  else if(str[0] == 's')
  {flag++;
    sugar = str[6]; 
    Serial.println(sugar);
    str = "";
  }
  else if(str[0] == 'w')
  {flag++;
    wheat = str[6]; 
    Serial.println(wheat);
    str = "";
  }
  else if(str[0] == 'o')
  {flag++;
    oil = str[4]; 
    Serial.println(oil);
    str = "";
  }
  else if(str[0] == 'r')
  {flag++;
    rice = str[5]; 
    Serial.println(rice);
    str = "";
  }
  else if(str[0] == 'D')
  {flag++;
    Serial.println("Hello\r\n");
    http_send(user_id, sugar, wheat, oil, rice);
    str = "";
  }*/

  /*if(flag == 5)
  {
    flag=0;
    http_send(user_id, sugar, wheat, oil, rice);
    break;
  }*/
 
  // get the json string
 // String body = "{ \"user_id\" : " + user_id +"}";
  
  }
 // }while(Serial.available());
}

void http_send(String user_id, String sugar, String wheat, String oil, String rice)
{
  String body = "{ \"user_id\" : " + String(user_id) +","+ "\"sugar\" : " + String(sugar)+ "," + "\"wheat\" : " + String(wheat) + "," + "\"oil\" : " + String(oil) + ","  "\"rice\" : " + String(rice) +"}";
  Serial.println("sending : " + body);

  // create the HTTP Client
  HTTPClient httpClient;

  // send the request
  httpClient.begin("http://172.18.5.210:4000/update_data");
  httpClient.addHeader("Content-Type", "application/json");
  int statusCode = httpClient.POST(body);
  
  Serial.println("status code: " + String(statusCode));
  

  // add delay
  delay(1000);  
}
