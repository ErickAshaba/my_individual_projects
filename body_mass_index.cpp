#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double weightPounds, heightInches;

    cout << "Enter weight in pounds: ";
    cin >> weightPounds;

    cout << "Enter height in inches: ";
    cin >> heightInches;

    // Conversion constants
    const double POUND_TO_KG = 0.45359237;
    const double INCH_TO_METER = 0.0254;

    // Convert to metric units
    double weightKg = weightPounds * POUND_TO_KG;
    double heightMeters = heightInches * INCH_TO_METER;

    // Calculate BMI
    double bmi = weightKg / (heightMeters * heightMeters);

    cout << fixed << setprecision(2);
    cout << "BMI is " << bmi << endl;

    // Determine BMI category
    if (bmi < 18.5) {
        cout << "Underweight" << endl;
    }
    else if (bmi < 25.0) {
        cout << "Normal" << endl;
    }
    else if (bmi < 30.0) {
        cout << "Overweight" << endl;
    }
    else {
        cout << "Obese" << endl;
    }

    return 0;
}