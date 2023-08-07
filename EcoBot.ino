#include <AFMotor.h>

#include <Servo.h>



AF_DCMotor front_leftmotor(1);
AF_DCMotor front_rightmotor(2);
AF_DCMotor back_rightmotor(3);
AF_DCMotor back_leftmotor(4);

Servo servo1;
Servo servo2;


void runMotors(int speed){
  front_leftmotor.setSpeed(speed);
  front_rightmotor.setSpeed(speed);
  back_rightmotor.setSpeed(speed);
  back_leftmotor.setSpeed(speed);
  
  front_leftmotor.run(BACKWARD);
  front_rightmotor.run(FORWARD);
  back_rightmotor.run(FORWARD);
  back_leftmotor.run(BACKWARD);
}

void runServo(int position1, int position2){
  servo1.write(position1);
  servo2.write(position2);
  delay(15);
}

void turnLeft(int duration, int speed1, int speed2){
front_rightmotor.setSpeed(speed1);
back_rightmotor.setSpeed(speed1);
front_leftmotor.setSpeed(speed2);
back_leftmotor.setSpeed(speed2);
front_rightmotor.run(BACKWARD);
back_rightmotor.run(BACKWARD);
front_leftmotor.run(BACKWARD);
back_leftmotor.run(BACKWARD);
delay(duration);
front_rightmotor.run(RELEASE);
back_rightmotor.run(RELEASE);
front_leftmotor.run(RELEASE);
back_leftmotor.run(RELEASE);
}

void turnRight(int duration, int speed1, int speed2){
  front_leftmotor.setSpeed(speed1);
  back_leftmotor.setSpeed(speed1);
  front_rightmotor.setSpeed(speed2);
  back_rightmotor.setSpeed(speed2);
  front_leftmotor.run(FORWARD);
  back_leftmotor.run(FORWARD);
  front_rightmotor.run(BACKWARD);
  back_rightmotor.run(BACKWARD);
  delay(duration);
  front_rightmotor.run(RELEASE);
  back_rightmotor.run(RELEASE);
  front_leftmotor.run(RELEASE);
  back_leftmotor.run(RELEASE);
}

void spinServos(){
  servo1.write(0);
  servo2.write(0);

  for(int servo_position = 0; servo_position <=180; servo_position += 1){
    servo1.write(servo_position);
    servo2.write(servo_position);
    delay(20);
  }
}

void setup()
{
	servo1.attach(10);
  servo2.attach(9);
}

void loop()
{
	spinServos();
  turnLeft(10000,2000,2000);
  turnRight(10000,2000,2000);
}
