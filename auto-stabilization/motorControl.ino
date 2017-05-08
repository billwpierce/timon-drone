/*
   Based on GerHarte's code here: https://github.com/GerHarte/Quadcopter/blob/master/Arduino/SetMotorSpeed.ino.
*/

Servo motor1;
Servo motor2;
int zeroValue = 55;
int safeValue = 50;
int throttleMin;
int throttleMax;
int aileronMin;
int aileronMax;
int elevatorMin;
int elevatorMax;
int rudderMin;
int rudderMax;

void initializeMotors() {
  motor1.attach(11);
  motor2.attach(10);
}

void runMotors(int throttle, float pitch) {
  int realThrottle = throttle;
  float motor1Value = realThrottle - pitch;
  float motor2Value = realThrottle + pitch;
  motor1.write(map(motor1Value, 1000, 2000, zeroValue, 180));
  Serial.println("Writing motor 1 at " + String(map(motor1Value, 1000, 2000, zeroValue, 180)));
  motor2.write(map(motor2Value, 1000, 2000, zeroValue, 180));
  Serial.println("Writing motor 2 at " + String(map(motor2Value, 1000, 2000, zeroValue, 180)));
}

void stopMotors() {
  motor1.write(safeValue);
  motor2.write(safeValue);
}

void setThrottleMin(int throttlemin) {
  throttleMin = throttlemin;
}
void setThrottleMax(int throttlemax) {
  throttleMax = throttlemax;
}
void setAileronMin(int aileronmin) {
  aileronMin = aileronmin;
}
void setAileronMax(int aileronmax) {
  aileronMax = aileronmax;
}
void setElevatorMin(int elevatormin) {
  elevatorMin = elevatormin;
}
void setElevatorMax(int elevatormax) {
  elevatorMax = elevatormax;
}
void setRudderMin(int ruddermin) {
  rudderMin = ruddermin;
}
void setRudderMax(int ruddermax) {
  rudderMax = ruddermax;
}
int safeThrottle() {
  return map(getThrottle(), throttleMin, throttleMax, 1000, 2000);
}
int safeAileron() {
  return map(getAileron(), aileronMin, aileronMax, 1000, 2000);
}
int safeElevator() {
  return map(getElevator(), elevatorMin, elevatorMax, 1000, 2000);
}
int safeRudder() {
  return map(getRudder(), rudderMin, rudderMax, 1000, 2000);
}

