#ifndef STACK_H
#define STACK_H

#include "Array.h"

template<typename T>
class Stack {
private:
    Array<T> data;

public:
    void clear();
    void push(const T& value);
    void pop();
    T top() const;
    bool empty() const;
};

#include "Stack.cpp"
#endif