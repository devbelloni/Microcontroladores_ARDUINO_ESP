#include <Ultrasonic.h>
#define pino_trigger 2
#define pino_echo 3
#define tmp 2000

Ultrasonic ultrasonic(pino_trigger, pino_echo);

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
long microsec = ultrasonic.timing();
int   leitura = ultrasonic.convert(microsec, Ultrasonic::CM);
leitura=map(analogRead(pino_echo),0,1023,0,100);
Serial.write(leitura);
delay(200);
}
