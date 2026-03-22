#pragma once

#include <algorithm>


template <typename T>
class SmartArray {

private:

	size_t _size;
	T* _data;

	// Method clear - void the array.

	void clear() {

		if (_data) {
			delete[] _data;
		}
	// put the class in nullptr state
		_data = nullptr;
		_size = 0;
	}

	// reset function

	void reset(T* otherData, size_t otherSize) {
		T* tmpData = new T[otherSize]{ };
		std::copy(otherData, otherData + otherSize, tmpData);

		clear();

		this->_size = otherSize;
		this->_data = tmpData;
	}

public:

	// add size = 0 - constructor becomes default
	SmartArray(size_t size = 0)
		: _size(size), _data(_size ? new T[_size]{ } : nullptr) {

	}

	// Add copy constructor

	//SmartArray(const SmartArray& other) {
	//	T* tmpData = new T[other._size]{ };
	//	std::copy(other._data, other._data + other._size, tmpData);

	//	this->_size = other._size;
	//	this->_data = tmpData;
	//}

	//implement reset in Copy constructor

	SmartArray(const SmartArray& other) : SmartArray() {
		reset(other._data, other._size);
	}

	// add operator =

	SmartArray& operator = (const SmartArray& other) {
		if (this != &other) {
			// this is now reset
			//T* tmpData = new T[other._size]{ };
			//std::copy(other._data, other._data + other._size, tmpData);

			//clear();

			//this->_size = other._size;
			//this->_data = tmpData;

			reset(other._data, other._size);
		}

		return *this;
	}

	~SmartArray() {
		clear();
	}

	T& operator[](size_t index) {
		return _data[index];
	}

	void print() const {
		for (size_t i = 0; i < _size; ++i) {
			std::cout << _data[i] << ' ';
		}
		std::cout << std::endl;
	}

};