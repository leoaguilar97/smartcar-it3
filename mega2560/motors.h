
#include <AFMotor.h>

#define fwd_speed 180
#define max_speed 120

//variables para el uso de motores
AF_DCMotor motor_L1(1, MOTOR12_8KHZ); //motor IZQUIERDA FRONTAL
AF_DCMotor motor_R1(4, MOTOR34_8KHZ); //motor DERECHA FRONTAL
AF_DCMotor motor_L2(2, MOTOR12_8KHZ); //motor IZQUIERDO TRASERO
AF_DCMotor motor_R2(3, MOTOR34_8KHZ); //motor DERECHA TRASERA

// #1 -> FRONTAL
// #2 -> TRASERO

//motor 4 es adelante derecha
//motor 3 es atras derecha
//motor 2 es atras izquierda
//motor 1 es adelante izquierda

#define R1B FORWARD
#define R2B FORWARD
#define L1B FORWARD
#define L2B BACKWARD

#define R1F BACKWARD
#define R2F BACKWARD
#define L1F BACKWARD
#define L2F FORWARD

void stop_motors() {
  motor_R1.run(RELEASE);
  motor_R2.run(RELEASE);
  motor_L1.run(RELEASE);
  motor_L2.run(RELEASE);
}

void forward() {
  motor_R1.setSpeed(fwd_speed);
  motor_R2.setSpeed(fwd_speed);
  motor_L1.setSpeed(fwd_speed);
  motor_L2.setSpeed(fwd_speed);

  motor_R1.run(R1F);
  motor_R2.run(R2F);
  motor_L1.run(L1F);
  motor_L2.run(L2F);
}

void backward() {
  motor_R1.setSpeed(fwd_speed);
  motor_R2.setSpeed(fwd_speed);
  motor_L1.setSpeed(fwd_speed);
  motor_L2.setSpeed(fwd_speed);

  motor_R1.run(R1B);
  motor_R2.run(R2B);
  motor_L1.run(L1B);
  motor_L2.run(L2B);
}

void go_right() {
  Serial.println("Moviendo hacia derecha");
  stop_motors();
  delay(100);

  motor_R1.run(R1B);
  motor_R2.run(R2B);
  motor_L1.run(L1F);
  motor_L2.run(L2F);
}

void go_left() {
  Serial.println("Moviendo hacia izquierda");
  stop_motors();
  delay(100);

  motor_R1.run(R1F);
  motor_R2.run(R2F);
  motor_L1.run(L1B);
  motor_L2.run(L2B);
}

//verifica si hay algún obstaculo
void check_obstacles() {
  if (check_distance() < 180) {
    stop_motors();
    delay(500);
    
    backward();
    while (check_distance() < 200) {
      delay(100);
    }
    stop_motors();
    
    if (random(100) % 2 == 0) {
      go_right();
    } else {
      go_left();
    }

    delay(750);
    
    stop_motors();
    delay(500);
    
    forward();
  }
}

// funcion que dirige para ir al punto de entrega
void run_car() {
  check_obstacles();
}
