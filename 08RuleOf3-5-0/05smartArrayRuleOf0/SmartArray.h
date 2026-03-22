#pragma once

#include <algorithm>
#include <vector>

template <typename T>
class SmartArray {

private:

	// size_t _size;
//	T* _data; - instead of dynamic data, just use vector
	std::vector<T> _data;

	// Method clear - void the array.
	// rule of 0 - clear is not necessary anymore. Vector has this func.

	//void clear() {

	//	if (_data) {
	//		delete[] _data;
	//	}
	//	// put the class in nullptr state
	//	_data = nullptr;
	//	_size = 0;
	//}

	// reset function

	//void reset(T* otherData, size_t otherSize) {
	//	T* tmpData = new T[otherSize]{ };
	//	std::copy(otherData, otherData + otherSize, tmpData);

	//	// clear(); - not needed - rule of 0

	//	this->_size = otherSize;
	//	this->_data = tmpData;
	//} - not required, rule of 0

public:

	// add size = 0 - constructor becomes default
	// rule of 0 -> init data with size only

	SmartArray(size_t size = 0)
		//: _size(size), _data(_size ? new T[_size]{ } : nullptr) {
		: _data(size) {

	}

	// Add copy constructor

	//SmartArray(const SmartArray& other) {
	//	T* tmpData = new T[other._size]{ };
	//	std::copy(other._data, other._data + other._size, tmpData);

	//	this->_size = other._size;
	//	this->_data = tmpData;
	//}

	//implement reset in Copy constructor

	//SmartArray(const SmartArray& other) : SmartArray() {
	//	reset(other._data, other._size);
	//}

	// Rule of 0 copy constructor

	// SmartArray(const SmartArray& other) : _data(other._data) {} - standard copy constructor, not required

	// add operator =

	//SmartArray& operator = (const SmartArray& other) {
	//	if (this != &other) {
	//		// this is now reset
	//		//T* tmpData = new T[other._size]{ };
	//		//std::copy(other._data, other._data + other._size, tmpData);

	//		//clear();

	//		//this->_size = other._size;
	//		//this->_data = tmpData;

	//		reset(other._data, other._size);
	//	}

	//	return *this;
	//}

	// New operator = to implement swap

	//SmartArray& operator = (SmartArray& other) { - not required, rule of 0 - standard assignment operator.
	//	//swap(*this, other);
	//	//return *this;

	//	_data = other._data;
	//}

	//~SmartArray() {
		// clear(); - not needed, rule of 0
	//}

	T& operator[](size_t index) {

		//if (index >= _size) - rule of 0 - vector does this.
		//	//out of bound
		//	throw std::out_of_range("out of range");

		return _data[index];
	}

	void print() const {
		//for (size_t i = 0; i < _size; ++i) {
		//	std::cout << _data[i] << ' ';
		//}
		//std::cout << std::endl;

		// rule of 0:

		for (const T& curr : _data) {
			std::cout << curr << ' ';
		}
		std::cout << std::endl;
	}

	// function resize

	void resize(size_t newSize) {

		//T* tmpData;

		//if (newSize)
		//	tmpData = new T[newSize]{};

		//else
		//	tmpData = nullptr;

		//if (_data != nullptr && tmpData != nullptr)
		//	std::copy(_data, _data + std::min(newSize, _size), tmpData);

		//clear();

		//_data = tmpData;
		//_size = newSize;

		// rule of 0:

		_data.resize(newSize);
	}

	//create friend function swap

	friend void swap(SmartArray& a, SmartArray& b) {
		std::swap(a._data, b._data);
		//std::swap(a._size, b._size); - not required. The whole swap is also obsolete.
	}

	// Iterator - not required in rule of 0

	//class Iterator {

	//	SmartArray& data;
	//	size_t index;

	//public:
	//	Iterator(SmartArray& _data, size_t _index) : data(_data), index(_index) {}

	//	Iterator operator ++ () {
	//		index++;
	//		return *this;
	//	}

	//	// Optional - not necessary for Iterator
	//	Iterator operator -- () {
	//		index--;
	//		return *this;
	//	}

	//	// operator !=

	//	bool operator != (const Iterator& other) const {
	//		if (data._data != other.data._data)
	//			// We are operating on different arrays - different
	//			return true;

	//		// We are operating on the same data - compare

	//		if (index >= data._size && other.index >= other.data._size)
	//			// past the end of the sequence - we are both end operators
	//			return false;

	//		// WE are different if not the same with other.index

	//		return index != other.index;
	//	}


	//	// Operator *
	//	T& operator * () {
	//		return data._data[index];
	//	}

	//};

	// begin() and end()

	//Iterator begin() {
	//	return Iterator(*this, 0);
	//}

	//Iterator end() {
	//	return Iterator(*this, SIZE_MAX);
	//} rule of 0. It supports iterator

	typename std::vector<T>::iterator begin() {
		return _data.begin();
	}

	typename std::vector<T>::iterator end() {
		return _data.end();
	}
};