/* =============================================================================================================================
 *  Utilização do Sensor de distância HC-SR04 com ESP8266
 *  
 *  fontes:
 *  http://blog.baudaeletronica.com.br/integrar-sensor-ao-nodemcu-esp8266/
 *  https://sheldondwill.wordpress.com/2014/02/04/using-an-ultrasonic-sensor-hc-sr04-with-a-3-3v-micro-controller-tiva-c-series/
 *  
 * ============================================================================================================================= 
 * 
 * Pinagem
 * ---------------------    
 * | HC-SC04 | NodeMCU |   
 * ---------------------   
 * |   Vcc   |   5V    |     
 * |   Trig  |   D7    | 
 * |   Echo  |   D8    |   
 * |   Gnd   |   GND   |   
 * 
 *   É necessário instalar a Biblioteca Ultrasonic pra rodar este código.
 *   Sketch -> Incluir Biblioteca -> Gerenciar Bibliotecas
 *=============================================================================================================================
*/


#include <Ultrasonic.h> // Biblioteca para utilização do sensor HC-SR04
#include <ESP8266WiFi.h>    // Biblioteca para utilizacao de dados Wifi
#include <WiFiUdp.h>        // Biblioteca para utilizacao de dados UDP


// Criação de variáveis para conexão em WiFi:
const char* ssid = "WiFi-RPis";          // Nome da rede WiFi a se conectar
const char* password = "nusompi67";      // Senha da rede WiFi a se conectar

Ultrasonic ultrasonic(D7, D8); /* Instância chamada ultrasonic com parâmetros (trig,echo) */
WiFiUDP Udp;  /* Instanciação de WiFiUDP através da criação do objeto Udp */

unsigned int portaLocal_UDP = 4210;  // Variável contendo o número da porta UDP de entrada
char incomingPacket[255];  // Buffer de memória para pacotes UDP que chegarem

const char* IP_host = "192.168.100.255";   // Endereço de IP para onde serão enviados os pacotes
unsigned int portaUDP_host = 54321;   // Variável contendo o número da porta UDP de saída
 

void setup() { 
  Serial.begin(115200);   /* inicializa a comunicação serial a 115200 bps   */
  Serial.println();  /* imprime no console uma linha em branco   */

  Serial.printf("Conectando a rede %s ", ssid); /* imprime no console status de conexão na rede WiFi */
  WiFi.begin(ssid, password); /* inicia a conexão com a rede Wifi e fornece o status
                                 https://www.arduino.cc/en/Reference/WiFiBegin */
  
  while (WiFi.status() != WL_CONNECTED) /*  https://www.arduino.cc/en/Reference/WiFiStatus  */
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" conectado");

  Udp.begin(portaLocal_UDP); /* inicializa a porta UDP de entrada */ 
  Serial.printf("Recebendo pacotes em IP %s, porta UDP %d\n", WiFi.localIP().toString().c_str(), portaLocal_UDP);
  /* imprime no console o endereço IP e porta UDP de entrada */
}


void loop() {
  const int distancia_cm = ultrasonic.distanceRead();  /* Variável recebe distância medida em centímetros */
  Serial.print("Distância: "); /* Escreve texto na tela  */
  Serial.print(distancia_cm);
  Serial.println("cm"); /* Escreve texto na tela e pula uma linha .  */

  Udp.beginPacket(IP_host, portaUDP_host);  /* Inicia o pacote de transmissão ao endereço de IP e porta UDP  */
  Udp.println(distancia_cm); /* Imprime o dado da entrada analógica no host remoto  */
  Udp.endPacket(); /* Finaliza o pacote UDP e envia ao host remoto */
  
  delay(100); /* Aguarda 1s */
}


