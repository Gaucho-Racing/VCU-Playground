//charging.cpp
//@vedantshah, @yarwinliu, @rt.z

#include "bms.cpp"
#include "do_not_charge.cpp"

int state_3_charging() {
   int state = 0;
   while(state != 7){
      switch (state) {
         case -1:
            state = state_minus_1_do_not_charge(); //do not charge
            break;
         case 0:
            state = state_0_ready_to_charge(); // ready to charge
            break;
         case 1:
            state = state_1_not_charging(); //not charging
            break;
         case 2:
            state = state_2_charging(); //charging
            break;
         case 3:
            state = state_3_fully_charged(); //fully charged
            break;
         case 19:
            return -1;
         case 20:
            return 0;
         case 22:
            return 2;
      }
   }
   return 0;
}
