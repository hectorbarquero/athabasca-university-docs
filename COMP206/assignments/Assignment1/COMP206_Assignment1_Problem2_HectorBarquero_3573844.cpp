//: COMP206_Assignment1_Problem2_HectorBarquero_STUDENT_ID.cpp

/*
 Title: COMP206_Assignment1_Problem2_HectorBarquero_STUDENT_ID.cpp
 Description: Convert temp units (F to C, or C to F)
 Date: Jun 13, 2026
 Author: Hector Barquero
 Version: 1.2
 Copyright: 2026 Hector Barquero
*/

/*
 DOCUMENTATION

 Program Purpose:
    Read an int or double as temperature and obtain its unit, convert it to the other unit. Repeat until exit.

 Compile on macOS with Homebrew GCC:
    g++-16 -std=c++17 -Wall -Wextra -pedantic COMP206_Assignment1_Problem2_HectorBarquero_STUDENT_ID.cpp -o COMP206_Assignment1_Problem2_HectorBarquero_STUDENT_ID

 Execution on macOS:
    ./COMP206_Assignment1_Problem2_HectorBarquero_STUDENT_ID.exe

 Classes: none

 Variables:
    temperature - double - temperature entered by the user
    convertedTemperature - double - calculated temperature in the other scale
    unit - char - F/f for Fahrenheit or C/c for Celsius
    repeat - char - Y/y to perform another conversion
*/

/*
 TEST PLAN

 Normal case 1 (F to C)
    >Please enter your temperature: 32
    >Please enter the units (F/C): F
    >A temperature of 32 degrees Fahrenheit is equivalent to 0 degrees Celsius.

    or
    (C to F):

    >Please enter your temperature: 100
    >Please enter the units (F/C): C
    >A temperature of 100 degrees Celsius is equivalent to 212 degrees Fahrenheit.

 Bad Data case 1 (unsupported unit)
    >Please enter your temperature: 25
    >Please enter the units (F/C): K
    >Invalid unit. Use F or C.
    The program asks for another unit while storing the valid temperature in memory.

 Bad Data case 2 (non-numeric temperature)
    >Please enter your temperature: fourteen
    >Invalid temperature. Please use a numeric number (not written)
    The program clears the failed input and asks for the temperature again because it won't accept strings.

 Bad Data case 3 (lowercase input)
    >Please enter your temperature: -40
    >Please enter the units (F/C): c
    >A temperature of -40 degrees Celsius is equivalent to -40 degrees Fahrenheit.
    The program is designed to handle lowercase or uppercase data.

 Discussion:
    The conversion formulas use double values so fractions, uppercase, and lowercase units are accepted
*/

#include <cctype>   // https://cplusplus.com/reference/cctype/ with toupper (https://cplusplus.com/reference/cctype/toupper/)
#include <iostream> 
#include <limits>   // https://en.cppreference.com/cpp/types/numeric_limits

using namespace std;

int main() {
    char repeat = 'Y';

    cout << "This program converts Temperatures from Fahrenheit to Celsius and vice versa.\n";

    while (toupper(static_cast<unsigned char>(repeat)) == 'Y') {
        double temperature = 0.0;

        // accept temperature
        while (true) {
            cout << "Please enter your temperature: ";

            if (cin >> temperature) {
                break;
            }

            cout << "Invalid temperature. Please use a numeric number (not written).\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        char unit = '\0';

        // accept unit
        while (true) {
            cout << "Please enter the units (F/C): ";
            cin >> unit;
            unit = static_cast<char>(toupper(static_cast<unsigned char>(unit)));

            if (unit == 'F' || unit == 'C') {
                break;
            }

            cout << "Invalid unit. Enter F or C.\n";
        }

        if (unit == 'F') {
            const double convertedTemperature = (temperature - 32.0) * 5.0 / 9.0;

            cout << "A temperature of " << temperature
                 << " degrees Fahrenheit is equivalent to " << convertedTemperature
                 << " degrees Celsius.\n";
        } else {
            const double convertedTemperature = (temperature * 9.0 / 5.0) + 32.0;

            cout << "A temperature of " << temperature
                 << " degrees Celsius is equivalent to " << convertedTemperature
                 << " degrees Fahrenheit.\n";
        }

        cout << "Do you want another conversion? (Y/N): ";
        cin >> repeat;
    }

    cout << "Thank you. Goodbye.\n";

    return 0;
} ///:~