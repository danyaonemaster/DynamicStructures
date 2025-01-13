#ifndef QUEUE_CPP
#define QUEUE_CPP

#include "Queue.h"

template<typename T>
void Queue<T>::clear() {
    data.clear();
}

template<typename T>
void Queue<T>::push(const T& value) {
    data.push_back(value);
}

template<typename T>
void Queue<T>::pop() {
    if (!data.empty()) {
        data.erase(0);
    }
}

template<typename T>
T Queue<T>::top() const {
    if (!data.empty()) {
        return data[0];
    }
    throw std::runtime_error("Queue is empty");
}

template<typename T>
bool Queue<T>::empty() const {
    return data.empty();
}

#endif