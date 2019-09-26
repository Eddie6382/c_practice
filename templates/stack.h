// use deque to write stack
#ifndef STACK_H
#define STACK_H
#include <deque>

template < typename T >   // view T as a new type
class Stack{
public:
    T& top(){
        return stack.front();
    }
    void push (const T &pushValue ){
        stack.push_front(pushValue);
    }
    void pop(){
        stack.pop_front();
    }
    bool isEmpty() const{
        return stack.empty();
    }
    size_t size() const{
        return stack.size();
    }
private:
    std::deque < T > stack;    //internal represention of stack
};

#endif