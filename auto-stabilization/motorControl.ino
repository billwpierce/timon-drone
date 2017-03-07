/*
   Based on GerHarte's code here: https://github.com/GerHarte/Quadcopter/blob/master/Arduino/SetMotorSpeed.ino.
*/

Servo motor1;
Servo motor2;
int zeroValue = 50;

void initializeMotors(){
  motor1.attach(11);
  delay(200);
  motor2.attach(10);
  delay(200);
}

void runMotors(int throttle, float pitch){
  float motor1Value = throttle - pitch / 2;
  float motor2Value = throttle + pitch / 2;
  motor1.write(map(motor1Value, 1151, 1908, 55, 180));
  motor2.write(map(motor2Value, 1151, 1908, 55, 180));
}

void stopMotors(){
  motor1.write(zeroValue);
  motor2.write(zeroValue);
}

