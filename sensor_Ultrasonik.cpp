#include <NewPing.h>
#define TRIGGER_PIN  6
#define ECHO_PIN     9
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(50);
  unsigned int uS = sonar.ping();
  unsigned int distance = uS / US_ROUNDTRIP_CM;
  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println("cm");
}