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

