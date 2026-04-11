#pragma once

#include <sstream>
#include <vector>

template <typename T>
class TypedStream {

protected:

	std::istringstream stream;

public:

	TypedStream (const std::string& inputString) : stream(inputString) {}
	
	virtual TypedStream<T> & operator >>(T & item) {
		return *this;
	};
	
	std::vector<T> readToEnd() {
		std::vector<T> result;

		T item;
		
		while (true) {

			*this >> item;

			if ((bool)stream == false) {
				break;
			}

			result.push_back(item);
		}
		return result;
	}

};