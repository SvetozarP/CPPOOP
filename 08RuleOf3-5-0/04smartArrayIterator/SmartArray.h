#pragma once

#include <algorithm>

// Iterator:
// 1. begin() in the container class
// 2. end() int the container class - should return "universal"
// 3. Class Iterator as part of the SmartArray
// 4. Iterator class must support operator ++
// 5. Iterator class must support operator != with another Iterator
// 6. Iterator class must provide operator * - dereference operator



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

	SmartArray& operator = (SmartArray& other) {
		swap(*this, other);
		return *this;
	}

	~SmartArray() {
		clear();
	}

	T& operator[](size_t index) {

		if (index >= _size)
			//out of bound
			throw std::out_of_range("out of range");

		return _data[index];
	}

	void print() const {
		for (size_t i = 0; i < _size; ++i) {
			std::cout << _data[i] << ' ';
		}
		std::cout << std::endl;
	}

	// function resize

	void resize(size_t newSize) {

		T* tmpData;

		if (newSize)
			tmpData = new T[newSize]{};

		else
			tmpData = nullptr;

		if (_data != nullptr && tmpData != nullptr)
			std::copy(_data, _data + std::min(newSize, _size), tmpData);

		clear();

		_data = tmpData;
		_size = newSize;
	}

	//create friend function swap

	friend void swap(SmartArray& a, SmartArray& b) {
		std::swap(a._data, b._data);
		std::swap(a._size, b._size);
	}

	// Iterator

	class Iterator {

		SmartArray& data;
		size_t index;

	public:
		Iterator(SmartArray& _data, size_t _index) : data(_data), index(_index) {}

		Iterator operator ++ () {
			index++;
			return *this;
		}

		// Optional - not necessary for Iterator
		Iterator operator -- () {
			index--;
			return *this;
		}

		// operator !=

		bool operator != (const Iterator& other) const {
			if (data._data != other.data._data)
				// We are operating on different arrays - different
				return true;

			// We are operating on the same data - compare

			if (index >= data._size && other.index >= other.data._size)
				// past the end of the sequence - we are both end operators
				return false;

			// WE are different if not the same with other.index

			return index != other.index;
		}


		// Operator *
		T& operator * () {
			return data._data[index];
		}

	};

	// begin() and end()

	Iterator begin() {
		return Iterator(*this, 0);
	}

	Iterator end() {
		return Iterator(*this, SIZE_MAX);
	}

};