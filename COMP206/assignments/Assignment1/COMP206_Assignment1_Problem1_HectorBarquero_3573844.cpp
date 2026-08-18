//: COMP206_Assignment1_Problem1_HectorBarquero_STUDENT_ID.cpp

/*
 Title: COMP206_Assignment1_Problem1_HectorBarquero_STUDENT_ID.cpp
 Description: Generate multiplication tables from 1(x) through 12(x).
 Date: Jun 13, 2026
 Author: Hector Barquero
 Version: 1.7
 Copyright: 2026 Hector Barquero
*/

/*
 DOCUMENTATION

 Program Purpose:
    Displays a multiplication table with values from 1x through 12x using nested for loops.

 Compiled on macOS with Homebrew GCC:
    g++-16 -std=c++17 -Wall -Wextra -pedantic COMP206_Assignment1_Problem1_HectorBarquero_STUDENT_ID.cpp -o COMP206_Assignment1_Problem1_HectorBarquero_STUDENT_ID

 Execution on macOS:
    ./COMP206_Assignment1_Problem1_HectorBarquero_STUDENT_ID.exe

 Classes: none

 Variables:
    row - int - sets the current table row
    column - int - sets the current table column
*/

/*
 TEST PLAN

 Normal case:
    Program executes without entering any input.

    Expected result:
    Displays a header row numbered 1 through 12. The first result is 1 and the final result should be 144.

 Bad Data case:
    Program doesn't accept user input, it should run unless hardware issues.

 Discussion:
    I used std::setw to provide the required table formatting after finding it in c++ docs. Since this program doesnt accept user input, the program should execute without any edge cases.
*/

#include <iomanip> //setw with iomanip for parametric manipulators https://cplusplus.com/reference/iomanip/
#include <iostream>

using namespace std;

int main() {
    constexpr int TABLE_LIMIT = 12;

    cout << "Multiplication Table from 1x to 12x\n";

    // columns
    cout << setw(3) << "" << '|';
    for (int column = 1; column <= TABLE_LIMIT; ++column) {
        // parametric manipulate with setw https://cplusplus.com/reference/iomanip/setw/
        cout << setw(4) << column << '|';
    }
    cout << '\n';

    // print table portion
    for (int row = 1; row <= TABLE_LIMIT; ++row) {
        cout << setw(3) << row << '|';

        for (int column = 1; column <= TABLE_LIMIT; ++column) {
            cout << setw(4) << (row * column) << '|';
        }

        cout << '\n';
    }

    return 0;
} ///:~