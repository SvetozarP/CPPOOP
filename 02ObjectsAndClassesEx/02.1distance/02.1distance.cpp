#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;

class Point {
    int x;
	int y;

public:

	Point() : x(0), y(0) {}

	Point(int x_, int y_) : x(x_), y(y_) {}

	Point(istream& in) {
		in >> x >> y;
	}

	double eucledianDistance(const Point & other) const {
		double res;
		res = sqrt((this->x - other.x)*(this->x - other.x) + (this->y - other.y)*(this->y - other.y));
		return res;
	}
};

int main()
{
    
	Point p1(cin);
	Point p2(cin);

	cout << fixed << setprecision(3) << p1.eucledianDistance(p2) << endl;

	return 0;

}
