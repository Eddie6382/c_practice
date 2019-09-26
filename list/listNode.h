#ifndef LISTNODE_H
#define LISTNODE_H

template< typename NODETYPE > class List;

template< typename NODETYPE > class ListNode
{
    friend class List<NODETYPE>;   //make list a friend
public:
    // explicit: can not change the type implicitly
    explicit ListNode( const NODETYPE &info ): data( info ), nextPtr(nullptr){};
    NODETYPE getData() const{
        return data;
    }
private:
    NODETYPE data;
    ListNode<NODETYPE> *nextptr;
};

#endif