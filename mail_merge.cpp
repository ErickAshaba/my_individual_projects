#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// Function to add the correct ordinal suffix to a day
string getOrdinal(int day) {
    if (day >= 11 && day <= 13)
        return to_string(day) + "th";

    switch (day % 10) {
        case 1:
            return to_string(day) + "st";
        case 2:
            return to_string(day) + "nd";
        case 3:
            return to_string(day) + "rd";
        default:
            return to_string(day) + "th";
    }
}

// Function to get the month name
string getMonthName(int month) {
    string months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    return months[month];
}

int main() {
    string firstName;
    string lastName;
    string program;
    string academicYear;

    // Get user information
    cout << "Enter first name: ";
    getline(cin, firstName);

    cout << "Enter last name: ";
    getline(cin, lastName);

    cout << "Enter study program: ";
    getline(cin, program);

    cout << "Enter academic year (e.g. 2027/2028): ";
    getline(cin, academicYear);

    // Get current date automatically
    time_t currentTime = time(nullptr);
    tm* localTime = localtime(&currentTime);

    int day = localTime->tm_mday;
    int month = localTime->tm_mon;
    int year = localTime->tm_year + 1900;

    // Display acceptance letter
    cout << "\n\n==============================================\n";
    cout << "          MAKERERE UNIVERSITY\n";
    cout << "          ACCEPTANCE LETTER\n";
    cout << "==============================================\n\n";

    cout << "Date: "
         << getOrdinal(day) << " "
         << getMonthName(month) << " "
         << year << "\n\n";

    cout << "To: " << firstName << " " << lastName << ",\n\n";

    cout << "Dear " << firstName << ",\n\n";

    cout << "CONGRATULATIONS! I am pleased to inform you that the Makerere University\n";
    cout << "Admissions Board has approved your application for admission to the\n";
    cout << academicYear << " academic year.\n\n";

    cout << "You have been offered a place for the following course:\n";
    cout << "PROGRAM: " << program << "\n\n";

    cout << "As a student of Makerere University, you will be part of a historic\n";
    cout << "institution dedicated to academic excellence and innovation. Please ensure\n";
    cout << "that you report to the Academic Registrar's office with your original\n";
    cout << "academic documents for verification during the orientation week.\n\n";

    cout << "We look forward to welcoming you to Makerere University.\n\n";

    cout << "Yours sincerely,\n\n\n";

    cout << "John Doe\n";
    cout << "Registrar\n";

    return 0;
}