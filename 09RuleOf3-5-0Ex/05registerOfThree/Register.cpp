#include <algorithm>

#include "Company.h"
#include "Register.h"

Register::Register(size_t numCompanies) : numAdded(0) {
	
	companiesArray = new Company[numCompanies];
}

void Register::add(const Company& c) {

	companiesArray[numAdded] = c;
	numAdded++;

}

Company Register::get(int companyId) const {
	for (size_t idx = 0; idx < numAdded; idx++)
		if (companiesArray[idx].getId() == companyId)
			return companiesArray[idx];

	return Company();
}

Register::~Register() {
	delete[] companiesArray;
}

Register& Register::operator=(const Register& other) {

	if (this != &other) {

		Company* newArr = new Company[other.numAdded];
		std::copy(other.companiesArray, other.companiesArray + other.numAdded, newArr);

		if (this->companiesArray != nullptr) {
			delete[] this->companiesArray;
		}

		this->companiesArray = newArr;
		this->numAdded = other.numAdded;
	}

	return *this;
}

Register::Register(const Register& other) : Register() {
	*this = other;
}
