#include <iostream>
#include <sstream>

#include "BigInt.h"

using namespace std;

bool isDivisibleBy5(const BigInt& number)
{
	string digits = number.getDigits();

	char lastDigit = digits[digits.length() - 1];

	return lastDigit == '0' || lastDigit == '5';
}

bool isDivisibleBy9(const BigInt& number)
{
	string digits = number.getDigits();

	int sumDigits = 0;

	for (char c : digits) 
		sumDigits += (c - '0');
	
	return (sumDigits % 9) == 0;
}

bool isDivisibleBy45(const BigInt& number)
{
	return isDivisibleBy9(number) && isDivisibleBy5(number);
}

int main()
{
	string s, e;
	cin >> s >> e;

	BigInt from(s), to(e);

	for (; from < to;) {

		if (isDivisibleBy45(from)) {
			cout << from << endl;
		}

		from += 1;
	}

	return 0;
}

