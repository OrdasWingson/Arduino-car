#define h HIGH
#define l LOW
#include <SoftwareSerial.h>
int rxPin = 2;
int txPin = 3;

String command = ""; //переменная ответа com-порта

char com;

int IN3 = 4; // Input3 подключен к выводу 4 
int IN4 = 5;
int IN1 = 6; // Input1 подключен к выводу 6 
int IN2 = 7;
//подключение к регулированию с помощью ШИМ
int EN1 = 9; 
int EN2 = 10; 
SoftwareSerial mySerial(rxPin, txPin);


//функция очистки буфера
void clearBuff(){
  while (mySerial.available()) mySerial.read();
  com = '0';
}


//функция сигнала
void drivers(int enA=0, int enB=0, int in1=0, int in2=0,int in3=0, int in4=0){
      analogWrite (EN1, enA);
      analogWrite (EN2, enB);
      digitalWrite(IN1, in1);   
      digitalWrite(IN2, in2);
      digitalWrite(IN3, in3);   
      digitalWrite(IN4, in4);
      clearBuff();
}



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
  Serial.begin(9600);
}


void loop() {  
    

 //функция чтения сериал
  if (mySerial.available()>0){
    com = mySerial.read();
    Serial.println(com);
    
  } 
  
  
    if( com == '1') //движение вперед
    {
      drivers(180,180,1,0,0,1);
    }

    if( com == '3') //поворот - лево
    {
      drivers(120,120,1,0,1,0);
    }
    if( com == '2')//поворот - право
    {
      drivers(120,120,0,1,0,1);
    }

    if( com == '4') // остановка
    {
      drivers(0,0,0,0,0,0);
    }

     if( com == '5') // назад
    {
      drivers(150,150,0,1,1,0);
    }

   

}
