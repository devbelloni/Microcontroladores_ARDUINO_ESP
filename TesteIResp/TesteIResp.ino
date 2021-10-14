//INCLUSÃO DE BIBLIOTECA IR
#include <i18n.h>
#include <IRac.h>
#include <IRrecv.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <IRtext.h>
#include <IRtimer.h>
#include <IRutils.h>
#include <ir_Airwell.h>
#include <ir_Amcor.h>
#include <ir_Argo.h>
#include <ir_Carrier.h>
#include <ir_Coolix.h>
#include <ir_Corona.h>
#include <ir_Daikin.h>
#include <ir_Delonghi.h>
#include <ir_Ecoclim.h>
#include <ir_Electra.h>
#include <ir_Fujitsu.h>
#include <ir_Goodweather.h>
#include <ir_Gree.h>
#include <ir_Haier.h>
#include <ir_Hitachi.h>
#include <ir_Kelvinator.h>
#include <ir_LG.h>
#include <ir_Magiquest.h>
#include <ir_Midea.h>
#include <ir_Mitsubishi.h>
#include <ir_MitsubishiHeavy.h>
#include <ir_NEC.h>
#include <ir_Neoclima.h>
#include <ir_Panasonic.h>
#include <ir_Samsung.h>
#include <ir_Sanyo.h>
#include <ir_Sharp.h>
#include <ir_Tcl.h>
#include <ir_Technibel.h>
#include <ir_Teco.h>
#include <ir_Toshiba.h>
#include <ir_Transcold.h>
#include <ir_Trotec.h>
#include <ir_Truma.h>
#include <ir_Vestel.h>
#include <ir_Voltas.h>
#include <ir_Whirlpool.h>
int RECV_PIN = 12; //PINO DIGITAL EM QUE O FOTORRECEPTOR ESTÁ CONECTADO - GPIO12 / PINO D6
IRrecv irrecv(RECV_PIN); //VARIÁVEL DO TIPO IRrecv
decode_results results; //VARIÁVEL QUE ARMAZENA OS RESULTADOS


void setup() {
//INICIALIZA O RECEPTOR IR
  irrecv.enableIRIn();  
  delay(1000);
  Serial.begin(9600);



}

void loop() {
    //RETORNA NA SERIAL AS INFORMAÇÕES FINAIS SOBRE O COMANDO IR QUE FOI IDENTIFICADO
  if (irrecv.decode(&results)) {
  int tecla=results.value;
    Serial.print(tecla);
 //   dump(&results);
    irrecv.resume(); //RECEBE O PRÓXIMO VALOR
  }

}
