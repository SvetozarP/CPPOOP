#include "IndexedSet.h"
#include <algorithm>
#include <vector>

void IndexedSet::clearIndex() {
    delete[] valuesArray;
    valuesArray = nullptr;
}

void IndexedSet::buildIndex() {
    clearIndex();

    if (valuesSet.empty()) {
        valuesArray = nullptr;
        return;
    }

    std::vector<Value> temp_values;
    temp_values.reserve(valuesSet.size());

    for (const Value& v : valuesSet) {
        temp_values.push_back(v);
    }

    valuesArray = new Value[temp_values.size()];

    std::copy(temp_values.begin(), temp_values.end(), valuesArray);
}

IndexedSet::IndexedSet() : valuesArray(nullptr) {}

IndexedSet::IndexedSet(const IndexedSet& other) : valuesSet(other.valuesSet), valuesArray(nullptr) {
    if (other.valuesArray != nullptr && !other.valuesSet.empty()) {
        buildIndex();
    }
}

void IndexedSet::add(const Value& v) {
    valuesSet.insert(v);
    clearIndex();
}

size_t IndexedSet::size() const {
    return valuesSet.size();
}

const Value& IndexedSet::operator[](size_t index) {
    if (valuesArray == nullptr && !valuesSet.empty()) {
        buildIndex();
    }
    return valuesArray[index];
}

IndexedSet& IndexedSet::operator=(const IndexedSet& other) {
    if (this == &other) {
        return *this;
    }
    valuesSet = other.valuesSet;
    clearIndex();

    if (other.valuesArray != nullptr && !other.valuesSet.empty()) {
        buildIndex();
    }
    return *this;
}

IndexedSet::~IndexedSet() {
    clearIndex();
}