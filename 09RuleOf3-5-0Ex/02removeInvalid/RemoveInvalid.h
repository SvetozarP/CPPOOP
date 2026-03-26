#pragma once

#include <list>

#include "Company.h"

class InvalidCompaniesRemover {
	std::list<Company*>& companies;

public:

	InvalidCompaniesRemover(std::list<Company*>& companies_) : companies(companies_) {}

	void remove() {

		for (std::list<Company*>::iterator it = companies.begin(); it != companies.end();) {

			Company* curr = *it;
			if (curr->getId() < 0) {
				it = companies.erase(it);
			}
			else
				it++;

		}
	}
};


void removeInvalid(std::list<Company*>& companies) {

	InvalidCompaniesRemover ICR(companies);
	ICR.remove();

}