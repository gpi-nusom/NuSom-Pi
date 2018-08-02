// Including the ESP8266 WiFi library
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

// Replace with your network details
const char* ssid = "love_in_the_air";
const char* password = "79791751";


// Udp Server on port 4210
WiFiUDP Udp;
unsigned int localUdpPort = 4210;  // local port to listen on
char incomingPacket[255];  // buffer for incoming packets
char  replyPacket[] = "Hi there! Got the message :-)";  // a reply string to send back
int  replyPacket2 = 0; 
unsigned int x = random (0, 50);

// only runs once on boot
void setup() {
  // Initializing serial port for debugging purposes
  Serial.begin(115200);
  pinMode(5, OUTPUT); // Habilita entrada D1 para acionamento do Motor Vibracall
  pinMode(4, OUTPUT);
  digitalWrite(5,LOW); // Inicializa a entrada mantendo o Motor desligado
  digitalWrite(4,LOW);
  // Connecting to WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  Udp.begin(localUdpPort);
  Serial.printf("Now listening at IP %s, UDP port %d\n", WiFi.localIP().toString().c_str(), localUdpPort);
  
  
  // Printing the ESP IP address
  Serial.println(WiFi.localIP());
}

// runs over and over again
void loop()
{
  int packetSize = Udp.parsePacket();
  if (packetSize)
  {
    Udp.beginPacket("192.168.2.5", 54321);
    digitalWrite(5,HIGH);
    digitalWrite(4, HIGH);
    delay(50);
    digitalWrite(5,LOW);
    digitalWrite(4,LOW);
    Udp.println("Chegou!");
    Udp.endPacket();
    //delay(10);
  }
} 
