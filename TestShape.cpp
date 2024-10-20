#include <iostream>
#include <vector>
#include <stdexcept>

#include "Shape2D.h"
#include "Triangle.h"

#include "Shape2D.cpp"
#include "Triangle.cpp"

using namespace std;

Triangle createTriangle() {
    string name;
    bool hasColor;
    double a, b, c;

    cout << "Enter the name of the triangle: ";
    cin >> name;
    if (cin.fail()) {
        throw invalid_argument("Invalid input");
    }
    if (name.length() == 0) {
        throw invalid_argument("Name cannot be empty");
    }

    cout << "Does the triangle have color? (1 for Yes, 0 for No): ";
    cin >> hasColor;
    if (cin.fail()) {
        throw invalid_argument("Invalid input");
    }
    if (hasColor != 0 && hasColor != 1) {
        throw invalid_argument("hasColor must be 0 or 1");
    }

    cout << "Enter the length of side a: ";
    cin >> a;
    if (cin.fail()) {
        throw invalid_argument("Invalid input");
    }
    if (a <= 0) {
        throw invalid_argument("Side length must be positive");
    }

    cout << "Enter the length of side b: ";
    cin >> b;
    if (cin.fail()) {
        throw invalid_argument("Invalid input");
    }
    if (b <= 0) {
        throw invalid_argument("Side length must be positive");
    }

    cout << "Enter the length of side c: ";
    cin >> c;
    if (cin.fail()) {
        throw invalid_argument("Invalid input");
    }
    if (c <= 0) {
        throw invalid_argument("Side length must be positive");
    }

    if (a + b <= c || a + c <= b || b + c <= a) {
        throw std::invalid_argument("Invalid side lengths: Does not satisfy the triangle inequality");
    }

    cout << endl;

    return Triangle(name, hasColor, a, b, c);
}

int main(){
    try{
        vector<Triangle> triangles;
        int numberOfTriangles = 6;

        // Input 6 triangles from the user
        for (int i = 0; i < numberOfTriangles; i++) {
            triangles.push_back(createTriangle());
        }

        // Print information for all triangles
        for (int i = 0; i < numberOfTriangles; i++) {
            cout << triangles[i].toString() << endl;
        }

        // Calculate the sum of the areas of all triangles
        double sum = 0;
        for (int i = 0; i < numberOfTriangles; i++) {
            sum += triangles[i].area();
        }

        cout << "\nThe sum of the areas of all triangles is: " << sum << endl << endl;

        // Print the largest triangle's name and color
        Triangle largestTriangle = triangles[0];
        for (int i = 1; i < numberOfTriangles; i++) {
            if (triangles[i].area() > largestTriangle.area()) {
                largestTriangle = triangles[i];
            }
        }

        cout << "The largest triangle is:\n" << largestTriangle.toString() << endl << endl;
    }
    catch(const exception& e){
        cerr << e.what() << '\n';
    }
    
    return 0;
}