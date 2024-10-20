#include <cmath>

#include "Triangle.h"

using namespace std;

Triangle::Triangle(string name, bool hasColor, double a, double b, double c): Shape2D(name, hasColor) {
    this->a = a;
    this->b = b;
    this->c = c;
}

double Triangle::area() {
    double p = (a + b + c) / 2; 
    double x = p * (p - a) * (p - b) * (p - c);
    double area = sqrt(x);
    return area;
}

string Triangle::toString() {
    return Shape2D::toString() + ", Sides: a = " + to_string(a) + ", b = " + to_string(b) + ", c = " + to_string(c) + ", Area: " + to_string(area());
}
