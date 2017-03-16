/*
   Based on GerHarte's code here: https://github.com/GerHarte/Quadcopter/blob/master/Arduino/SetMotorSpeed.ino.
*/

Servo motor1;
Servo motor2;
int zeroValue = 55;
int safeValue = 50;

void initializeMotors(){
  motor1.attach(11);
  delay(200);
  motor2.attach(10);
  delay(200);
  motor3.attach(9);
  delay(200);
  motor4.attach(6);
  delay(200);
}

void runMotors(int throttle, float pitch, float roll){ //TODO: Make pitch/roll changes correct based on IMU.
  float motor1Value = throttle - pitch + roll;
  float motor2Value = throttle - pitch - roll;
  float motor3Value = throttle + pitch + roll;
  float motor4Value = throttle + pitch - roll;
  motor1.write(map(motor1Value, 1151, 1908, zeroValue, 180));
  motor2.write(map(motor2Value, 1151, 1908, zeroValue, 180));
  motor3.write(map(motor3Value, 1151, 1908, zeroValue, 180));
  motor4.write(map(motor4Value, 1151, 1908, zeroValue, 180));
}

void stopMotors(){
  motor1.write(safeValue);
  motor2.write(safeValue);
}

//  Motor Map:
//  1  2
//   \/
//   /\
//  3  4
