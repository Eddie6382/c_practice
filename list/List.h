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
    void insertFront( const NODETYPE & );
    void insertBack( const NODETYPE & );
    bool removeFront( NODETYPE & );
    bool removeBack( NODETYPE & );
    bool isEmpty() const;
    void print() const;


private:
    // pounters to the first or the end of the list
    ListNode<NODETYPE> *firstptr;
    ListNode<NODETYPE> *lastptr;

    // to allocate new node, view NODETYPE as a type
    ListNode<NODETYPE> *getNewNode( const NODETYPE &value ){
        return new ListNode<NODETYPE>(value);
    }
};

template <typename NODETYPE>
void List<NODETYPE>::insertFront( const NODETYPE &value ){
    List <NODETYPE> *newPtr = getNewNode( value );

    if(isEmpty()){
        firstptr = lastptr = newPtr;
    }
    else // list id not empty
    {
        newPtr->nextptr = firstptr;
        firstptr = newPtr;
    }
}

template <typename NODETYPE>
void List<NODETYPE>::insertBack( const NODETYPE &value ){
    List<NODETYPE> *newPtr = getNewNode( value );

    if( isEmpty() ){
        firstptr = lastptr = newPtr;
    }
    else{
        lastptr->nextptr = newPtr;
        lastptr = newPtr;
    }
}

template <typename NODETYPE>
bool List<NODETYPE>::removeFront( NODETYPE &value ){
    if( isEmpty() )
        return false;
    else{
        ListNode<NODETYPE> *tempptr = firstptr;
        if( firstptr == lastptr)
            firstptr = lastptr = nullptr;
        else
            firstptr = firstptr->nextptr;

        value = tempptr->data;     //return data being removed
        delete tempptr;
        return true;
    }
}

// it is hard to find last node
template <typename NODETYPE>
bool List<NODETYPE>::removeBack( NODETYPE &value ){
    if( isEmpty() )
        return false;
    else{
        ListNode<NODETYPE> *tempptr = lastptr;

        if( firstptr == lastptr )
            firstptr = lastptr = nullptr;
        else{
            ListNode<NODETYPE> *currentPtr = firstptr;

            while( currentPtr->nextptr != lastptr ){
                currentPtr = currentPtr->nextptr;
            }
            lastptr = currentPtr;
            currentPtr->nextptr = nullptr;
        }

        value = tempptr->data;
        delete tempptr;
        return true;
    }
}

template <typename NODETYPE>
bool List<NODETYPE>::isEmpty() const{
    return firstptr == nullptr;
}

template <typename NODETYPE>
void List<NODETYPE>::print() const{
    if( isEmpty() ){
        cout << "The list is empty\n\n";
        return;
    }

    ListNode<NODETYPE> *currentPtr = firstptr;

    while( currentPtr != nullptr ){
        cout << currentPtr->data << ' ';
        currentPtr = currentPtr->nextptr;
    }
    cout << "\n\n";
}

#endif