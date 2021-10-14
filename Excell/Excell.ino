#include <rExcel.h>
rExcel myExcel;
int idx = 0;
float A;


void setup() {
  Serial.begin(115200);
  delay(1000);
  myExcel.clearInput();
pinMode (A0,INPUT);
}

void loop() {
A=analogRead (A0);
myExcel.writeIndexed("Example", idx+1, 1,"%date%");
myExcel.writeIndexed("Example", idx+1, 2,"%time%");
myExcel.writeIndexed("Example", idx+1, 3,A,4);
delay(1000);
idx++;
}
