#pragma once

#include "Vector2D.h"

class Shape {
protected:
    Vector2D center;
    double area;

public:
    // Default constructor
    Shape() : center(0, 0), area(0.0) {}

    // Constructor with center
    Shape(Vector2D center) : center(center), area(0.0) {}

    // Virtual destructor to ensure proper cleanup of derived classes
    virtual ~Shape() = default;

    // Getter for center
    Vector2D getCenter() const {
        return center;
    }

    // Getter for area
    double getArea() const {
        return area;
    }
};