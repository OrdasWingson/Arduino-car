void HTTP_init(void) {
  HTTP.on("/forword", go_forword);     //едем вперед
  HTTP.on("/left", go_left);     //едем вперед
  HTTP.on("/right", go_right);     //едем вперед
  HTTP.on("/reset", stopWheels);
  HTTP.on("/back", go_back);
  HTTP.on("/config", conf); //обработка конфигурации
  HTTP.on("/mode", changeMode);
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
  HTTP.send(200, "text/plain", stateOf); // AP/STA
}

