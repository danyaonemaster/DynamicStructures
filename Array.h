#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
private:
    T* arr;
    size_t size;
    size_t capacity;

    void resize(size_t newCapacity);

public:
    Array(size_t initialCapacity = 10);
    Array(const Array& other);
    Array(Array&& other) noexcept;
    ~Array();

    Array& operator=(const Array& other);
    Array& operator=(Array&& other) noexcept;

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    size_t getSize() const;
    bool empty() const;

    void push_back(const T& value);
    void pop_back();
    T& back();
    const T& back() const;

    void clear();
    void display() const;
};

#include "Array.cpp"

#endif