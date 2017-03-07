#include <Servo.h>

void setup() {
  setupIMU();
  setupController();
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
