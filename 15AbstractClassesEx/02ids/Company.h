#pragma once

#include <string>
#include <sstream>
#include <vector>
#include <utility>

class HasId {
public:
	virtual int getId() const = 0;

	virtual ~HasId() {}
};

class HasInfo {
public:
	virtual std::string getInfo() const = 0;

	virtual ~HasInfo() {}
};

class Company : public HasId, public HasInfo {
private:
	int id;
	std::string name;
	std::vector<std::pair<char, char>> employees;
public:

	Company();
	Company(int id, std::string name, std::vector<std::pair<char, char> > employee);

	int getId() const;

	std::string getName() const;

	std::vector<std::pair<char, char> > getEmployees() const;

	friend std::ostream& operator<<(std::ostream& stream, const Company& c);
	friend std::istream& operator>>(std::istream& stream, Company& c);

	std::string getInfo() const;

};