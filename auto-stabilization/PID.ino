/*
   Based on Joop Brooking's tutorial/code: http://www.brokking.net/ymfc-al_main.html.
*/

float pitch_pid_p = 0.0;
float pitch_pid_i = 0.0;
float pitch_pid_d = 0.0;

float pitch_pid_error_temp;
float pitch_pid_setpoint;
float pitch_pid_i_mem;
float pitch_pid_last_error;
float pitch_pid_output;

float calculatePitchPID(float pitch) {
  pitch_pid_error_temp = pitch - pitch_pid_setpoint;
  pitch_pid_i_mem += pitch_pid_i * pitch_pid_error_temp;
  pitch_pid_output = pitch_pid_p * pitch_pid_error_temp + pitch_pid_i_mem + pitch_pid_d * (pitch_pid_error_temp - pitch_pid_last_error);
  pitch_pid_last_error = pitch_pid_error_temp;
  return pitch_pid_output;
}

float roll_pid_p = 0.0;
float roll_pid_i = 0.0;
float roll_pid_d = 0.0;

float roll_pid_error_temp;
float roll_pid_setpoint;
float roll_pid_i_mem;
float roll_pid_last_error;
float roll_pid_output;

float calculateRollPID(float roll) {
  roll_pid_error_temp = roll - roll_pid_setpoint;
  roll_pid_i_mem += roll_pid_i * roll_pid_error_temp;
  roll_pid_output = roll_pid_p * roll_pid_error_temp + roll_pid_i_mem + roll_pid_d * (roll_pid_error_temp - roll_pid_last_error);
  roll_pid_last_error = roll_pid_error_temp;
  return roll_pid_output;
}

