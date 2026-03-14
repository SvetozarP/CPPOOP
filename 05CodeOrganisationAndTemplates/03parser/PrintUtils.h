#ifndef PRINTUTILS_H
#define PRINTUTILS_H

#include <vector>
#include <iostream>

template <typename T>

void printVector(const std::vector<T>& v) {
	for (const T& t : v) {
		std::cout << t << ' ';
	}

	std::cout << std::endl;
}

template <typename T>
void printContainer(typename T::iterator begin, typename T::iterator end) {
	for (T it = begin; it != end; ++it) {
		std::cout << *it << ' ';
	}
}

#endif // PRINTUTILS_H
