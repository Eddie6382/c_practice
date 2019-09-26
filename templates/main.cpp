#include <iostream>
#include "stack.h"
using namespace std;

int main(){
    Stack<float> floatStack;
    const size_t floatStackSize = 5;
    float floatValue = 1.1;

    cout << "pushing element on to doublrStack\n";

    for(size_t i=0; i<floatStackSize; ++i){
        floatStack.push(floatValue);
        cout << floatValue << ' ';
        floatValue += 1.1;
    }

    cout << "poping element from floatStack\n";

    while( !floatStack.isEmpty() ){
        cout << floatStack.top() << " ";
        floatStack.pop();
    }

    cout << "stack now is empty";


    Stack<int> intStack;
    const int intStackSize = 5;
    int intValue = 1;

    cout << "pushing element on to doublrStack\n";

    for(size_t i=0; i<intStackSize; ++i){
        intStack.push(intValue);
        cout << intValue << ' ';
        intValue += 1.1;
    }

    cout << "poping element from intStack\n";

    while( !intStack.isEmpty() ){
        cout << intStack.top() << " ";
        intStack.pop();
    }

    cout << "stack now is empty";
}
