#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <cmath>

#include "Shape2D.h"

using namespace std;

class Triangle : public Shape2D {
private:
    double a, b, c;

public:
    Triangle(string name, bool hasColor, double a, double b, double c);

    double area() override;

    string toString() override;
};

#endif
