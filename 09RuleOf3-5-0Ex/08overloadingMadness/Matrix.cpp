#include "Matrix.h"

Matrix& Matrix::operator=(const std::vector<std::vector<int>>& data) {
	_data = data;
	return *this;
}


Matrix& Matrix::operator+=(const Matrix& other) {
	size_t size = other._data.size();

	for (size_t row = 0; row < size; row++) {
		for (size_t col = 0; col < size; col++) {
			this->_data[row][col] += other._data[row][col];
		}
	}

	return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {

	size_t size = other._data.size();

	for (size_t row = 0; row < size; row++) {
		for (size_t col = 0; col < size; col++) {
			this->_data[row][col] -= other._data[row][col];
		}
	}

	return *this;
}

Matrix& Matrix::operator*=(const Matrix& other) {

	size_t size = other._data.size();

	for (size_t row = 0; row < size; row++) {
		for (size_t col = 0; col < size; col++) {
			this->_data[row][col] *= other._data[row][col];
		}
	}

	return *this;
}

Matrix& Matrix::operator/=(const Matrix& other) {

	size_t size = other._data.size();

	for (size_t row = 0; row < size; row++) {
		for (size_t col = 0; col < size; col++) {
			if (other._data[row][col] == 0) {
				this->_data[row][col] = 0;
			}
			else {
				this->_data[row][col] /= other._data[row][col];
			}
		}
	}

	return *this;
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {

	size_t size = matrix._data.size();

	for (size_t row = 0; row < size; row++) {
		for (size_t col = 0; col < size; col++) {
			os << matrix._data[row][col] << ' ';
		}
		os << std::endl;
	}
	return os;
}