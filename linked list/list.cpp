#include <iostream>
using namespace std;

class Node
{
public:
    int element;
    Node *next;
};

class List
{
public:
    List()
    {
        first = NULL;
        size = 0;
    }
    void pushFront(int _element)
    {
        Node *p = new Node; //指標變數 = new*資料型別
        p->element = _element;
        p->next = first;
        first = p;
        ++size;
    }
    void pushAt(int index, int _element)
    {
        if (index == 0)
            pushFront(_element);
        else
        {
            Node *before = first;
            for (int i = 1; i < index; ++i)
                before = before->next;
            push(before, _element);
        }
    }
    int getindex(int index)
    {
        if (index == 0)
            return first->element;
        else
        {
            Node *p = first;
            for (int i = 1; i <= index; ++i)
                p = p->next;
            return p->element;
        }
    }
    void eraseAt(int index)
    {
        Node *p;
        if (index == 0)
        {
            p = first;
            first = first->next;
            delete[] p;
        }
        else
        {
            Node *before = first;
            for (int i = 1; i < index; ++i)
                before = before->next;
            p = before->next;
            before->next = p->next;
            delete[] p;
        }
    }
    void destructAll()
    {
        Node *p = first;
        Node *store;
        while (p != NULL)
        {
            store = p;
            p = p->next;
            delete[] store;
        }
    }
    void printOut() const
    {
        Node *p = first;
        while (p != NULL)
        {
            cout << p->element << " -> ";
            p = p->next;
        }
        cout << "NULL" << endl;
    }
    bool isEmpty() const
    {
        return (size == 0);
    }

protected:
    void push(Node *before, int _element)
    {
        Node *p = new Node;
        p->element = _element;
        p->next = before->next;
        before->next = p;
        ++size;
    }
    Node *first;
    int size;
};

int main(void)
{
    List myList;
    myList.pushFront(1);
    myList.pushFront(2);
    myList.pushFront(3);
    myList.pushFront(4);
    myList.pushFront(5);

    myList.pushAt(2, 999);
    myList.printOut();
    myList.eraseAt(1);
    myList.printOut();
    cout << myList.getindex(2) << endl;
    return 0;
}