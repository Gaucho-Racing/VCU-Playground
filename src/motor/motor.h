#ifndef MOTORH
#define MOTORH

#include <iostream>
using namespace std;

class Motor {
   public:
      /* 
      * The main running function of the motor state machine. 
      * This will control the states the motor goes through based on the outputs of the previous state. 
      * -rt.z
      *
      * @returns int return type is a stub. planning to return something to notify core main function whether to shutdown the car completely (off switch, something failed), move to next step in processing logic, or some other special case.
      */
      int state_update();
   private:
      string throttle();
      string brake();
      string idle();
      
      static string state; //the current state of the motor logic
      static bool start_pressed; 
      static int motor_speed; // [0, 100]
      static int throttle_pod; // [0, 100]
      static int brake_pod; // [0, 1]

      static int set_motor_speed(int speed); // in: [0, 100], out:[0, 100] (current speed)

      //other data to be stored.
};

#endif
