#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,10,11,12,13);//13,12,11,10,9,8);//
#include <Ultrasonic.h>
#define pino_trigger 2
#define pino_echo 3
 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);


void setup() {
lcd.begin(16, 2);
Serial.begin(9600);

lcd.setCursor(0,0);
lcd.print ("HEXEN TECHNOLOGY");
lcd.setCursor(1,0);
lcd.print ("GROUP");
delay (2000);
}

void loop() {

float cmMsec, inMsec;
long microsec = ultrasonic.timing();

  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);

lcd.clear();
lcd.setCursor(0,0);
lcd.print ("Medidas ");
lcd.setCursor(0,9);
lcd.print (cmMsec);
lcd.setCursor(0,12);
lcd.print ("(cm)");
lcd.setCursor(1,9);
lcd.print (cmMsec);
lcd.setCursor(1,11);
lcd.print ("(pol)");


Serial.print("Medidas: ");
Serial.print(cmMsec);
Serial.println(" (cm)");

delay (50);
}
