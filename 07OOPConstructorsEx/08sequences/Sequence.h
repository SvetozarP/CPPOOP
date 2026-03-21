#pragma once

#include <vector>

template<typename T, typename Generator>
class Sequence {

    typedef std::vector<T> Data;

    Data data;
    Generator gen;

public:

    // Forward declaration of EndIterator for use in Iterator
    class EndIterator;

    class Iterator {
        // Needs to hold a pointer or reference to the Sequence
        // to check its current size for the "end" condition.
        Sequence<T, Generator>* sequence_ptr;
        size_t index;

    public:
        // Constructor for regular iterators
        Iterator(Sequence<T, Generator>* seq_ptr, size_t idx)
            : sequence_ptr(seq_ptr), index(idx) {
        }

        // Dereference operator
        T& operator*() {
            return sequence_ptr->data[index];
        }

        // Pre-increment operator
        Iterator& operator++() {
            index++;
            return *this;
        }

        // Post-increment operator (optional but good practice)
        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        // Comparison with another Iterator (same type)
        bool operator==(const Iterator& other) const {
            return sequence_ptr == other.sequence_ptr && index == other.index;
        }

        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }

        // Comparison with EndIterator (different type)
        // This is where the magic happens for dynamic end
        bool operator==(const EndIterator& other) const {
            // An Iterator is "equal" to the EndIterator if its index
            // is at or past the current size of the sequence.
            return index >= sequence_ptr->data.size();
        }

        bool operator!=(const EndIterator& other) const {
            return !(*this == other);
        }
    };

    // Special EndIterator type that doesn't hold an index,
    // but rather signals the end condition.
    // It's a "sentinel" that works by comparing against the current size.
    class EndIterator {
        // No members needed, it's just a type to compare against
    public:
        // Comparison with Iterator (different type)
        bool operator==(const Iterator& other) const {
            return other.operator==(*this); // Delegate to Iterator's comparison
        }

        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }
    };

    // begin() creates a regular iterator pointing to the start
    Iterator begin() { return Iterator(this, 0); }

    // end() creates the special EndIterator
    // It doesn't need to know the size, the Iterator does the check
    EndIterator end() { return EndIterator(); }

    void generateNext(size_t numToGenerate) {
        while (numToGenerate--) {
            data.push_back(gen());
        }
    }
};