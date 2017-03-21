#include <Servo.h>

void setup() {
  Serial.begin(115200);
  setupIMU();
  setupController();
  initializeMotors();
}

void loop() {
  readIMU();
  readController();
  if(getActivation()){
    runMotors(getThrottle(), calculatePitchPID(getPitch()));
  }else{
    stopMotors();
  }
}
