/* 
 * Motor normal_brake and hard_brake state.
 * @rt.z
*/
#include <string>
#include "motor.cpp"

using namespace std;

string Motor::normal_brake(bool do_not_pass = 0) {
   //check for state change conditions
   if (Motor.throttle_pod > 0 && Motor.brake_pod == 0) {
      //to throttle
   }
   if (Motor.throttle_pod > 0 && Motor.throttle_pod < 25) {
      //to both
   }
   if (Motor.brake_pod == 0) {
      //to idle
   }
   if (Motor.throttle_pod >= 25) {
      //to hard_brake
   }

   //output to brake if otherwise
   Motor.set_brake(1);

   return "normal brake";
}

string Motor::hard_brake(bool do_not_pass = 1) {
   //check for state change conditions
   if (Motor.brake == 0 && Motor.throttle_pod == 0) {
      //to idle
   }
   if (Motor.brake == 0) {
      //to throttle
   }
   if (Motor.throttle_pod < 25) {
      //to normal_brake
   }

   //output to brake if otherwise
   Motor.set_brake(1);
   Motor.set_motor_speed(0);

   return "hard brake";
}
