#pragma once

#include "Company.h"
#include <vector>
#include <memory>

class ArrayOfPointers {

	std::vector<std::shared_ptr<Company>> data;

public:

	void add(Company* c);

	size_t getSize() const;

	Company* get(size_t index) const;

};