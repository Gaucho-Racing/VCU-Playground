#include <iostream>
using namespace std;

struct failed {

}

/*
 * one instance of this "failed" struct will be on the heap.
 * the pointer to that instance will be a global variable on main.cpp for all functions to access.
 * any state function is able to modify that struct instance and send state -1
 * this function, the state -1 function, will read this struct and do what's necessary, intiate/facilite shutdown of the entire system (send state 7), or send a signal to the dashboard to show a warning.
 * if system shutdown has not been facilitated, this will send state 1 (startup)?
*/

int state_minus_1_fail(failed* failstates) {
   //if critical error: 
   //intiate hardware that permanently shuts off the system
   //return state 7

   //if non-critical error: 
   //for each failed thing…
   //send the specific related information to the dashboard


}
