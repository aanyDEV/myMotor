#include <Servo.h>
#include <NewPing.h>

#define TRIGGER_PIN  6
#define ECHO_PIN     9
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
int totBelok = 0;
Servo myMotor1;
Servo myMotor2;
Servo myServo;
int pos = 0;

void setup() {
  myMotor1.attach(8);
  myMotor2.attach(4);
  myServo.attach(10);
  Serial.begin(9600);
}

void loop() {
  unsigned int uS = sonar.ping();
  int distance = uS / US_ROUNDTRIP_CM;

  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println("cm");

  if (distance < 10) {
    totBelok++;
    if (totBelok % 2 == 0) {
      myMotor1.write(225); // Gerak cepat
      myMotor2.write(225); // Gerak cepat
      myServo.write(45);   // Belok ke kanan 45 derajat
      delay(1000);
      Serial.print("Total belokan terdeteksi: ");
      Serial.println(totBelok);
    }else {
      myMotor1.write(225); // Gerak cepat
      myMotor2.write(225); // Gerak cepat
      myServo.write(135);   // Belok ke kiri 45 derajat
      delay(1000);
      Serial.print("Total belokan terdeteksi: ");
      Serial.println(totBelok);
    }
    
  } else {
    myMotor1.write(100); // Gerak normal
    myMotor2.write(100); // Gerak normal
    myServo.write(90);    // Kembali ke posisi semula
  }
  
  delay(5000); // Delay di luar kondisi untuk menghindari pembacaan terlalu cepat
}