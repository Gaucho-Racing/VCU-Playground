//main.cpp
//@rt.z, @Th3w1ll

#include <iostream>

#include "Nodes.h"
#include "bms.cpp" //make into separate files later
#include "charging.cpp"
#include "do_not_charge.cpp"
#include "fail.cpp"
#include "drive.cpp"
#include "charging.cpp"

using namespace std;


int main(int argc, char const *argv[]) {
   int state = 0;
   if (argc >= 2) {
      state = stoi(argv[1]); //initial state upon startup
   }
   /*
   an interative solution to prevent stack overflow (it's quite obvious and easy)
   as we will be swtching states many many Many MANY times during the actual thing
   this works by having each state function return the "code" for the state to go
   to upon an input to switch states is recieved.
   The main function then directs execution to the corresponding state, with 7 being
   "turn off the machine" (software cannot keep track of the state while the machine is off)
   */

  //loop through each state
  //if conditions are met for a state, step into it
  //the state loops until conditions are met for a state change
   while (state != 7) {
      switch (state) {
         case -1:
            state = state_minus_1_fail();
            break;
         case 0:
            state = state_0_off();
            break;
         case 1:
            state = state_1_startup();
            break;
         case 2:
            state = state_2_drive();
            break;
         case 3:
            state = state_3_charging();
            break;
         //add more states as necessary
         case 7:
            break;
         default:
            break;
      }
   }
   return 0;
}
