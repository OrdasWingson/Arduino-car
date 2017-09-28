#define h HIGH
#define l LOW
#include <SoftwareSerial.h>
int rxPin = 2;
int txPin = 3;

String stringLed = ""; //для тестов

char com;

int IN3 = 4; // Input3 подключен к выводу 4 
int IN4 = 5;
int IN1 = 6; // Input1 подключен к выводу 6 
int IN2 = 7;
//подключение к регулированию с помощью ШИМ
int EN1 = 9; 
int EN2 = 10; 
SoftwareSerial mySerial(rxPin, txPin);

void setup() {

  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  mySerial.begin(9600);
  Serial.begin(115200);
}

//функция очистки буфера
void clearBuff(){
  while (mySerial.available()) mySerial.read();
  stringLed="";
}


//функция сигнала
void drivers(int enA, int enB, int in1, int in2,int in3, int in4)
{
      analogWrite (EN1, enA);
      analogWrite (EN2, enB);
      digitalWrite(IN1, in1);   
      digitalWrite(IN2, in2);
      digitalWrite(IN3, in3);   
      digitalWrite(IN4, in4);
      clearBuff();
}


void loop() {  
    

 //функция чтения сериал
  if (mySerial.available()>0){
     char c = mySerial.read();
     stringLed += c;
    com = mySerial.read();   
    Serial.print("===");
    Serial.println(c);
    Serial.println("->"+stringLed);
    
  } 
  
  
    if( stringLed == "1") //движение вперед
    {
      drivers(200,200,1,0,0,1);
    }

    if( stringLed == "3") //поворот - лево
    {
      drivers(140,0,0,1,0,1);
    }
    if( stringLed == "2")//поворот - право
    {
      drivers(0,140,1,0,1,0);
    }

    if( stringLed == "4") // остановка
    {
      drivers(0,0,0,0,0,0);
    }

     if( stringLed == "5") // назад
    {
      drivers(130,130,0,1,1,0);
    }

   

}
