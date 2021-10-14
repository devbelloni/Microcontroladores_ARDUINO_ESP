#include <Wire.h>
#include "SSD1306Wire.h"

//Pinos do NodeMCU
// SDA => D1
// SCL => D2

// Inicializa o display Oled
SSD1306Wire  display(0x3c, D1, D2);

// --- Dados de Acesso do seu roteador ---
//#define WLAN SSID   "VIVO-7F38"   // nome da sua rede
//#define WLAN PASS  "4J4KAFw7wJ"   // senha de acesso do seu roteador
//WebClient Secure cliente; //Cria um cliente seguro (para ter acesso ao HTTPS)

void setup()
{
  // configura o display OLED
  Serial.begin(115200);
  display.init();
  display.flipScreenVertically();
  
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  //Seleciona a fonte
  display.setFont(ArialMT_Plain_16);
  display.drawString(63, 1, "Conectado!!!");
  display.display();
  delay(1500); // aguarda 1,5 segundo
}

void telainicial()
{
  //Apaga o display
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  //Seleciona a fonte
  display.setFont(ArialMT_Plain_16);
  display.drawString(63, 1, "ENIAC");
  display.drawString(63, 26, "Professor");
  display.drawString(63, 45, "Belloni");
  display.display();
}


void loop()
{
  telainicial();
  delay(3000); // aguarda 3 segundos

}
