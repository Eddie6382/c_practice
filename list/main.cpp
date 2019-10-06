#include <iostream>
#include <string>
#include "List.h"
using namespace std;

void instructions(){
    cout << "Enter one of the following commands:\n"
        << " 1 to insert at beginning of the list\n"
        << " 2 to insert at end of the list\n"
        << " 3 to delete from beginning of the list\n"
        << " 4 to delete from end of the list\n"
        << " 5 to end kist processing\n"; 
}
enum commmand()
