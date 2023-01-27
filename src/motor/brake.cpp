/* 
 * Motor normal_brake and hard_brake state and stationary
 * Brake is mechanical, only controls motor
 * @rt.z
 * @yarwinliu
*/
#include <string>
#include "motor.cpp"
//#include "Node.h" //from CAN-work repo

using namespace std;
int tooMuchBrake = 75; //assuming brake and throttle is [0, 100] -rt.z, 
int tooMuchThrottle = 25;

//decides which brake to do (normal or hard brake)
string Motor::brake(){
   if(getThrottleIn()>0 && getBrakeIn()>tooMuchBrake) {
      hard_brake();
   } else if(getThrottleIn()>tooMuchThrottle && getBrakeIn()>0) {
      hard_brake();
   } else if (getThrottleIn()>0 && getBrakeIn()>0){
      throttle_and_brake();
   }
   /*else if(getBrakeIn()>0) { 
      normal_brake();
   }*/ else {
      return;
   }
}

/*
string Motor::normal_brake() {
   //brake does nothing, mechanically controlled
   return "normal brake";
}s
*/

string Motor::hard_brake() {
   setSpeed(0); //set motor speed to zero, mechanical brake will do the rest
   
   return "hard brake";
}

string Motor::throttle_and_brake() {
   setSpeed(getThrottleIn());
   return "throttle and brake";
}
