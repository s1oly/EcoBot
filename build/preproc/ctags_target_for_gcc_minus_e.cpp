# 1 "/Users/s1oly/Documents/GitHub/EcoBot/EcoBot/EcoBot.ino"
# 2 "/Users/s1oly/Documents/GitHub/EcoBot/EcoBot/EcoBot.ino" 2

# 4 "/Users/s1oly/Documents/GitHub/EcoBot/EcoBot/EcoBot.ino" 2

Servo myservo;

AF_DCMotor front_leftmotor(1);
AF_DCMotor front_rightmotor(2);
AF_DCMotor back_rightmotor(3);
AF_DCMotor back_leftmotor(4);

void runMotors(int speed){
  front_leftmotor.setSpeed(speed);
  front_rightmotor.setSpeed(speed);
  back_rightmotor.setSpeed(speed);
  back_leftmotor.setSpeed(speed);

  front_leftmotor.run(2);
  front_rightmotor.run(1);
  back_rightmotor.run(1);
  back_leftmotor.run(2);
}

void runServo(int position){
  myservo.write(position);
  delay(15);
}

void turnLeft(int duration, int speed1, int speed2){
front_rightmotor.setSpeed(speed1);
back_rightmotor.setSpeed(speed1);
front_leftmotor.setSpeed(speed2);
back_leftmotor.setSpeed(speed2);
front_rightmotor.run(1);
back_rightmotor.run(1);
front_leftmotor.run(2);
back_leftmotor.run(2);
delay(duration);
front_rightmotor.run(4);
back_rightmotor.run(4);
front_leftmotor.run(4);
back_leftmotor.run(4);
}

void setup()
{

}

void loop()
{

}
