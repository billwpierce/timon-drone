#include <Servo.h>

void setup() {
  Serial.begin(9600);
  setupIMU();
  setupController();
  initializeMotors();
}

void loop() {
  readIMU( );
  readController();
  detectString();
  checkForActivation();
  if(getActivation()){
    runMotors(safeThrottle(), calculatePitchPID(getPitch()));
  }else{
    stopMotors();
  }
//  Serial.print("P " + String(getPitch()));
//  Serial.print(" Ro " + String(getRoll()));
//  Serial.println(" Y " + String(getYaw()));
//  Serial.print(" T " + String(safeThrottle()));
//  Serial.print(" A " + String(safeAileron()));
//  Serial.print(" E " + String(safeElevator()));
//  Serial.println(" Ru " + String(safeRudder()));
  delay(50);
}
