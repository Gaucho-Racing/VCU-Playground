// loop that calls state functions
// calls battry managemente stae funcitons
// charging, full-charged, ready-to-charge, pre-cahrging, do-not-charge
//, charged, pre-charge, 

#include <iostream>
#include "do_not_charge.cpp"
#include "charging.cpp"
#include "full_charged.cpp"
#include "ready_to_charge.cpp"

using namespace std;

int state_3_charging() {
    int state = 0;
    while(state != 7){
        switch (state){
            case 0:
                // charging
                break;
            case 1:
                // fully-charged
                break;
            case 2:
                // ready-to-charge
                break;
            case 3:
                // pre-charging
                break;
            case 4:
                // do not charge
                if (state == -1) return -1;
                break;
            case 7:
                break;
        }
    }
    return 2;
}