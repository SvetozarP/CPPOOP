#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Student {
	string name, surname;
	double average;

public:

	Student() : average(0) {}

	void read(istream& in) {
		getline(in, name);
		getline(in, surname);
		in >> average;
		in.ignore();
	}

	const string& getName() const { return name; }
	void setName(const string& name) { this->name = name; }

	const string& getSurname() const { return surname; }
	void setSurname(const string& surname) { this->surname = surname; }

	double getAverage() const { return average; }
	void setAverage(double average) { this->average = average; }

	void print(ostream & out) const {
		out << name << " " << surname << " " << average << endl;
	}

};

int main()
{
	int numberOfStudents;
	cin >> numberOfStudents;
	cin.ignore();

	if (numberOfStudents <= 0) {
		cout << "Invalid input" << endl;
		return 1;
	}

	vector<Student> students;

	while(numberOfStudents--) {
		Student s;
		s.read(cin);
		students.push_back(s);
	}

	double totalAverage = 0;
	for (const Student& s : students) {
		s.print(cout);
		totalAverage += s.getAverage();
	}
	totalAverage /= students.size();
	cout << totalAverage << endl;

	return 0;

}
