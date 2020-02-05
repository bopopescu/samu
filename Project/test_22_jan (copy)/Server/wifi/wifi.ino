#include <WiFiClient.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// credentials
const char *ssid = "H-105";
const char *password = "admin_1234";

// create the web server
ESP8266WebServer server(80);

void root() {
  // 200: status code
  // text/plain: content type -> type of content
  // "welcome..": contents
  server.send(200, "text/plain", "Welcome to NodeMCU web server");
}

void update_data() {
    String user_id = "";
    String sugar = "";
  
}

void read_data_for_u1() {
  digitalWrite(D5, LOW);
  server.send(200, "text/plain", "Turned off RED LED");
}

void read_data_for_u2() {
  digitalWrite(D3, HIGH);
  server.send(200, "text/plain", "Turned on GREEN LED");
}

void read_data_for_u3() {
  digitalWrite(D3, LOW);
  server.send(200, "text/plain", "Turned off GREEN LED");
}


void read_data_for_u4() {
  digitalWrite(D0, HIGH);
  server.send(200, "text/plain", "Turned on yellow LED");
}

void read_data_for_u5() {
  digitalWrite(D0, LOW);
  server.send(200, "text/plain", "Turned off yellow LED");
}

void get_current_temperature() {
  float temperature = analogRead(A0);
  String result = "Current Temperature = " + String(temperature);
  server.send(200, "text/plain", result);
}


void setup() {
  Serial.begin(115200);
  Serial.flush();

  // change the pinmodes
  pinMode(D0, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(A0, INPUT);

  // connect to WiFi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  // wait for valid IP
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // you are connected
  Serial.println("connected..");
  Serial.print("IP Address");
  Serial.println(WiFi.localIP());

  // setup the routes
  // server.on("/", root);
  server.on("/", HTTP_GET, root);
  server.on("/update_data", HTTP_POST, update_data);
  server.on("/u1/read_data", HTTP_GET, read_data_for_u1);
  server.on("/u2/read_data", HTTP_GET, read_data_for_u2);
  server.on("/u3/read_data", HTTP_GET, read_data_for_u3);
  server.on("/u4/read_data", HTTP_GET, read_data_for_u4);
  server.on("/u5/read_data", HTTP_GET, read_data_for_u5);

  // start the server
  server.begin();
}

void loop() {
  // continuously handle the client incoming requests
  server.handleClient();
}
