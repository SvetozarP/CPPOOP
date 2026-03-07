#include <iostream>
#include <numeric>
#include <set>
#include <list>
#include <algorithm>

#include "Fraction.h"

using namespace std;

int main()
{
	set<Fraction> fractions{ Fraction{1, 3}, Fraction{2, 10}, Fraction {2,6} };

	Fraction f13{ 1, 3 }, f24{ 2, 4 }, f25{ 2, 5 }, f26(2, 6);

	Fraction f13_1(1, 3);

	cout << (f13 == f13_1 ? "equal" : "not equal") << endl;
	cout << (f13 == f26 ? "equal" : "not equal") << endl;
	cout << (Fraction(10, 50) == Fraction(20, 100) ? "equal" : "not equal") << endl;

	cout << f13 << endl;

	Fraction fr;

	cin >> fr;
	cout << "You entered: " << fr << endl;
	
	cout << ++fr << endl;
	cout << "Immediate after: " << fr << endl;

	cout << fr++ << endl;
	cout << "Immediate after: " << fr << endl;

	Fraction fR = fr + f13;
	cout << fR << endl;

	fR = fr - f13;
	cout << fR << endl;

	return 0;

}
