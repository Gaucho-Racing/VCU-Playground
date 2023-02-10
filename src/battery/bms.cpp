// loop that calls state functions
// calls battry managemente stae funcitons
// charging, full-charged, ready-to-charge, pre-cahrging, do-not-charge
//, charged, pre-charge, 

#include <iostream>
#include "startup.cpp"
#include "off.cpp"
#include "fail.cpp"
#include "Motor.cpp"
#include "battery.cpp"

using namespace std;


int main(int argc, char const *argv[]) {
    int state = 0;
    if (argc >= 2) {
        state = stoi(argv[1]);
    }

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
                break;
            case 7:
                break;
        }
    }
    return 0;
}