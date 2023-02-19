// loop that calls state functions
// calls battry managemente stae funcitons
// charging, full-charged, ready-to-charge, pre-cahrging, do-not-charge
//, charged, pre-charge, 

int state_0_ready_to_charge() {
   cout << "VCU: Changing state to 0: ready to charge..." << endl;
   cout << "CAN: Command BMS/AIR to be ready to accept positive current..." << endl; //in the case do_not_charge sent the opposite command earlier.
   cout << "CAN: Dashboard stuff. Indication may not be necessary." << endl;
   while (1) {
      if (0 /*fail conditions met*/) {
         return 19;
      }
      //continously execute state tasks
      cout << "VCU/CAN: Do necessary things here" << endl;
      //check for state change
      if (0 /* motor contols engaged */) {
         return 22;
      } else if (getCurrent() >= -10 && getCurrent() <= 10) {
         return 1;
      } else if (getCurrent() > 10) {
         return 2;
      }
   }
}

int state_1_not_charging() { //an extended version of precharge that includes the cases where it's not precharging, but not charging.
   cout << "VCU: Switching state to 1: not charging…" << endl;
   cout << "CAN: Send signal to dashboard to indicate NOT CHARGING." << endl;
   while (1) {
      if (0 /*fail conditions met*/) {
         return 19;
      }
      //continously execute state tasks
      cout << "VCU/CAN: Do other necessary things here" << endl;
      //check for state change
      if (getCurrent() <= -10) {
         return 0;
      } else if (getCurrent() > 10) {
         return 2;
      }
   }
} 

int state_2_charging() {
   cout << "VCU: Switching state to 2: charging..." << endl;
   cout << "CAN: Send signal to dashboard to indicate CHARGING." << endl;
   while (1) {
      if (0 /*fail conditions met*/) {
         return 19;
      }
      //continously execute state tasks
      cout << "VCU/CAN: Do necessary things here" << endl;
      //check for state change conditions
      if (getChargeState() >= 99) {
         return 3;
      } else if (getCurrent() < -10) {
         return 0;
      } else if (getCurrent() <= 10) {
         return 1;
      } e
   }
}

int state_3_charging() {
   cout << "VCU: Switching state to 3: fully charged..." << endl;
   cout << "CAN: Send signal to dashboard to indicate FULLY CHARGED." << endl;
   while (1) {
      if (0 /*fail conditions met*/) {
         return 19;
      }
      //continously execute state tasks
      cout << "VCU/CAN: Do necessary things here" << endl;
      if (getChargeState() < 99 && getCurrent() >= -10) {
         return 2;
      } else if (getCurrent() < -10) {
         return 0;
      }
   }
}
