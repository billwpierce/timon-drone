#include <Servo.h>

void setup() {
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
