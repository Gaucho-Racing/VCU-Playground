#include "motor.h"
using namespace std;

int Motor::state_update() {
   cout << "MOTOOOOOOOOOOOOOOOOOOOOOOOOOOR!" << endl;
   //update the inputs to the motor of the motor class (start_pressed, motor_speed, throttle_pod, brake_pod)
   //return control to main, if necessary (off or fail)
   //run one instance of the while loop of the lightbulb tests, only modified for motor logic.
   //set next state (private static string variable state) to next state as returned by the state function that was run above. 
   state = "off";
   return 0; 
}

int set_motor_speed(int speed) {
   return 50;
}

int set_brake(int brake) {
   return 1;
}

#include "throttle.cpp"
#include "brake.cpp"
//#include "idle.cpp"


//main function runs a loop that consistantly runs the "state_update" functions of each macro-state class
//"state_update" runs a private function of corresponding state class and sets the next state of this macro-state class
//each state function that executes one loop of the current state
