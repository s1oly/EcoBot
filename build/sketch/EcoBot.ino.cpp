#include <Arduino.h>
#line 1 "/Users/s1oly/Documents/GitHub/EcoBot/EcoBot/EcoBot.ino"
#include <AFMotor.h>
#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial bluetoothserial(9,10);

char command;

AF_DCMotor front_leftmotor(4);
AF_DCMotor front_rightmotor(3);
AF_DCMotor back_rightmotor(2);
AF_DCMotor back_leftmotor(1);

Servo servo1;
Servo servo2;


#line 18 "/Users/s1oly/Documents/GitHub/EcoBot/EcoBot/EcoBot.ino"
void runMotors(int speed);
#line 30 "/Users/s1oly/Documents/GitHub/EcoBot/EcoBot/EcoBot.ino"
void runServo(int position1, int position2);
#line 36 "/Users/s1oly/Documents/GitHub/EcoBot/EcoBot/EcoBot.ino"
void turnLeft(int duration, int speed1, int speed2);
#line 52 "/Users/s1oly/Documents/GitHub/EcoBot/EcoBot/EcoBot.ino"
void turnRight(int duration, int speed1, int speed2);
#line 68 "/Users/s1oly/Documents/GitHub/EcoBot/EcoBot/EcoBot.ino"
void spinServos();
#line 79 "/Users/s1oly/Documents/GitHub/EcoBot/EcoBot/EcoBot.ino"
void Stop();
#line 90 "/Users/s1oly/Documents/GitHub/EcoBot/EcoBot/EcoBot.ino"
void setup();
#line 97 "/Users/s1oly/Documents/GitHub/EcoBot/EcoBot/EcoBot.ino"
void loop();
#line 18 "/Users/s1oly/Documents/GitHub/EcoBot/EcoBot/EcoBot.ino"
void runMotors(int speed){
  front_leftmotor.setSpeed(speed);
  front_rightmotor.setSpeed(speed);
  back_rightmotor.setSpeed(speed);
  back_leftmotor.setSpeed(speed);
  
  front_leftmotor.run(FORWARD);
  front_rightmotor.run(BACKWARD);
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
back_rightmotor.run(FORWARD);
front_leftmotor.run(BACKWARD);
back_leftmotor.run(FORWARD);
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
  back_leftmotor.run(BACKWARD);
  front_rightmotor.run(FORWARD);
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

void Stop(){
  front_leftmotor.setSpeed(0);  //Define minimum velocity
  front_leftmotor.run(RELEASE); //stop the motor when release the button
  back_leftmotor.setSpeed(0);  //Define minimum velocity
  back_leftmotor.run(RELEASE); //rotate the motor clockwise
  front_rightmotor.setSpeed(0);  //Define minimum velocity
  front_rightmotor.run(RELEASE); //stop the motor when release the button
  back_rightmotor.setSpeed(0);  //Define minimum velocity
  back_rightmotor.run(RELEASE); //stop the motor when release the butto
}

void setup()
{
	servo1.attach(10);
  servo2.attach(9);
  bluetoothserial.begin(9600);
}

void loop()
{
	
  if(bluetoothserial.available() > 0){
    command = bluetoothserial.read();
  }

  switch(command){
    case 'F':
      runMotors(100);
      break;
    case 'R':
      turnRight(1000,100,150);
      break;
    case 'L':
      turnLeft(1000,100,150);
      break;
    case 'S':
      runServo(130,130);
      break;
  }


}

