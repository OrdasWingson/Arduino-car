void HTTP_init(void) {
  HTTP.on("/ledon", handle_led_on);     //включить светодиод
  HTTP.on("/forword", go_forword);     //едем вперед
  HTTP.on("/left", go_left);     //едем вперед
  HTTP.on("/right", go_right);     //едем вперед
  HTTP.on("/reset", reset);
  HTTP.on("/back", go_back);
  // Запускаем HTTP сервер
  HTTP.begin();

}


void handle_led_on(){
  //Serial.begin(9600);//115200
  String answ = HTTP.arg("res");
  HTTP.send(200, "text/plain", "OK "+answ);  
  Serial.println(answ); 
}

void go_forword(){
  Serial.println("1");
  HTTP.send(200, "text/plain", "OK ");
}

void go_left(){
  Serial.println("2");
  HTTP.send(200, "text/plain", "OK ");
}

void go_right(){
  Serial.println("3");
  HTTP.send(200, "text/plain", "OK ");
}

void reset(){
  Serial.println("4");
  HTTP.send(200, "text/plain", "OK ");
}

void go_back(){
  Serial.println("5");
  HTTP.send(200, "text/plain", "OK ");
}

