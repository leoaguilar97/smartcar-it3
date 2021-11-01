#define echoUltraSonicFront A14
#define triggerUltraSonicFront A12

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

//void sendEvent(int count) { return; }

char enabled = 1; // 0 inactivo //1 activo

void setup() {
  Serial.begin(115200);
  Serial.println(">> START");

  pinMode(echoUltraSonicFront, INPUT);
  pinMode(triggerUltraSonicFront, OUTPUT);

  randomSeed(analogRead(A15));
}

boolean started = false;

void loop() {
  if (enabled) {
    if (!started) {
      //forward();
      started = true;
    }
    //Serial.println("INICIO");
    run_car();
  }
  else if (started) {
    stop_motors();
    started = false;
  }
  //Serial.print("Distancia: ");
  //Serial.println(String(check_distance()));
  delay(10);
}
