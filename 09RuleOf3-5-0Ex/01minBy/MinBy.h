#pragma once

#include <string>
#include <vector>

class MinByImpl {

public:
	std::string result;

	MinByImpl(const std::vector<std::string>& values, bool (*compareFunction)(const std::string& a, const std::string& b)) {
		result = values[0];
		for (auto it = (values.begin() + 1); it != values.end(); it++) {
			if (compareFunction(*it, result))
				result = *it;
		}
	}

};


std::string minBy(const std::vector<std::string>& values, bool (*compareFunction)(const std::string& a, const std::string& b)) {
	return MinByImpl(values, compareFunction).result;
}