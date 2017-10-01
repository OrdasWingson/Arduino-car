#include <ESP8266WiFi.h>        
#include <ESP8266WebServer.h>     
#include <FS.h>
#include <ArduinoJson.h> 

String ssid = "admin"; //Сеть по умолчанию
String password = "1234"; //Пароль по умолчанию
String jsonConfig = "{}";//Переменная для обработки файла конфигурации
String stateOf ="AP"; //какой режим включен

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
   loadConfig();
  //Serial.println("Start 1-WIFI");
   //Запускаем WIFI
   if(stateOf == "STA")
      WIFIinit();
   else
      StartAPMode();
    //Настраиваем и запускаем SSDP интерфейс
  //Serial.println("Start 2-WebServer");
  HTTP_init();

}

void loop() {
  HTTP.handleClient();
  delay(1);
}

