/*   
 *  Este código permite a transmissão de dados da porta analógica do ESP8266
 *  para uma máquina (computador/servidor) externa através do protocolo UDP
 *  por WiFi.
*/

//  Bibliotecas:
#include <ESP8266WiFi.h>    // Biblioteca para utilizacao de dados Wifi
#include <WiFiUdp.h>        // Biblioteca para utilizacao de dados UDP


// Criação de variáveis para conexão em WiFi:
const char* ssid = "WiFi-RPis";          // Nome da rede WiFi a se conectar
const char* password = "nusompi67";      // Senha da rede WiFi a se conectar

WiFiUDP Udp;  /* Instanciação de WiFiUDP através da criação do objeto Udp */

unsigned int portaLocal_UDP = 4210;  // Variável contendo o número da porta UDP de entrada
char incomingPacket[255];  // Buffer de memória para pacotes UDP que chegarem

const char* IP_host = "192.168.100.100";   // Endereço de IP para onde serão enviados os pacotes
unsigned int portaUDP_host = 54321;   // Variável contendo o número da porta UDP de saída

/* NOTA:
 *  host é qualquer computador ou dispositivo conectado à rede, que conta com um número de IP e nome definidos
 *  http://www.techtudo.com.br/artigos/noticia/2012/02/o-que-e-um-host.html
*/

const int yPin = A0;  // Variável que receberá dados da porta analógica


/*
 *  Em void setup() serão listadas rotinas que serão executadas uma única vez
 * 
*/
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


/*
 *  Em void loop() teremos a parte do código que envia a leitura feita na porta analógica A0
 *  do ESP8266 e envia para o console da IDE do Arduino e para o host via protocolo UDP
 * 
*/
void loop() {
  
  int y = analogRead(yPin);  /* criação da variável que recebe os dados da entrada analógica do ESP8266 */
  delay(100);  /* tempo de espera em milissegundos */

  Serial.print("Eixo Y : "); /* imprime no console a mensagem descritiva  */
  Serial.println(y); /* adiciona valor ao pacote
                        https://portal.vidadesilicio.com.br/comunicacao-wireless-esp-protocolo-udp/  */
  
  Udp.beginPacket(IP_host, portaUDP_host);  /* inicia o pacote de transmissão ao endereço de IP e porta UDP  */
  Udp.println(y); /* imprime o dado da entrada analógica no host remoto  */
  Udp.endPacket(); /* finaliza o pacote UDP e envia ao host remoto
                      https://www.arduino.cc/en/Reference/WiFiUDPEndPacket  */

}
