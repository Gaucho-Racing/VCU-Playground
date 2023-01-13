#ifndef MOTORH
#define MOTORH

#include <iostream>
using namespace std;

class Motor {
   public:
      int main();
      string throttle();
      string brake();
      string idle();
   private:
      static int const zero = 0; //[placeholder]
      static bool start_pressed; 
      static int motor_speed; // [0, 100]
      static int throttle_pos; // [0, 100]
      static int brake_pos; // [0, 1]
}

#endif
