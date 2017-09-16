#include <ESP8266WiFi.h>        
#include <ESP8266WebServer.h>     
#include <FS.h>

const char* ssid = "Amsterdam111";
const char* password = "scarletrose90";

// Web интерфейс для устройства
ESP8266WebServer HTTP(80);
// Для файловой системы
File fsUploadFile;

void setup() {
  Serial.begin(9600);
 // Serial.println("");
  //Запускаем файловую систему 
  //Serial.println("Start 4-FS");
   FS_init();
  //Serial.println("Start 1-WIFI");
   //Запускаем WIFI
  WIFIinit();
    //Настраиваем и запускаем SSDP интерфейс
  //Serial.println("Start 2-WebServer");
  HTTP_init();

}

void loop() {
  HTTP.handleClient();
  delay(1);
}

