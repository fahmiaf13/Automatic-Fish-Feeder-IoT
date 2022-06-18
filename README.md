# Automatic-Fish-Feeder-IoT

This project are using NodeMCU and Arduino Nano (you can also use ESP32 for the better performance)
You need to instal another library on your arduino text editor before starting this project like :
- ArduinoJSON.h 
- wire.h
- ESP8266 or ESP32 library

Step about this project are :
1. NodeMCU get data from API that it will be parsing it into array and deserialize it
2. Arduino nano will get this data from NodeMCU using wire and compare the data with the value inside his memory (EEPROM) <br> *note : in this step you can also insert the value before, by writing a value to inject them into his memory (EEPROM)

