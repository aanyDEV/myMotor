#include <Servo.h> 

Servo myServo;
void setup() {
  myServo.attach(8);
  Serial.begin(9600);
}

void loop() {
  for (int angle = 0; angle <= 180; angle++) { 
    myServo.write(angle);            
    delay(15);                       
    Serial.print("Sudut: ");
    Serial.println(angle);
  }

  delay(1000);

  for (int angle = 180; angle >= 0; angle--) {
    myServo.write(angle);            
    delay(15);                       
    Serial.print("Sudut: ");
    Serial.println(angle);
  }

  delay(1000);
}