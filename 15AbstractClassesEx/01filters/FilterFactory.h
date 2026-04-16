#pragma once

#include "Filter.h"

class CapsFilter : public Filter {

public:

	CapsFilter() = default;
	~CapsFilter() override = default;

protected:
	bool shouldFilterOut(char symbol) const override {
		if (symbol >= 'A' && symbol <= 'Z') {
			return true;
		}
		return false;
	}

};

class SmallFilter : public Filter {

public:
	SmallFilter() = default;
	~SmallFilter() override = default;

protected:
	bool shouldFilterOut(char symbol) const override {
		if (symbol >= 'a' && symbol <= 'z') {
			return true;
		}
		return false;
	}

};

class NumberFilter : public Filter {

public:
	NumberFilter() = default;
	~NumberFilter() override = default;

protected:
	bool shouldFilterOut(char symbol) const override {
		if (symbol >= '0' && symbol <= '9') {
			return true;
		}
		return false;
	}
};


class FilterFactory {
public:
	Filter* buildFilter(std::string filterDefinition) const;
};
