#ifndef SPLIT_H
#define SPLIT_H


#include <vector>
#include <sstream>

template <typename T>

std::vector<T> split(const std::string& str, char separator) {
	std::vector<T> result;

	std::istringstream ss(str);
	std::string token;

	while (std::getline(ss, token, separator)) {
		std::istringstream tokenStream(token);
		T value;
		tokenStream >> value;
		result.push_back(value);
	}
	return result;
}


#endif // SPLIT_H
