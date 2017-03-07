/*
<<<<<<< Updated upstream
 * Based on GerHarte's code here: https://github.com/GerHarte/Quadcopter/blob/master/Arduino/SetMotorSpeed.ino.
 */
=======
   Based on GerHarte's code here: https://github.com/GerHarte/Quadcopter/blob/master/Arduino/SetMotorSpeed.ino.
*/
>>>>>>> Stashed changes

Servo motor1;
Servo motor2;
int zeroValue = 50;

<<<<<<< Updated upstream
void runMotors(int throttle, float pitch){
  float motor1Value = throttle - pitch/2;
  float motor2Value = throttle + pitch/2;
=======
void runMotors(int throttle, float pitch) {
  float motor1Value = throttle - pitch / 2;
  float motor2Value = throttle + pitch / 2;
>>>>>>> Stashed changes
  motor1.write(map(motor1Value, 1151, 1908, 55, 180));
  motor2.write(map(motor2Value, 1151, 1908, 55, 180));
}

<<<<<<< Updated upstream
void stopMotors(){
=======
void stopMotors() {
>>>>>>> Stashed changes
  motor1.write(zeroValue);
  motor2.write(zeroValue);
}

