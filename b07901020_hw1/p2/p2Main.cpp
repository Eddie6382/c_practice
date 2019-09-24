/****************************************************************************
  FileName     [ p2Main.cpp ]
  PackageName  [ p2 ]
  Synopsis     [ Define main() function ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2016-present DVLab, GIEE, NTU, Taiwan ]
****************************************************************************/
#include <iostream>
#include <string>
#include <iomanip>
#include "p2Json.h"

using namespace std;
void cut_command(const string &, vector<string> &);

int main()
{
   Json json;

   // Read in the csv file. Do NOT change this part of code.
   string jsonFile;
   cout << "Please enter the file name: ";
   cin >> jsonFile;
   if (json.read(jsonFile)){
      //json.print_allData();
      cout << "\nFile \"" << jsonFile << "\" was read in successfully." << endl;
   }
   else {
      cerr << "Failed to read in file \"" << jsonFile << "\"!" << endl;
      exit(-1); // jsonFile does not exist.
   }

   // TODO read and execute commands
   cout << "Enter command: ";
   while (true) {
      string Command;
      cin >> Command;
      //getline(cin, Command);
      //string cmd = cut_command(Command);
      
      if (Command == "SUM"){
         if ( !json.elem_num() )
            cerr << "Error: No element found!!" << endl;
         else
            cout << "The summation of the values is: " << json.SUM() << "." << endl;
      }
      else if (Command == "PRINT"){
         json.PRINT();
      }
      else if (Command == "AVE"){
         if ( !json.elem_num() )
            cerr << "Error: No element found!!" << endl;
         else
            cout << "The average of the value is: " << fixed << setprecision(1) << json.AVE() << "." << endl;
      }
      else if (Command == "MAX"){
         if ( !json.elem_num() )
            cerr << "Error: No element found!!" << endl;
         else
            cout << "The maximum element is: { " <<  json.MAX() << " }." << endl;
      }
      else if (Command == "MIN"){
         if ( !json.elem_num() )
            cerr << "Error: No element found!!" << endl;
         else
            cout << "The minimum element is: { " <<  json.MIN() << " }." << endl;
      }
      else if (Command == "ADD"){
         string key;
         int value;
         cin >> key >> value;
         json.ADD(key, value);
      }
      else if (Command == "EXIT"){
         exit(EXIT_SUCCESS);
      }
      else{
         cerr << "Invalid command. " << endl;
      }
      cout << "Enter command: ";
   }
}

void cut_command(const string &command, vector<string> &cmd){

}