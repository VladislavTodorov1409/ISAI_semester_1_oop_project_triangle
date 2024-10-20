#include "Shape2D.h"

using namespace std;

// Constructor

Shape2D::Shape2D(string name, bool hasColor) {
    this->name = name;
    this->hasColor = hasColor;
}

// Getters

string Shape2D::getName() {
    return name;
}

bool Shape2D::getHasColor() {
    return hasColor;
}

// Setters

void Shape2D::setName(string name) {
    this->name = name;
}

void Shape2D::setHasColor(bool hasColor) {
    this->hasColor = hasColor;
}

// Methods

string Shape2D::toString() {
    string color;
    if (hasColor) {
        color = "Yes";
    } else {
        color = "No";
    }
    return "Shape Name: " + name + ", Has Color: " + color;
}
