// if there is any error, then don't charge

//already checked not moving, no errors (voltage)
bool chargeOrNot() {
   if (getHealth() < 80 || getTemp() < 0 || getTemp() > 60) {  
      //At these conditions, the chemistry of a Li-ion battery may go terribly wrong
      //if something is wrong, abort
      return false;
   } else {  
      return true;
   }
}

int state_minus_1_do_not_charge() {
   cout << "Switching state to -1: Do not charge..." << endl;
   cout << "CAN: send warning for dashboard to display: DO NOT CHARGE!!" << endl;
   cout << "CAN: Command BMS or AIR to not accept any positive current, as we do not want to charge battery at this point" << endl;
   while (1) {
      if (0 /*fail conditions met*/) {
         return 19;
      }
      if (0 /*off button*/) {
         return 20;
      } else if (0 /*motor startup*/) {
         return 22;
      } else if (chargeOrNot()) {
         return 0;
      }
   }
}