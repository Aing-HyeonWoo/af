#define trig 9
#define echo 8

void setup() {
  Serial.begin(9600);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {

  int light = analogRead(A0);
  long duration;    // 거리 측정을 위한 변수 선언
  // 트리거 핀으로 10us 동안 펄스 출력
  digitalWrite(trig, LOW);        // Trig 핀 Low
  delayMicroseconds(2);            // 2us 딜레이
  digitalWrite(trig, HIGH);    // Trig 핀 High
  delayMicroseconds(10);            // 10us 딜레이
  digitalWrite(trig, LOW);        // Trig 핀 Low
   
  duration = pulseIn(echo, HIGH); 

  if(duration < 1000 && light > 500){
    Serial.println(1);
  } else{
    Serial.println(0);
  }


  delay(100);



}
