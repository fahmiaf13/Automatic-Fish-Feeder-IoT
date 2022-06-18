#include <Wire.h>
#include<EEPROM.h>

byte nilai;
bool mode1=true;
bool mode2=false;
bool on=LOW;
bool off=HIGH;
const int led=3;

void setup() {
 Wire.begin(8);                /* join i2c bus with address 8 */
 Wire.onReceive(receiveEvent); /* register receive event */
 Wire.onRequest(requestEvent); /* register request event */
 Serial.begin(9600);           /* start serial for debug */

  pinMode(led, OUTPUT);
  digitalWrite(led,on);
}
void loop() {
  requestEvent();
  digitalWrite(led,off);
  delay(100);
}

// function that executes whenever data is received from master
void receiveEvent(int howMany) {
 while (0 <Wire.available()) {
    byte c = Wire.read();      /* receive byte as a character */
    Serial.print(c);    /* print the character */
    
     pinMode(led, OUTPUT);
     digitalWrite(led,on);
    //login
     cekKeamanan(c, EEPROM.read(0));
     mode1=true;
  }
 Serial.println();            
}

 void cekKeamanan(byte str, byte data){
  while(mode1){
   if(!mode2){
    
          if(str==data){
            mode1=false;
            Serial.println("success");
          }
          
          else{
            Serial.println("invalid");
            delay(1500);
            loop();
            //cekKeamanan(str,data);
          }
        }
  }
 }

// function that executes whenever data is requested from master
void requestEvent() {
 byte nomorseri=EEPROM.read(0);
 Wire.write(nomorseri);  /*send string on request */
}
