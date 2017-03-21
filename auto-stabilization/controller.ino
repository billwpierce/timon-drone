/*
   Modified from:
   RC PulseIn Serial Read out
   By: Nick Poole
   SparkFun Electronics
*/

int channel_throttle; // Here's where we'll keep our channel values
int channel_aileron; 
int channel_elevator;
int channel_rudder;  

int throttle_pin = 13;
int aileron_pin = 4;
int elevator_pin = 7;
int rudder_pin = 8;

void setupController() {
  pinMode(throttle_pin, INPUT); // Set our input pins as such
  pinMode(aileron_pin, INPUT);
  pinMode(elevator_pin, INPUT);
  pinMode(rudder_pin, INPUT);
}

void readController() {
  channel_throttle = pulseIn(throttle_pin, HIGH, 25000); //Set the variables to match the input
  channel_aileron = pulseIn(aileron_pin, HIGH, 25000);
  channel_elevator = pulseIn(elevator_pin, HIGH, 25000);
  channel_rudder = pulseIn(rudder_pin, HIGH, 25000);
}

int getThrottle() {
  return channel_throttle;
}
int getAileron() {
  return channel_aileron;
}
int getElevator() {
  return channel_elevator;
}
int getRudder() {
  return channel_rudder;
}
