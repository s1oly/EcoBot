#include <Arduino.h>
#line 1 "/Users/s1oly/Documents/GitHub/EcoBot/EcoBot/EcoBot.ino"
#include <AFMotor.h>

#include <Servo.h>

Servo myservo; 

AF_DCMotor front_leftmotor(1);
AF_DCMotor front_rightmotor(2);
AF_DCMotor back_rightmotor(3);
AF_DCMotor back_leftmotor(4);

#line 12 "/Users/s1oly/Documents/GitHub/EcoBot/EcoBot/EcoBot.ino"
void runMotors(int speed);
#line 24 "/Users/s1oly/Documents/GitHub/EcoBot/EcoBot/EcoBot.ino"
void runServo(int position);
#line 29 "/Users/s1oly/Documents/GitHub/EcoBot/EcoBot/EcoBot.ino"
void turnLeft(int duration, int speed1, int speed2);
#line 45 "/Users/s1oly/Documents/GitHub/EcoBot/EcoBot/EcoBot.ino"
void turnRight(int duration, int speed1, int speed2);
#line 61 "/Users/s1oly/Documents/GitHub/EcoBot/EcoBot/EcoBot.ino"
void setup();
#line 66 "/Users/s1oly/Documents/GitHub/EcoBot/EcoBot/EcoBot.ino"
void loop();
#line 12 "/Users/s1oly/Documents/GitHub/EcoBot/EcoBot/EcoBot.ino"
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

void runServo(int position){
  myservo.write(position);
  delay(15);
}

void turnLeft(int duration, int speed1, int speed2){
front_rightmotor.setSpeed(speed1);
back_rightmotor.setSpeed(speed1);
front_leftmotor.setSpeed(speed2);
back_leftmotor.setSpeed(speed2);
front_rightmotor.run(FORWARD);
back_rightmotor.run(FORWARD);
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

void setup()
{
	
}

void loop()
{
	
}

