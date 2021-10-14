#include "SoftwareSerial.h" // Inclui a biblioteca SoftwareSerial

#define ledPin 13 // numero do pino onde o LED esta conectado

// Cria uma serial em software 
SoftwareSerial blackBoardMaster(2,3); // (RX, TX)

void setup() {
 Serial.begin(9600); // inicia a serial em software com uma taxa de 9600 bit/s
  blackBoardMaster.begin(9600);
  
  pinMode(LED_BUILTIN, OUTPUT);  // configura o pino do LED como saida
}

void loop() {
  // verifica se existem dados para serem lidos na serial
  if (blackBoardMaster.available() > 0){
    // le o byte recebido
    char received = blackBoardMaster.read();

    // se o byte recebido corresponde ao caractere '0'(48) apaga o LED
    if (received == '0'){
      digitalWrite(ledPin, LOW);
    }
    
    // se o byte recebido corresponde ao caractere '1'(49) acende o LED
    if (received == '1'){
      digitalWrite(ledPin,HIGH);
  }    
    Serial.print(received);
    }}
