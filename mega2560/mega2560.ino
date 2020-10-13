#include <Wire.h>

#define echoUltraSonicFront A12
#define triggerUltraSonicFront A13

long duration = 0;

long check_distance() {
  digitalWrite(triggerUltraSonicFront, LOW);
  delayMicroseconds(2);

  digitalWrite(triggerUltraSonicFront, HIGH);

  delayMicroseconds(10);
  digitalWrite(triggerUltraSonicFront, LOW);

  duration = pulseIn(echoUltraSonicFront, HIGH);
  return (duration * 0.034 / 2 ) * 10;
}

#include "motors.h"

void sendEvent(int count) { return; }

char enabled = 0; // 0 inactivo //1 activo

void receiveEvent (int count) {
  while (!Wire.available()) {}
  enabled = Wire.read();
}

void setup() {
  Serial.begin(115200);
  Serial.println(">> START");

  pinMode(echoUltraSonicFront, INPUT);
  pinMode(triggerUltraSonicFront, OUTPUT);

  randomSeed(analogRead(A15));
  
  Wire.begin(8);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(sendEvent);
}

boolean started = false;

void loop() {
  if (enabled) {
    if (!started) {
      forward();
      started = true;
    }

    run_car();
  }
  else if (started) {
    stop_motors();
    started = false;
  }

  delay(10);
}
