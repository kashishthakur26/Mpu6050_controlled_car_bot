#include<ESP8266WiFi.h>
#include<ESP8266WebServer.h>

IPAddress ip(192,168,4,1);
IPAddress subnet(255,255,255,0);
IPAddress gateway(192,168,4,1);

const char *ssid="ESPap";
const char *password="12345678";
 

ESP8266WebServer server(80);

void handleRoot(){
  server.send(200,"text/html","Welcome To ErodeRTP");
  digitalWrite(D5,LOW);
  digitalWrite(D6,LOW); //RIGHT MOTOR
  
  digitalWrite(D7,LOW);
  digitalWrite(D8,LOW); //LEFT MOTOR
}

void halt(){
  server.send(200,"text/html","HALT");
  digitalWrite(D5,LOW);
  digitalWrite(D6,LOW); //RIGHT MOTOR
  
  digitalWrite(D7,LOW);
  digitalWrite(D8,LOW); //LEFT MOTOR
}

void forward(){
  server.send(200,"text/html","FORWARD");
  digitalWrite(D5,HIGH);
  digitalWrite(D6,LOW); //RIGHT MOTOR
  
  digitalWrite(D7,HIGH);
  digitalWrite(D8,LOW); //LEFT MOTOR
}

void backward(){
  server.send(200,"text/html","BACKWARD");
  digitalWrite(D5,LOW);
  digitalWrite(D6,HIGH); //RIGHT MOTOR
  
  digitalWrite(D7,LOW);
  digitalWrite(D8,HIGH); //LEFT MOTOR
}

void left(){
  server.send(200,"text/html","LEFT");
  digitalWrite(D5,HIGH);
  digitalWrite(D6,LOW); //RIGHT MOTOR
  
  digitalWrite(D7,LOW);
  digitalWrite(D8,HIGH); //LEFT MOTOR
}

void right(){
  server.send(200,"text/html","RIGHT");
  digitalWrite(D5,LOW);
  digitalWrite(D6,HIGH); //RIGHT MOTOR
  
  digitalWrite(D7,HIGH);
  digitalWrite(D8,LOW); //LEFT MOTOR
}

void setup() {
  // put your setup code here, to run once:
 pinMode(D5,OUTPUT);
 pinMode(D6,OUTPUT);
 pinMode(D7,OUTPUT);
 pinMode(D8,OUTPUT);
 delay(100);

 WiFi.mode(WIFI_AP);
 WiFi.softAPConfig(ip,gateway,subnet);
 WiFi.softAP(ssid,password);

 server.on("/",handleRoot);
 server.on("/halt",halt);
 server.on("/forward",forward);
 server.on("/backward",backward);
 server.on("/left",left);
 server.on("/right",right);
 server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
 server.handleClient();
}
