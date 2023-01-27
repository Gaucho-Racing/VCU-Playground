/*
 * Start the motor
 * @rt.z
 */

using namespace std;

string Motor::ST_F_start() {
   //starting procedure
   Motor::set_motor_speed(Motor::throttle_pod);
   //InternalEvent to throttle
}
