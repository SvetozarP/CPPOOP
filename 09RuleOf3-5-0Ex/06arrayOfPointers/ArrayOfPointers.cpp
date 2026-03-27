#include "ArrayOfPointers.h"


void ArrayOfPointers::add(Company* c) {
	data.push_back(c);
}

ArrayOfPointers::~ArrayOfPointers() {
	for (Company* c : data) {
		delete c;
	}
}

size_t ArrayOfPointers::getSize() const { return data.size(); }

Company* ArrayOfPointers::get(size_t index) const { return data[index]; }