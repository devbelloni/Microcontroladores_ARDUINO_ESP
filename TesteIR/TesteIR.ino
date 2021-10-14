#include <IRremote.h> //INCLUSÃO DE BIBLIOTECA

int RECV_PIN = 8; //PINO DIGITAL UTILIZADO PELO FOTORRECEPTOR KY-022

IRrecv irrecv(RECV_PIN); //PASSA O PARÂMETRO PARA A FUNÇÃO irrecv

decode_results results; //VARIÁVEL QUE ARMAZENA OS RESULTADOS (SINAL IR RECEBIDO)

void setup(){
  pinMode(13,OUTPUT);
  irrecv.enableIRIn(); //INICIALIZA A RECEPÇÃO DE SINAIS IR
}

void loop(){
  //CAPTURA O SINAL IR
  if (irrecv.decode(&results)) {
  if (results.value==926197162){
    digitalWrite(13,1);
    delay(1000);
    digitalWrite(13,0);
    delay(1000);
  }
  }
}  
