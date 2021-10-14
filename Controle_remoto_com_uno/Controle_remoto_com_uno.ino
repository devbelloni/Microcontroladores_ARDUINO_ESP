#include <Keypad.h> // Biblioteca do codigo

const byte LINHAS = 4; // Linhas do teclado
const byte COLUNAS = 4; // Colunas do teclado

const char TECLAS_MATRIZ[LINHAS][COLUNAS] = { // Matriz de caracteres (mapeamento do teclado)
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

const byte PINOS_LINHAS[LINHAS] = {9, 8, 7, 6}; // Pinos de conexao com as linhas do teclado
const byte PINOS_COLUNAS[COLUNAS] = {5, 4, 3, 2}; // Pinos de conexao com as colunas do teclado

Keypad teclado_personalizado = Keypad(makeKeymap(TECLAS_MATRIZ), PINOS_LINHAS, PINOS_COLUNAS, LINHAS, COLUNAS); // Inicia teclado

const int IR = 10; // pino do IR
int contagem;
int periodoA = 3;
int periodoB = 4;

void setup() {
  Serial.begin(9600); // Inicia porta serial
pinMode (IR,OUTPUT);
}

void loop() {

  char leitura_teclas = teclado_personalizado.getKey(); // Atribui a variavel a leitura do teclado

if (leitura_teclas){    Serial.println(leitura_teclas); // Imprime a tecla pressionada na porta serial

  if (leitura_teclas=="A") 
    {    
      digitalWrite(IR,1);
      delay(periodoA);
      digitalWrite(IR,0);
      delay(periodoA);
    }
  
  if (leitura_teclas=="B") 
    {    
      digitalWrite(IR,1);
      contagem ++;
      delay(periodoB);
      digitalWrite(IR,0);
      delay(periodoB);
      } 
    }

  
delay(10);  
}
