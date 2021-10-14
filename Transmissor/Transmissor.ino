#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h> // biblioteca para controle da fita de led

Adafruit_NeoPixel pixels(6, 5, NEO_GRB + NEO_KHZ800); // numero de leds e pino de controle

SoftwareSerial loraSerial(2, 3); // TX, RX pinos digitais do lora e32


void setup() {
  Serial.begin(9600);
  loraSerial.begin(9600); // velocidade da porta serial do módulo configurada antes
  pixels.begin();

}

void loop() {
  while (loraSerial.available()) {
    Serial.write(loraSerial.read());// mostra no monitor serial a mensagem recebida
    
    for (int i = 0; i < 6; i++) { //liga todos os leds da fita
      pixels.setPixelColor(i, pixels.Color(0, 255, 0));
      pixels.show();
    }
  }
  pixels.clear(); // apaga os leds quando não há mensagens para ler
}
