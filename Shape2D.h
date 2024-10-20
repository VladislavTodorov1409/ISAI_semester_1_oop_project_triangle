#ifndef SHAPE2D_H
#define SHAPE2D_H

#include <string>
#include <iostream>

using namespace std;

class Shape2D {
private:
    string name;
    bool hasColor;

public:
    // Constructor
    Shape2D(string name, bool hasColor);

    // Getters
    string getName();
    bool getHasColor();

    // Setters
    void setName(string name);
    void setHasColor(bool hasColor);

    // Methods
    virtual double area() = 0;
    virtual string toString();
};

#endif
