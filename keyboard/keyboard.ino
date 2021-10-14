#include <Keyboard.h>

void setup() {
  // Configura o pino 2 como entrada e ativa
  // o resistor pull-up tal que o pino seja HIGH
  // a menos que conectado ao ground:
  pinMode(2, INPUT_PULLUP);
  //Inicia a emulação de um teclado USB
  Keyboard.begin();
}

void loop() {
  //se o botão for pressionado
  if (digitalRead(2) == LOW) {
    //envia a mensagem
    Keyboard.print("Hello!");
  }
}
