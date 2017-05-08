int disableCounter;
int enableCounter;
boolean activated;

void readyActivation(){
  activated = false;
  Serial.println("DEACTIVATED");
}

void checkForActivation(){
  if (safeThrottle() < 1170 && safeRudder() > 1895 && activated) {
    enableCounter = 0;
    disableCounter += 1;
    if (disableCounter > 50) {
      activated = false;
      Serial.println("DEACTIVATED");
    }
  }
  if (safeThrottle() < 1170 && safeRudder() < 1142 && !activated) {
    disableCounter = 0;
    enableCounter += 1;
    if (enableCounter > 50) {
      activated = true;
      Serial.println("ACTIVATED");
    }
  }
}

boolean getActivation(){
  return activated;
}

