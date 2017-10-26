void HTTP_init(void) {
  HTTP.on("/forword", go_forword);     //едем вперед
  HTTP.on("/left", go_left);     //лево
  HTTP.on("/right", go_right);     //право
  HTTP.on("/reset", stopWheels); //остановка
  HTTP.on("/back", go_back); //назад
  HTTP.on("/config", conf); //обработка конфигурации
  HTTP.on("/mode", changeMode); //смена режима работы сервера
  // Запускаем HTTP сервер
  HTTP.begin();

}

//Код движения вперед
void go_forword(){
  Serial.println("1");
  HTTP.send(200, "text/plain", "OK ");
}

//Код движения налево
void go_left(){
  Serial.println("2");
  HTTP.send(200, "text/plain", "OK ");
}

//Код движения направо
void go_right(){
  Serial.println("3");
  HTTP.send(200, "text/plain", "OK ");
}

//Остановка
void stopWheels(){
  Serial.println("4");
  HTTP.send(200, "text/plain", "OK ");
}

//Код движения назад
void go_back(){
  Serial.println("5");
  HTTP.send(200, "text/plain", "OK ");
}


//конфигурация
void conf()
{
  //root
  HTTP.send(200, "application/json", jsonConfig);
}

//режим подключения
void changeMode()
{
  stateOf = HTTP.arg("mode");
  Serial.println("mode - " + stateOf); 
  
  if(stateOf == "STA"){
    ssid = HTTP.arg("ssid");
    //Serial.println("ssid - " + ssid);
    password = HTTP.arg("pass");
    //Serial.println("password - " + password);
    WiFi.disconnect();
    Serial.println("DISCONECT");
    WIFIinit();
  }
  if(stateOf == "AP"){
    Serial.println("AP START");
     StartAPMode();
  }
   HTTP.send(200, "text/plain", "OK"); // AP/STA
  saveConfig();
 
}

