#include <iostream>
using namespace std;

int main() {
    const long long currentPopulation = 312032486;

    const int secondsPerMinute = 60;
    const int minutesPerHour = 60;
    const int hoursPerDay = 24;
    const int daysPerYear = 365;

    // Total seconds in one year
    long long secondsPerYear =
        secondsPerMinute * minutesPerHour * hoursPerDay * daysPerYear;

    // Population changes per year
    long long births = secondsPerYear / 7;
    long long deaths = secondsPerYear / 13;
    long long immigrants = secondsPerYear / 45;

    long long population = currentPopulation;

    for (int year = 1; year <= 5; year++) {
        population = population + births - deaths + immigrants;

        cout << "Population after year "
             << year << ": "
             << population << endl;
    }

    return 0;
}