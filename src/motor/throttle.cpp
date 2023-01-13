//motor thorttle state

string Motor::throttle() {
   cout << "Throttle running..." << endl;
   //initialize data; test purposes only

   //loop
   while (1) {
      //get data: Motor.throttle_pos, Motor.motor_speed
      //check motor_speed compared to throttle_pos
      if ((Motor.motor_speed - Motor.throttle_pos) /*placeholder math formula*/ > 25) {
         Motor.motor_speed += 25; //again, placeholder math formula
      } else if ((Motor.motor_speed - Motor.throttle_pos) /*placeholder math formula*/ > 0) {
         Motor.motor_speed = Motor.throttle_pos; //again, placeholder math formula, ask powertrain about motor to axle connection
      }
      //else, not anything.
      //wait for input:
      if (Motor.brake_pos > 0) {
         return "both";
      } else if (Motor.throttle_pos == 0) {
         return "idle_moving";
      }
   }
}