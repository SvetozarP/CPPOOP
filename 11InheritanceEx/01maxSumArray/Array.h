#pragma once

#include <cstddef>

template <typename T>
class Array {
private:
    T* data;
    size_t size;

public:
    // Default constructor
    Array() : data(nullptr), size(0) {}

    // Constructor with size
    explicit Array(size_t s) : size(s) {
        data = new T[size];
    }

    // Copy constructor
    Array(const Array& other) : size(other.size) {
        data = new T[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // Move constructor
    Array(Array&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
    }

    // Destructor
    ~Array() {
        delete[] data;
    }

    // Copy assignment operator
    Array& operator=(const Array& other) {
        if (this == &other) {
            return *this;
        }
        delete[] data;
        size = other.size;
        data = new T[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
        return *this;
    }

    // Move assignment operator
    Array& operator=(Array&& other) noexcept {
        if (this == &other) {
            return *this;
        }
        delete[] data;
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
        return *this;
    }

    // Subscript operator (lvalue)
    T& operator[](size_t index) {
        return data[index];
    }

    // Subscript operator (rvalue)
    const T& operator[](size_t index) const {
        return data[index];
    }

    // Get size
    size_t getSize() const {
        return size;
    }

    // Iterators for range-based for loop
    T* begin() {
        return data;
    }

    const T* begin() const {
        return data;
    }

    T* end() {
        return data + size;
    }

    const T* end() const {
        return data + size;
    }
};