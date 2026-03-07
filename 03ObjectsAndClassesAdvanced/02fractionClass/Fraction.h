#include <iostream>
#include <numeric>
#include <set>
#include <list>
#include <algorithm>

class Fraction {
	int numerator;
	int denominator;

public:

	Fraction() : numerator(0), denominator(1) {}

	Fraction(int num, int denom) : numerator(num), denominator(denom) {
		reduce();
	}

	int getNumerator() const {
		return this->numerator;
	}

	int getDenominator() const {
		return this->denominator;
	}

	bool operator<(const Fraction& other) const {
		return this->numerator * other.denominator < other.numerator * this->denominator;
	}

	bool operator == (const Fraction& other) const {
		return this->numerator == other.numerator && this->denominator == other.denominator;
	}

	Fraction operator + (const Fraction& other) const {
		int num = this->numerator * other.denominator + other.numerator * this->denominator;
		int denom = this->denominator * other.denominator;
		return Fraction(num, denom);
	}

	Fraction operator - (const Fraction& other) const {
		int num = this->numerator * other.denominator - other.numerator * this->denominator;
		int denom = this->denominator * other.denominator;
		return Fraction(num, denom);
	}

	Fraction operator++() { // prefix
		this->numerator += this->denominator;
		reduce();
		return *this;
	}

	Fraction operator++(int) { // postfix
		Fraction temp = *this;
		this->numerator += this->denominator;
		reduce();
		return temp;
	}

	void reduce() {
		int gcd = std::gcd(this->numerator, this->denominator);
		if (gcd > 1) {
			this->numerator /= gcd;
			this->denominator /= gcd;
		}
	}

	friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
	friend std::istream& operator>>(std::istream& is, Fraction& f);
};


std::ostream & operator << (std::ostream& os, const Fraction & f) {
	if (f.getDenominator() == 1) {
		os << f.getNumerator();
	}
	else {
		os << f.getNumerator() << "/" << f.getDenominator();
	}
	return os;
}

std::istream & operator >> (std::istream& is, Fraction & f) {
	//char c;  // to read the '/' character
	//is >> f.numerator >> c >> f.denominator;
	is >> f.numerator >> f.denominator; // assuming input is in the form "numerator denominator"
	f.reduce(); // reduce the fraction after reading
	return is;
}