#ifndef QUEUE_H
#define QUEUE_H

#include "Array.h"

template<typename T>
class Queue {
private:
    Array<T> data;

public:
    void clear();
    void push(const T& value);
    void pop();
    T top() const;
    bool empty() const;
};

#include "Queue.cpp"
#endif