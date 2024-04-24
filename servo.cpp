#include <Servo.h>
#include <NewPing.h>
#define TRIGGER_PIN  6
#define ECHO_PIN     9
#define MAX_DISTANCE 200
#define SERVO_PIN    8

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
Servo myServo;

void setup() {
  myServo.attach(SERVO_PIN);
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
  } else {
    myServo.write(0);
  }
}