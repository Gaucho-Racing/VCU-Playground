/*
 * Start the motor
 * @rt.z
 */

using namespace std;

string Motor::ST_F_start() {
   //starting procedure, if any
   cout << "Motor is starting" << endl;
   Motor::set_motor_speed(Motor::throttle_pod);
   //check output of motor??? 
   //InternalEvent to throttle
}
