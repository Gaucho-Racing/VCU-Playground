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
      string off();
      string throttle(bool do_not_pass = 0);
      string idle_stationary(bool do_not_pass = 0);
      string idle_moving(bool do_not_pass = 0);
      string both(bool do_not_pass = 0);
      string normal_brake(bool do_not_pass = 0);
      string hard_brake(bool do_not_pass = 1);
      
      static string state; //the current state of the motor logic
      static bool start_pressed; 
      static int motor_speed; // [0, 100]
      static int car_speed; //[0, 100]
      static int throttle_pod; // [0, 100]
      static int brake_pod; // [0, 1]

      static int set_motor_speed(int speed); // in: [0, 100], out:[0, 100] (current speed after update)
      static int set_brakes(int brake); // in: [0, 1], out: [0, 1] (current brake after update) 

      //other data to be stored.
};

#endif
