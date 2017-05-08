String incomingByte;   // for incoming serial data

//Readings:
//1. Left- Bottom Left
//2. Left- Top Right
//3. Right - Bottom Left
//4. Right - Bottom Right

int currentRead = 0;
int totalMinThrottle = 0;
int throttleMin = 0;
int totalMinRudder = 0;
int rudderMin = 0;
int totalMaxThrottle = 0;
int throttleMax = 0;
int totalMaxRudder = 0;
int rudderMax = 0;

int totalMinElevator = 0;
int elevatorMin = 0;
int totalMinAileron = 0;
int aileronMin = 0;
int totalMaxElevator = 0;
int elevatorMax = 0;
int totalMaxAileron = 0;
int aileronMax = 0;

int currentThrottle;
int currentRudder;
int currentElevator;
int currentAileron;

int throttle_pin = 8;
int aileron_pin = 4;
int elevator_pin = 7;
int rudder_pin = 12;

void setup() {
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
  pinMode(throttle_pin, INPUT); // Set our input pins as such
  pinMode(aileron_pin, INPUT);
  pinMode(elevator_pin, INPUT);
  pinMode(rudder_pin, INPUT);
}

void loop() {
  int currentRead = 0;
  int totalMinThrottle = 0;
  int throttleMin = 0;
  int totalMinRudder = 0;
  int rudderMin = 0;
  int totalMaxThrottle = 0;
  int throttleMax = 0;
  int totalMaxRudder = 0;
  int rudderMax = 0;

  int totalMinElevator = 0;
  int elevatorMin = 0;
  int totalMinAileron = 0;
  int aileronMin = 0;
  int totalMaxElevator = 0;
  int elevatorMax = 0;
  int totalMaxAileron = 0;
  int aileronMax = 0;

  Serial.println("Enter anything into serial to begin reading...");
  //  //        // send data only when you receive data:
  //  //        if (Serial.available() > 0) {
  //  //                // read the incoming byte:
  //  //                incomingByte = Serial.readString();
  //  //
  //  //                // say what you got:
  //  //                Serial.print("I received: ");
  //  //                Serial.println(incomingByte);
  //  //        }
  while (currentRead == 0) {
    if (Serial.available() > 0) {
      currentRead = 1;
      break;
    }
  }
  Serial.println("Put the left joystick to the bottom left");
  Serial.println("Reading 1000 values. Starting in 5 seconds...");
  delay(1000);
  Serial.println("4 seconds...");
  delay(1000);
  Serial.println("3 seconds...");
  delay(1000);
  Serial.println("2 seconds...");
  delay(1000);
  Serial.println("1 seconds...");
  delay(1000);
  Serial.println("Beginning read...");
  for (int i = 0; i < 1000; i++) {
    currentThrottle = pulseIn(throttle_pin, HIGH, 25000); //Set the variables to match the input
    currentRudder = pulseIn(rudder_pin, HIGH, 25000);
    if (currentThrottle * currentRudder == 0) {
      i--;
      Serial.println("Not working: " + String(currentThrottle) + ", " + String(currentRudder));
    } else {
      totalMinThrottle += currentThrottle;
      totalMinRudder += currentRudder;
      //      Serial.println(i);
    }
  }
  Serial.println("Finished Reading");
  throttleMin = totalMinThrottle / 1000;
  rudderMin = totalMinRudder / 1000;
  Serial.println("Average Min Throttle: " + String(throttleMin));
  Serial.println("Average Min Rudder: " + String(rudderMin));
  currentRead = 2;

  Serial.println("Put the left joystick to the top right");
  Serial.println("Reading 1000 values. Starting in 5 seconds...");
  delay(1000);
  Serial.println("4 seconds...");
  delay(1000);
  Serial.println("3 seconds...");
  delay(1000);
  Serial.println("2 seconds...");
  delay(1000);
  Serial.println("1 seconds...");
  delay(1000);
  Serial.println("Beginning read...");
  for (int i = 0; i < 1000; i++) {
    currentRudder = pulseIn(rudder_pin, HIGH, 25000);
    currentThrottle = pulseIn(throttle_pin, HIGH, 25000); //Set the variables to match the input
    if (currentThrottle * currentRudder == 0) {
      i--;
    } else {
      totalMaxThrottle += currentThrottle;
      totalMaxRudder += currentRudder;
    }
  }
  Serial.println("Finished Reading");
  throttleMax = totalMaxThrottle / 1000;
  rudderMax = totalMaxRudder / 1000;
  Serial.println("Average Max Throttle: " + String(throttleMin));
  Serial.println("Average Max Rudder: " + String(rudderMin));
  currentRead = 3;


  Serial.println("Put the right joystick to the bottom left");
  Serial.println("Reading 1000 values. Starting in 5 seconds...");
  delay(1000);
  Serial.println("4 seconds...");
  delay(1000);
  Serial.println("3 seconds...");
  delay(1000);
  Serial.println("2 seconds...");
  delay(1000);
  Serial.println("1 seconds...");
  delay(1000);
  Serial.println("Beginning read...");
  for (int i = 0; i < 1000; i++) {
    currentElevator = pulseIn(elevator_pin, HIGH, 25000);
    currentAileron = pulseIn(aileron_pin, HIGH, 25000);
    if (currentElevator * currentAileron == 0) {
      i--;
    } else {
      totalMinElevator += currentElevator;
      totalMinAileron += currentAileron;
    }
  }
  Serial.println("Finished Reading");
  elevatorMin = totalMinElevator / 1000;
  aileronMin = totalMinAileron / 1000;
  Serial.println("Average Min Elevator: " + String(elevatorMin));
  Serial.println("Average Min Aileron: " + String(aileronMin));
  currentRead = 4;

  Serial.println("Put the right joystick to the top right");
  Serial.println("Reading 1000 values. Starting in 5 seconds...");
  delay(1000);
  Serial.println("4 seconds...");
  delay(1000);
  Serial.println("3 seconds...");
  delay(1000);
  Serial.println("2 seconds...");
  delay(1000);
  Serial.println("1 seconds...");
  delay(1000);
  Serial.println("Beginning read...");
  for (int i = 0; i < 1000; i++) {
    currentElevator = pulseIn(elevator_pin, HIGH, 25000);
    currentAileron = pulseIn(aileron_pin, HIGH, 25000);
    if (currentElevator * currentAileron == 0) {
      i--;
    } else {
      totalMaxElevator += currentElevator;
      totalMaxAileron += currentAileron;
    }
  }
  Serial.println("Finished Reading");
  elevatorMax = totalMaxElevator / 1000;
  aileronMax = totalMaxAileron / 1000;
  Serial.println("Average Max Elevator: " + String(elevatorMax));
  Serial.println("Average Max Aileron: " + String(aileronMax));
  Serial.println(String(throttleMin) + ";" + String(throttleMax) + ";" + String(aileronMin) + ";" + String(aileronMax) + ";" + String(elevatorMin) + ";" + String(elevatorMax) + ";" + String(rudderMin) + ";" + String(rudderMax) + ";");
}
String convertToReadable(String channelReading) {
  if (channelReading.length() > 4) {
    Serial.println("ERROR: Could not convert " + String(channelReading));
    return "1500";
  } else if (channelReading.length() < 4) {
    if (channelReading.length() == 3) {
      return "0"+String(channelReading);
    }else if (channelReading.length() == 2) {
      Serial.println("Warning: ChannelReading surprising low at " + String(channelReading));
      return "00"+String(channelReading);
    }else if (channelReading.length() == 1) {
      Serial.println("ERROR: ChannelReading too low at " + String(channelReading));
      return "000"+String(channelReading);
    }else{
      Serial.println("ERROR: ChannelReading could not be converted from " + String(channelReading) + ". The string size was too low");
      return "1500";
    }
  }else{
    return String(channelReading);
  }
}

