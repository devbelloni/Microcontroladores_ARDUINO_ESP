 

  
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
 
// Altere com as suas credenciais
const char *ssid = "CLARO_2G4A3C1E";
const char *password = "E74A3C1E";
 
ESP8266WebServer server(80); //instanciar servidor no porto 80
 
String page = "";
 
void setup(void)
{
 
  //Pagina HTML
page = "<!DOCTYPE html><html lang=\"pt-BR\"><head><meta charset=\"UTF-8\"><meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"><title>CONTROLE DO MALUCO</title><style>body {background-color: aqua;font: normal 20pt Arial;}</style></head><body><h1>Controle de LED</h1><p>Bem vindo ao Controle de LED do seu NODEMCU ESP!<br/></p><br/><p><a href=\"LEDOn\"><button>ON</button></a>&nbsp;<a href=\"LEDOff\"><button>OFF</button></a></p></body></html>";
// page = "<title>CONTROLE DO MALUCO</title><h1>Controle de LED</h1><p>Bem vindo ao Controle de LED do seu NODEMCU ESP!<br/></p><br/><p><a href=\"LEDOn\"><button>ON</button></a>&nbsp;<a href=\"LEDOff\"><button>OFF</button></a></p>";
 
  //DEsligar PINs
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
 
  delay(1000);
  Serial.begin(9600);
  WiFi.begin(ssid, password); //Iniciar ligação à rede Wi-Fi
  Serial.println("");
 
  // Aguardar por ligação
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Ligado a: ");
  Serial.println(ssid);
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());
 
  server.on("/", []() {
    server.send(200, "text/html", page);
  });
  server.on("/LEDOn", []() {
    server.send(200, "text/html", page);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
  });
  server.on("/LEDOff", []() {
    server.send(200, "text/html", page);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
  });
  server.begin();
  Serial.println("Web server Inicializado!");
}
 
void loop(void)
{
  server.handleClient();
}
