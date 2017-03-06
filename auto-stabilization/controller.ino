/*
   Modified from:
   RC PulseIn Serial Read out
   By: Nick Poole
   SparkFun Electronics
*/

int channel_throttle; // Here's where we'll keep our channel values
int channel_aileron;  //roll
int channel_elevator; //pitch
int channel_rudder;   //yaw

void setupController() {
  pinMode(2, INPUT); // Set our input pins as such
  pinMode(4, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
}

void readController() {
  channel_throttle = pulseIn(2, HIGH, 25000); //Set the variables to match the input
  channel_aileron = pulseIn(4, HIGH, 25000);
  channel_elevator = pulseIn(7, HIGH, 25000);
  channel_rudder = pulseIn(8, HIGH, 25000);
}

