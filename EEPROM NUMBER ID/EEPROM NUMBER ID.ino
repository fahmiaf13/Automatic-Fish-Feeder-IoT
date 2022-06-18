#include<EEPROM.h>

byte nilai;
byte nilai1;
byte nilai2;
void setup() {
  Serial.begin(9600);
  EEPROM.write(0,130);  //write a value in EEPROM on Arduino Nano with array type
  EEPROM.write(1,120);  
  EEPROM.write(2,110);
}

void loop() {
  nilai=EEPROM.length(0); //read a value in EEPROM on Arduino Nano with array type
  nilai1=EEPROM.read(1);
  nilai2=EEPROM.read(2);
  Serial.println(nilai);
  Serial.println(nilai1);
  Serial.println(nilai2);
  delay(1000);

  Serial.print(EEPROM.read(0));
}
