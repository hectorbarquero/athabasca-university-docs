//: Problem3.cpp

/*
 Title: COMP206_Assignment1_Problem3_HectorBarquero_STUDENT_ID.cpp
 Description: print F to C and C to F comparative tables
 Date: Jun 13, 2026
 Author: Hector Barquero
 Version: 1.0
 Copyright: 2026 Hector Barquero
*/

/*
 DOCUMENTATION

 Program Purpose:
    Prints 100 temp conversion rows starting at -40 degrees and increases by 5 deg per row. Each row shows both conversions C and F.

 Compile on macOS with Homebrew GCC:
    g++-16 -std=c++17 -Wall -Wextra -pedantic COMP206_Assignment1_Problem3_HectorBarquero_STUDENT_ID.cpp -o COMP206_Assignment1_Problem3_HectorBarquero_STUDENT_ID

 Execution on macOS:
    ./COMP206_Assignment1_Problem3_HectorBarquero_STUDENT_ID.exe

 Classes: none

 Variables:
    entry - int - current table-row index from 0 through 99
    temperature - double - source temperature for both conversion columns
*/

/*
 TEST PLAN

 Normal case:
    Run the program without entering any input.

   first row:
      -40.000     -40.000  |    -40.000     -40.000

   middle verification row:
      100.000      37.778  |    100.000     212.000

   final row:
      455.000     235.000  |    455.000     851.000


 Bad Data case:
    Not applicable again, this program doesn't accept user input and either works or doesnt (for hardware issues).

 Discussion:
    Static conversion funcs separate the formulas from the output loop. I use std::fixed, std::setprecision and std::setw to control formatting per docs.
*/

#include <iomanip>  // using again for fixed, setprecision, setw
#include <iostream>

using namespace std;

static double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

static double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

int main() {
    constexpr int NUMBER_OF_ENTRIES = 100;
    constexpr double START_TEMPERATURE = -40.0;
    constexpr double TEMPERATURE_INTERVAL = 5.0;

    cout << "Temperature Conversion Tables\n";
    cout << "      Temperature      |      Temperature\n";
    cout << "       (degrees)       |       (degrees)\n";
    cout << "     F           C     |       C           F\n";

    cout << fixed << setprecision(3);

    for (int entry = 0; entry < NUMBER_OF_ENTRIES; ++entry) {
        const double temperature =
            START_TEMPERATURE + (entry * TEMPERATURE_INTERVAL);

        cout << setw(10) << temperature
             << setw(12) << fahrenheitToCelsius(temperature)
             << "  |"
             << setw(11) << temperature
             << setw(12) << celsiusToFahrenheit(temperature)
             << '\n';
    }

    return 0;
} ///:~