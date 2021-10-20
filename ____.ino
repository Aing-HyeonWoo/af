#include <SoftwareSerial.h>

#define trig 9
#define echo 8

SoftwareSerial mySerial(2, 3);

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
}
s
void loop() {

  
  long duration;    // 거리 측정을 위한 변수 선언
  long value = 0;

  while(1){
    

    int light = analogRead(A0);

    // 트리거 핀으로 10us 동안 펄스 출력
    digitalWrite(trig, LOW);        // Trig 핀 Low
    delayMicroseconds(2);            // 2us 딜레이
    digitalWrite(trig, HIGH);    // Trig 핀 High
    delayMicroseconds(10);            // 10us 딜레이
    digitalWrite(trig, LOW);        // Trig 핀 Low
     
    duration = pulseIn(echo, HIGH); 
    
    if(duration < 1000 && light > 500){
      value = value + 1;
    }
  
    Serial.println(value);
    mySerial.println(value);
    
    delay(500);
  }
}
