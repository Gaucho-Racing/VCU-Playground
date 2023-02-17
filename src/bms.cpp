// loop that calls state functions
// calls battry managemente stae funcitons
// charging, full-charged, ready-to-charge, pre-cahrging, do-not-charge
//, charged, pre-charge, 

#include <iostream>
#include "startup.cpp"
#include "off.cpp"
#include "fail.cpp"
#include "Motor.cpp"

using namespace std;


int main(int argc, char const *argv[]) {
    int state = 0;
    if (argc >= 2) {
        state = stoi(argv[1]);
    }
