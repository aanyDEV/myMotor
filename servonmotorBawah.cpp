#include <Servo.h>
#include <NewPing.h>
#define TRIGGER_PIN  6
#define ECHO_PIN     9
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
Servo myMotor1;
Servo myMotor2;
Servo myServo;

void setup() {
  myMotor1.attach(8);
  myMotor2.attach(4);
  myServo.attach(10);
  Serial.begin(9600);
}

void loop() {
  delay(50);
  unsigned int uS = sonar.ping();
  int distance = uS / US_ROUNDTRIP_CM;

  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println("cm");

  if (distance <= 15 && distance > 0) {
    int speed = map(distance, 1, 15, 180, 0);
    myServo.write(speed);
    myMotor1.write(speed);
    myMotor2.write(speed);
  } else {
    myServo.write(0);
    myMotor1.write(0);
    myMotor2.write(0);
  }
}