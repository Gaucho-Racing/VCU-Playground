#include <iostream>
#include "startup.cpp"
#include "off.cpp"
#include "fail.cpp"
#include "drive.cpp"
#include "charging.cpp"

using namespace std;

/*
   TEMPLATE for each state function

   int state_<<state code>>_<<state name>>() {
      cout << "Changing state to …" << endl;
      while (1) {
         if (check for possible critical failures) {
            return -1;
         }
         if (check for possible non-critical failures) {
            //use dashboard library to send warning to dash.
         }
         //take inputs from CAN system
         //execute and set outputs via CAN system
         //check if conditions necessetate state change. return code of state to change to if conditions necessitate.
      }
   }
*/

int main(int argc, char const *argv[]) {
   int state = 0;
   if (argc >= 2) {
      state = stoi(argv[1]);
   }
   /*
   an interative solution to prevent stack overflow (it's quite obvious and easy)
   as we will be swtching states many many Many MANY times during the actual thing
   this works by having each state function return the "code" for the state to go
   to upon an input to switch states is recieved.
   The main function then directs execution to the corresponding state, with 7 being
   "turn off the machine" (software cannot keep track of the state while the machine is off)
   */
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
         //will add more states as necessary
         case 7:
            break;
      }
   }
   return 0;
}