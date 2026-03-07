#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
class Point {
private:
    double x;
    double y;

public:
    Point(double xVal, double yVal) : x(xVal), y(yVal) {}

    double calculateDistance(const Point& otherPoint) const {
        double dx = x - otherPoint.x;
        double dy = y - otherPoint.y;
        return sqrt(dx * dx + dy * dy);
    }
};


int main() {

    double x1, y1;
    cin >> x1 >> y1;
    Point p1(x1, y1);

    double x2, y2;
    cin >> x2 >> y2;
    Point p2(x2, y2);

    cout << fixed << setprecision(3) << p1.calculateDistance(p2) << endl;

    return 0; 
}