String recentInput;
String incomingByte;   // for incoming serial data

void detectString() {
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.readString();

    // say what you got:
    Serial.println("");
    Serial.print("I received: ");
    Serial.println(incomingByte);
    if(incomingByte.length() == 40){
      recentInput = incomingByte;
      Serial.println("Correct modifier recieved");
      modifyCalibration(recentInput);
    }else{
      Serial.println("Incorrect input size of " + String(incomingByte.length()));
    }
  }
}

void modifyCalibration(String input){
  setThrottleMin(input.substring(0,4).toInt());
  Serial.println(input.substring(0,4));
  setThrottleMax(input.substring(5,9).toInt());
  Serial.println(input.substring(5,9));
  setAileronMin(input.substring(10,14).toInt());
  Serial.println(input.substring(10,14));
  setAileronMax(input.substring(15,19).toInt());
  Serial.println(input.substring(15,19));
  setElevatorMin(input.substring(20,24).toInt());
  Serial.println(input.substring(20,24));
  setElevatorMax(input.substring(25,29).toInt());
  Serial.println(input.substring(25,29));
  setRudderMin(input.substring(30,34).toInt());
  Serial.println(input.substring(30,34));
  setRudderMax(input.substring(35,39).toInt());
  Serial.println(input.substring(35,39));
}

