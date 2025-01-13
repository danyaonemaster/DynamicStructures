#ifndef ARRAY_CPP
#define ARRAY_CPP

#include "Array.h"

template <typename T>
Array<T>::Array(size_t initialCapacity)
    : size(0), capacity(initialCapacity) {
    arr = new T[capacity];
}

template <typename T>
Array<T>::Array(const Array& other)
    : size(other.size), capacity(other.capacity) {
    arr = new T[capacity];
    for (size_t i = 0; i < size; ++i) {
        arr[i] = other.arr[i];
    }
}

template <typename T>
Array<T>::Array(Array&& other) noexcept
    : arr(other.arr), size(other.size), capacity(other.capacity) {
    other.arr = nullptr;
    other.size = 0;
    other.capacity = 0;
}

template <typename T>
Array<T>::~Array() {
    delete[] arr;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] arr;
        size = other.size;
        capacity = other.capacity;
        arr = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>& Array<T>::operator=(Array&& other) noexcept {
    if (this != &other) {
        delete[] arr;
        arr = other.arr;
        size = other.size;
        capacity = other.capacity;

        other.arr = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](size_t index) {
    return arr[index];
}

template <typename T>
const T& Array<T>::operator[](size_t index) const {
    return arr[index];
}

template <typename T>
size_t Array<T>::getSize() const {
    return size;
}

template <typename T>
bool Array<T>::empty() const {
    return size == 0;
}

template <typename T>
void Array<T>::push_back(const T& value) {
    arr[size++] = value;
}

template <typename T>
void Array<T>::pop_back() {
    --size;
}

template <typename T>
T& Array<T>::back() {
    return arr[size - 1];
}

template <typename T>
const T& Array<T>::back() const {
    return arr[size - 1];
}

template <typename T>
void Array<T>::clear() {
    size = 0;
}

template <typename T>
void Array<T>::resize(size_t newCapacity) {
    T* newArr = new T[newCapacity];
    for (size_t i = 0; i < size; ++i) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    capacity = newCapacity;
}

template <typename T>
void Array<T>::display() const {
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

#endif
