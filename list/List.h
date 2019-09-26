#ifndef LIST_H
#define LIsT_H

#include <iostream>
#include "listNode.h"
using namespace std;

template <typename NODETYPE>
class List{
public:
    List():firstptr(nullptr), lastptr(nullptr){};
    ~List(){
        if( !isEmpty() ){
            cout << "Destorying nodes......" << endl;

            ListNode<NODETYPE> *currrentptr = firstptr;
            ListNode<NODETYPE> &tempptr = nullptr;

            while( currrentptr != nullptr ){
                tempptr = currrentptr;
                cout << tempptr->getData() << "\n";
                currrentptr = currrentptr->nextptr;
                delete tempptr;
            }
        }
    }
    void insertFront( const NODETYPE* & );
    void insertBack( const NODETYPE* & );
    bool removeFront( NODETYPE* & );
    bool removeBack( NODETYPE* & );
    bool isEmpty() const;
    void print() const;


private:
    // pounters to the first or the end of the list
    ListNode<NODETYPE> *firstptr;
    ListNode<NODETYPE> *lastptr;

    // to allocate new node
    ListNode<NODETYPE> *getNewNode( const NODETYPE &value ){
        return new ListNode<NODETYPE>(value);
    }
};

#endif