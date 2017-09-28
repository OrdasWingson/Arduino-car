void WIFIinit() {
  // Попытка подключения к точке доступа. IP по умолчанию 192.168.4.1 
  WiFi.mode(WIFI_STA);
  byte tries = 11;
  WiFi.begin(ssid.c_str() , password.c_str());
  // Делаем проверку подключения до тех пор пока счетчик tries
  // не станет равен нулю или не получим подключение
  while (--tries && WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(1000);
    
  }
  Serial.print(ssid+" "+password);
  if (WiFi.status() != WL_CONNECTED)
  {
    // Если не удалось подключиться запускаем в режиме AP
    Serial.println("");
    Serial.println("WiFi up AP");
    StartAPMode();
  }
  else {
    // Иначе удалось подключиться отправляем сообщение
    // о подключении и выводим адрес IP
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    stateOf="STA(КЛИЕНТ)";
  }
}

bool StartAPMode()
{ // Отключаем WIFI
  WiFi.disconnect();
  // Меняем режим на режим точки доступа
  WiFi.mode(WIFI_AP);
  // Задаем настройки сети
  //WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
  // Включаем WIFI в режиме точки доступа с именем и паролем
  // хронящихся в переменных _ssidAP _passwordAP
  //WiFi.softAP(_ssidAP.c_str(), _passwordAP.c_str());
  WiFi.softAP("RIK");
  Serial.println("softAP is start");
  Serial.println(WiFi.softAPIP());
  stateOf="AP(ТОЧКА ДОСТУПА)";
  return true;
}
