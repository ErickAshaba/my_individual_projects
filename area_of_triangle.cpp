#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double x1, y1, x2, y2, x3, y3;

    // Prompt user for the three points
    cout << "Enter three points for a triangle: ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    // Calculate the lengths of the three sides
    double side1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    double side2 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    double side3 = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));

    // Calculate s (semi-perimeter)
    double s = (side1 + side2 + side3) / 2.0;

    // Calculate area using Heron's formula
    double area = sqrt(s * (s - side1) *
                         (s - side2) *
                         (s - side3));

    cout << fixed << setprecision(1);
    cout << "The area of the triangle is " << area << endl;

    return 0;
}