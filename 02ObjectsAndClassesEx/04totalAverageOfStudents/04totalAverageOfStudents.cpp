#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <numeric>

using namespace std; 
class Student {
private:
    string name;
    string surname;
    double totalAverage;

public:
    Student(const string& studentName, const string& studentSurname, double avg)
        : name(studentName), surname(studentSurname), totalAverage(avg) {
    }

    void print() const {
        cout << name << " " << surname << " " << totalAverage << endl;
    }

    double getTotalAverage() const {
        return totalAverage;
    }
};

double calculateTotalClassAverage(const vector<Student>& students) {
    if (students.empty()) {
        return 0.0;
    }

    double sumOfAverages = 0.0;
    for (const Student& s : students) {
        sumOfAverages += s.getTotalAverage();
    }
    return sumOfAverages / students.size();
}


int main() {
    
    int numberOfStudents;
    cin >> numberOfStudents;

    if (numberOfStudents <= 0) {
        cout << "Invalid input" << endl;
        return 0;
    }

    vector<Student> students;
    students.reserve(numberOfStudents);

    for (int i = 0; i < numberOfStudents; ++i) {
        string name, surname;
        double average;

        cin >> name >> surname >> average;
        students.emplace_back(name, surname, average);
    }

    for (const Student& s : students) {
        s.print();
    }

    double classAverage = calculateTotalClassAverage(students);
    cout << classAverage << endl;

    return 0;
}