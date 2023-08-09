# 1 "/Users/s1oly/Documents/GitHub/EcoBot/EcoBot/EcoBot.ino"
# 2 "/Users/s1oly/Documents/GitHub/EcoBot/EcoBot/EcoBot.ino" 2
# 3 "/Users/s1oly/Documents/GitHub/EcoBot/EcoBot/EcoBot.ino" 2
# 4 "/Users/s1oly/Documents/GitHub/EcoBot/EcoBot/EcoBot.ino" 2



AF_DCMotor front_leftmotor(4);
AF_DCMotor front_rightmotor(3);
AF_DCMotor back_rightmotor(2);
AF_DCMotor back_leftmotor(1);

Servo servo1;
Servo servo2;


void runMotors(int speed){
  front_leftmotor.setSpeed(speed);
  front_rightmotor.setSpeed(speed);
  back_rightmotor.setSpeed(speed);
  back_leftmotor.setSpeed(speed);

  front_leftmotor.run(1);
  front_rightmotor.run(2);
  back_rightmotor.run(1);
  back_leftmotor.run(2);
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
front_rightmotor.run(2);
back_rightmotor.run(1);
front_leftmotor.run(2);
back_leftmotor.run(1);
delay(duration);
front_rightmotor.run(4);
back_rightmotor.run(4);
front_leftmotor.run(4);
back_leftmotor.run(4);
}

void turnRight(int duration, int speed1, int speed2){
  front_leftmotor.setSpeed(speed1);
  back_leftmotor.setSpeed(speed1);
  front_rightmotor.setSpeed(speed2);
  back_rightmotor.setSpeed(speed2);
  front_leftmotor.run(1);
  back_leftmotor.run(2);
  front_rightmotor.run(1);
  back_rightmotor.run(2);
  delay(duration);
  front_rightmotor.run(4);
  back_rightmotor.run(4);
  front_leftmotor.run(4);
  back_leftmotor.run(4);
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
