#pragma once

#include "Company.h"
#include <vector>

class ArrayOfPointers {

	std::vector<Company*> data;

public:

	ArrayOfPointers() {};

	~ArrayOfPointers();

	void add(Company* c);

	size_t getSize() const;

	Company* get(size_t index) const;

	ArrayOfPointers(const ArrayOfPointers&) = delete;
	ArrayOfPointers& operator=(const ArrayOfPointers&) = delete;

};