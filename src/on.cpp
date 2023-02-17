#include "motor.h"

void MOTOR_ON(){
    motor.setByteEnable(1); //in bytes not bool
}