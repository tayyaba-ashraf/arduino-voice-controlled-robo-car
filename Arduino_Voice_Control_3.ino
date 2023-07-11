
//Final For Viva
/**this code implementation will provide functionality to communicate with hardware devices 
such as voice controlled robo car using and third app */
/**in current situation we will integrate this implementaion with voice controlled robo car
and will send basic commands through arduino bluetooth controller app available on 
playstore or app store*/
#include <AFMotor.h>
#include <Servo.h>

String command;

AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

Servo myservo;



void setup() {
  
Serial.begin(9600);
myservo.attach(10);
myservo.write(90);

}

void loop() {
  
 delay(10);
 while(Serial.available()) {
  command = "";  
  command = Serial.readString();
  
    Serial.print(command);
}
  if((command == "*move forward#") ||(command == "*Move Forward#") || (command == "*MOVE FORWARD#") || (command == "*move Forward#") ||(command == "*Move forward#")  || (command == "*MOVE FORWARD#") || (command == "*move Forward#")  || (command == "*MOVE forward#") || (command == "*MOVE Forward#") || (command == "*Move FORWARD#")){
    forward();
  }
  else if((command == "*move backward#") ||(command == "*Move Backward#") || (command == "*Move backward#") || (command == "*MOVE BACKWARD#") ||(command == "*move Backward#") ||(command == "*MOVE backward#") || (command == "*move BACKWARD#") || (command == "*Move BACKWARD#")){
    backward();
  }
  
  else if((command == "*Turn Left#") ||(command == "*turn Left#") || (command == "*Turn left#") || (command == "*TURN LEFT#") ||(command == "*turn left#") || (command == "*TURN Left#")|| (command == "*Turn LEFT#") || (command == "*turn LEFT#")){
    left();
  }

  else if((command == "*Turn Right#") ||(command == "*turn right#") || (command == "*Turn right#") || (command == "*TURN RIGHT#") ||(command == "*turn Right#") || (command == "*TURN right#") || (command == "*turn RIGHT#") || (command == "*Turn RIGHT#")){
    right();
  }
 
  else if(command == "*stop#") {
    Stop();
 }
 
  command = "";
}

void forward() {
  motor1.setSpeed(200);
  motor1.run(FORWARD);
  motor2.setSpeed(200);
  motor2.run(FORWARD);
  motor3.setSpeed(200);
  motor3.run(FORWARD);
  motor4.setSpeed(200);
  motor4.run(FORWARD);
  delay(1500);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  
}

void backward() {
  motor1.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.setSpeed(255);
  motor2.run(BACKWARD);
  motor3.setSpeed(255);
  motor3.run(BACKWARD);
  motor4.setSpeed(255);
  motor4.run(BACKWARD);
  delay(1500);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void right() {
  myservo.write(180);
  delay(500);
  myservo.write(90);
  delay(500);
  motor1.setSpeed(255);
  motor1.run(FORWARD);
  motor2.setSpeed(255);
  motor2.run(BACKWARD);
  motor3.setSpeed(255);
  motor3.run(FORWARD);
  motor4.setSpeed(255);
  motor4.run(BACKWARD);
  delay(500);
  forward();
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void left() {
  myservo.write(0);
  delay(500);
  myservo.write(90);
  delay(500);
  motor1.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.setSpeed(255);
  motor2.run(FORWARD);
  motor3.setSpeed(255);
  motor3.run(BACKWARD);
  motor4.setSpeed(255);
  motor4.run(FORWARD);
  delay(500);
  forward();
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void Stop() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
