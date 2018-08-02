#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "love_in_the_air";
const char* password = "79791751";

WiFiUDP Udp;
unsigned int localUdpPort = 4210;  // local port to listen on
char incomingPacket[255];  // buffer for incoming packets
unsigned int  replyPacket1 = 1;  // a reply string to send back
int  replyPacket2 = 0; 
unsigned int x = random (0, 50);
//bool dado = 1;

void setup()
{
  pinMode (5, INPUT);
  Serial.begin(115200);
  Serial.println();

  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected");

  Udp.begin(localUdpPort);
  Serial.printf("Now listening at IP %s, UDP port %d\n", WiFi.localIP().toString().c_str(), localUdpPort);
}


void loop()
{
    // receive incoming UDP packets
    // send back a reply, to the IP address and port we got the packet from
  
    Udp.beginPacket("192.168.2.5", 54321);
    Udp.println(digitalRead(5));
    Udp.endPacket();
    delay(10);
}
