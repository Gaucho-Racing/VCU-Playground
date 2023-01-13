#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

//State change detection while loop to be implemented at end of each function
int main_test() {
   char key;
   //cout << "TYPE SH!T!!!: ";
   while (1) {
      if (_kbhit()) {
         key = (char)_getch();
         //some key output conditionals
         cout << key; //sample debugging output for character output.
      }
   }
}

/*
All state functions are templated as follows
int state_function() { //I include both the state code and name
   //"Change the state"
   //Take sensor readings, if necessary.
   //Check sensor readings, if necessary.
   //Send to other states if necessary, based on sensor reading
   //Wait for further input, send to other states when expected input is given
}
*/

//prevent re-turn on via software reset? (something in hardware???)
int state_minus_1_fail() {
   cout << "Something went wrong" << endl << "Changing state to fail…" << endl;
   char key;
   while (1) {
      if (_kbhit()) {
         key = (char)_getch();
         if (key == 'd') cout << "Current state: -1 - MACHINE FAILURE" << endl;
         else if (key == 'x') return 7;
      }
   }
}

int state_0_off() { //off state
   cout << "Changing state to off…" << endl << "Turning off light…" << endl;
   //and we turn on the light…
   int s;
   cout << "Enter test value for light sensor reading: ";
   cin >> s; //get some sensor output
   if (s == 0) cout << "Light successfully turned off!" << endl; //correct sensor reading
   //cases of failure
   else if (s < 0) {
      cout << "Oops, something went wrong with the lightbulb sensor!" << endl;
      return -1;
   }
   else if (s > 100) {
      cout << "MY EYES! THEY BURN!" << endl;
      return -1;
   }
   else if (s > 0) {
      cout << "Oops, the light's still on!" << endl;
      return -1;
   }
   //wait for more input
   char key;
   while (1) {
      if (_kbhit()) {
         key = (char)_getch();
         if (key == 'd') cout << "Current state: 0 - OFF" << endl;
         else if (key == 'x') return 7;
         else if (key == 'f') return 0;
         else if (key == ' ') return 2;
      }
   }
}

int state_1_on() { //partially on state
   cout << "Changing state to dim…" << endl << "Dimming light…" << endl;
   //and we turn on the light…
   int s;
   cout << "Enter test value for light sensor reading: ";
   cin >> s; //get some sensor output
   if (s > 0 && s <= 50) cout << "Light successfully dimmed!" << endl; //correct sensor reading
   //cases of failure
   else if (s < 0) {
      cout << "Oops, something went wrong with the lightbulb sensor!" << endl;
      return -1;
   }
   else if (s == 0) {
      cout << "Oops, the light's off!" << endl;
      return -1;
   }
   else if (s > 50) {
      cout << "Oops, the light's still bright." << endl;
      return -1;
   }
   else if (s > 100) {
      cout << "MY EYES! THEY BURN!" << endl;
      return -1;
   }
   //wait for more input
   char key;
   while (1) {
      if (_kbhit()) {
         key = (char)_getch();
         if (key == 'd') cout << "Current state: 1 - DIM" << endl;
         else if (key == 'x') return 7;
         else if (key == 'f') return 0;
         else if (key == ' ') return 0;
      }
   }
}

int state_2_on() { //on state
   cout << "Changing state to bright…" << endl << "Turning on light at brightest…" << endl;
   //and we turn on the light…
   int s;
   cout << "Enter test value for light sensor reading: ";
   cin >> s; //get some sensor output
   if (s > 50 && s <= 100) cout << "Light successfully turned on bright!" << endl; //correct sensor reading
   //cases of failure
   else if (s < 0) {
      cout << "Oops, something went wrong with the lightbulb sensor!" << endl;
      return -1;
   }
   else if (s == 0) {
      cout << "Oops, the light's still off!" << endl;
      return -1;
   }
   else if (s <= 50) {
      cout << "Maybe time to change the lightbulb or something??" << endl;
      return -1;
   }
   else if (s > 100) {
      cout << "MY EYES! THEY BURN!" << endl;
      return -1;
   }
   //wait for more input
   char key;
   while (1) {
      if (_kbhit()) {
         key = (char)_getch();
         if (key == 'd') cout << "Current state: 2 - BRIGHT" << endl;
         else if (key == 'x') return 7;
         else if (key == 'f') return 0;
         else if (key == ' ') return 1;
      }
   }
}

int main(int argc, char const *argv[]) {
   int state = 0;
   if (argc >= 2) {
      state = stoi(argv[1]);
   }
   /*
   an interative solution to prevent stack overflow (it's quite obvious and easy)
   as we will be swtching states many many Many MANY times during the actual thing
   this works by having each state function return the "code" for the state to go
   to upon an input to switch states is recieved.
   The main function then directs execution to the corresponding state, with 7 being
   "turn off the machine" (software cannot keep track of the state while the machine is off)
   */
   while (state != 7) {
      switch (state) {
         case -1:
            state = state_minus_1_fail();
            break;
         case 0:
            state = state_0_off();
            break;
         case 1:
            state = state_1_on();
            break;
         case 2:
            state = state_2_on();
            break;
         case 7:
            break;
      }
   }
   return 0;
}

/*
int main() {
   HANDLE hIn;
   HANDLE hOut;
   COORD KeyWhere;
   COORD MouseWhere;
   COORD EndWhere;
   bool Continue = TRUE;
   int KeyEvents = 0;
   int MouseEvents = 0;
   INPUT_RECORD InRec;
   DWORD NumRead;

   hIn = GetStdHandle(STD_INPUT_HANDLE);
   hOut = GetStdHandle(STD_OUTPUT_HANDLE);

   cout << "Key Events   : " << endl;
   cout << "Mouse Events : " << flush;

   KeyWhere.X = 15;
   KeyWhere.Y = 0;
   MouseWhere.X = 15;
   MouseWhere.Y = 1;
   EndWhere.X = 0;
   EndWhere.Y = 3;

   while (Continue) {
      ReadConsoleInput(hIn, &InRec, 1, &NumRead);
      switch (InRec.EventType) {
         case KEY_EVENT:
            ++KeyEvents;
            SetConsoleCursorPosition(hOut, KeyWhere);
            cout << KeyEvents << flush;
            if (InRec.Event.KeyEvent.uChar.AsciiChar == 'x') {
               SetConsoleCursorPosition(hOut, EndWhere);
               cout << "Exiting..." << endl;
               Continue = FALSE;
            }
            break;
         case MOUSE_EVENT:
            ++MouseEvents;
            SetConsoleCursorPosition(hOut, MouseWhere);
            cout << MouseEvents << flush;
            break;
      }
   }
   return 0;
}
*/
