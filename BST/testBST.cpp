#include <iostream>
#include "bst.h"
using namespace std;

int main()
{
    BST bst;

    bst.insert(3);
    bst.insert(6);
    bst.insert(9);
    bst.insert(4);
    bst.insert(2);
    bst.insert(0);

    bst.printInOrder();

    //cout << bst.search(2) << endl;
    //cout << bst.search(5) << endl;
    //cout << bst.search(-1) << endl;
    return 0;
}