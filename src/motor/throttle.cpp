/* 
 * Motor thorttle state.
 * @rt.z, @
*/
string Motor::throttle(bool do_not_pass = 0) {
   //state output
   cout << "Throttle running..." << endl;

   //body of the state is below
   /* Below are cases that do not necessetate a state change
    */
   if ((Motor.motor_speed - Motor.throttle_pos) /*placeholder math formula*/ > 25) {
      Motor.motor_speed += 25; //again, placeholder math formula
      return "throttle";
   } else if ((Motor.motor_speed - Motor.throttle_pos) /*placeholder math formula*/ > 0) {
      Motor.motor_speed = Motor.throttle_pos; //again, placeholder math formula, ask powertrain about motor to axle connection
      return "throttle";
   }

   /* Below are cases that do necessetate a state change. Each case calls the state that the state machine should go to, which would do all the work (but will not call another state)
    */
   if (!do_not_pass) {
      if (Motor.brake_pos > 0) return both(1);
      else if (Motor.throttle_pos == 0) return idle_moving(1);
   }
}
