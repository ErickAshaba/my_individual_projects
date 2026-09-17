#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Point {
    string name;
    double x;
    double y;
};

// Calculate Euclidean distance between two points
double distanceBetween(const Point& a, const Point& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;

    return sqrt(dx * dx + dy * dy);
}

int main() {
    // -------------------------------------------------
    // 1. Define the center point
    // -------------------------------------------------
    Point center = {"Center", 0.0, 0.0};

    // -------------------------------------------------
    // 2. Define buffer radii
    // -------------------------------------------------
    vector<double> buffers = {5.0, 10.0, 15.0};

    // Sort buffers from smallest to largest
    sort(buffers.begin(), buffers.end());

    // -------------------------------------------------
    // 3. Define the points to test
    // -------------------------------------------------
    vector<Point> points = {
        {"A", 2.0, 3.0},
        {"B", 4.0, 4.0},
        {"C", 6.0, 5.0},
        {"D", 9.0, 4.0},
        {"E", 12.0, 5.0},
        {"F", 20.0, 10.0}
    };

    cout << fixed << setprecision(2);

    cout << "Center point: ("
         << center.x << ", " << center.y << ")\n\n";

    // -------------------------------------------------
    // 4. Determine points inside each buffer
    // -------------------------------------------------
    for (double radius : buffers) {

        cout << "Points inside buffer radius "
             << radius << ":\n";

        bool found = false;

        for (const Point& p : points) {

            double d = distanceBetween(center, p);

            if (d <= radius) {
                cout << "  " << p.name
                     << " (" << p.x << ", " << p.y << ")"
                     << "  distance = " << d << '\n';

                found = true;
            }
        }

        if (!found) {
            cout << "  No points found.\n";
        }

        cout << '\n';
    }

    
    cout << "\nPOINTS BY BUFFER REGION\n";
    cout << "=======================\n";

    double previousRadius = 0.0;

    for (double radius : buffers) {

        cout << "\nRegion "
             << previousRadius << " - "
             << radius << ":\n";

        bool found = false;

        for (const Point& p : points) {

            double d = distanceBetween(center, p);

            if (d > previousRadius && d <= radius) {
                cout << "  " << p.name
                     << " (" << p.x << ", " << p.y << ")"
                     << "  distance = " << d << '\n';

                found = true;
            }
        }

        if (!found) {
            cout << "  No points found.\n";
        }

        previousRadius = radius;
    }

    return 0;
}