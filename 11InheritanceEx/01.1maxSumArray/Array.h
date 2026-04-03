#pragma once

#include <vector>

template<typename T>
class Array : public std::vector<T> {
public:

	Array(size_t size) {
		this->resize(size);
	}

	int getSize() const {
		return this->size();
	}

};