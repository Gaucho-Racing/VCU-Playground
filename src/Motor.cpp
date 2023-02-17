#include "Motor.h"
#include <iostream>
using namespace std;
#include <cassert>

//calculates what to send to the 
double calcPow(){
    /* Insert Math lmao */
    return 0.0;
}

void Motor::setSpeed(MotorData* mData){
    //check that mData is accessible
    if(!mData){
        std::cerr << "Motor.setSpeed(): no valid motor data";
        return;
    }

    //  The power to the Motor(s) must be immediately and completely shut down when both of the following exist at the same time:
    // • The mechanical brakes are actuated
    // • The APPS signals more than 25% pedal travel
    // Brakes and Throttle are not pressed at the same time beyond acceptable params  
    //assuming appsPos & bspdPos is in percents converted to decimal
    
    else if (mData->appsPos>0.25 && mData->bspdPos > 0.05)
    {
        //Turn Off Motor, set Motor Power to 0
    } 
    
    //start up
    else if (/* Initial */)
    {

        /* code */
    } 
    
    //traction control

    else if (/*isok*/) {
        /* code */
    } else{
        cerr << "motor: should never be here, something is really wrong" << endl;
    }
    
    


}