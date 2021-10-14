#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
SoftwareSerial Receptor (0,1);

#define led 13

void setup()
{
lcd.init();
lcd.backlight();
Receptor.begin(9600);
}

void loop()
{
  if(Receptor.available() >0){
    int leitura = Serial.read();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("HEXEM TECHNOLOGY");
    lcd.setCursor(0, 1);
    lcd.print("Dist.(cm): ");  
    lcd.setCursor(12, 1);
    lcd.print(leitura);
    delay (300);
  }
delay(50);
}
