#include <Wire.h>
//HTTP REQUEST
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

const char* ssid = ""; //Your WiFi Name
const char* password = ""; //Your Wifi Password

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Wire.begin(5, 4); /* join i2c bus with SDA=D1 and SCL=D2 of NodeMCU */

  pinMode(16, OUTPUT);

  
  while (WiFi.status() != WL_CONNECTED) {

    delay(1000);
    Serial.println("Connecting..");
 
  }
}

void loop() {
 digitalWrite(16, HIGH);
  delay(1000);           
  digitalWrite(16, LOW); 
  delay(1000);   
  
   if (WiFi.status() == WL_CONNECTED) {
      
    HTTPClient http;
    
    WiFiClient client;
    http.begin(client,"https://xxxx.id/xxxx.php"); //Get JSON API 
    int httpCode = http.GET();

    if (httpCode > 0) {
       Wire.requestFrom(8, 1); /* request & read data of size 13 from slave */
       while(Wire.available()){
       byte c = Wire.read();
       Serial.println(c);
    }
      
      char json[500];
      String payload = http.getString();
      payload.toCharArray(json, 500);
      StaticJsonDocument<200> doc;
      deserializeJson(doc, json);
       //Parsing
      byte id_mesin = doc[0];
      Serial.println(id_mesin);     

       byte data = id_mesin;
       Wire.beginTransmission(8); /* begin with device address 8 */
       Wire.write(data);          /* sends hello string */
       Wire.endTransmission();    /* stop transmitting */

 Serial.println();
 delay(1000);
    }
    http.end();
  }
  delay(1000);
}
