//: COMP206_Assignment3_Problem4_HectorBarquero_STUDENT_ID.cpp

/*
 Title: COMP206_Assignment3_Problem4_HectorBarquero_STUDENT_ID.cpp
 Description: Fill and combine three arrays of 25 floating-point values.
 Date: July 16, 2026
 Author: Hector Barquero
 Version: 1.1
 Copyright: 2026 Hector Barquero
*/

/*
 DOCUMENTATION

 Program Purpose:
    Create 3 arrays of 25 floating pt values. Fill the 1st array with the loop counter, fill the 2nd array 
    with the counter squared, and fill the third array with the sum of elements. Display each result.

 Compile on macOS with Homebrew GCC:
    g++-16 -std=c++17 -Wall -Wextra -pedantic COMP206_Assignment3_Problem4_HectorBarquero_STUDENT_ID.cpp -o COMP206_Assignment3_Problem4_HectorBarquero_STUDENT_ID

 Execution on macOS:
    ./COMP206_Assignment3_Problem4_HectorBarquero_STUDENT_ID.exe

 Notes:
    Array indices and loop-counter values run from 0 through 24.

 Classes: none

 Functions:
    main - fills the arrays, adds corresponding elements and displays them

 Variables:
    values - array<double, 25> - loop-counter values
    squares - array<double, 25> - squared loop-counter values
    sums - array<double, 25> - corresponding-element sums
    index - size_t - array index and loop-counter value
*/

/*
 TEST PLAN

 Normal case 1, first element:
    >0; 0.00 + 0.00 = 0.00

 Normal case 2, middle element:
    >12; 12.00 + 144.00 = 156.00

 Normal case 3, final element:
    >24; 24.00 + 576.00 = 600.00

 Structural test:
    Verify exactly 25 output rows are produced.

 Discussion:
    3 separate loops each visit 25 elements. For a generalized array of n elements, total work is 3n, 
    which simplifies to O(n). The three arrays store 3n floating-point values, which simplifies to O(n) space.
*/

#include <array>    //array again
#include <iomanip>  // use setprecision
#include <iostream>

using namespace std;

int main() {
    constexpr size_t arraySize = 25;
    array<double, arraySize> values{};
    array<double, arraySize> squares{};
    array<double, arraySize> sums{};

    for (size_t index = 0; index < arraySize; ++index) {
        values[index] = static_cast<double>(index);
    }

    for (size_t index = 0; index < arraySize; ++index) {
        squares[index] = values[index] * values[index];
    }

    for (size_t index = 0; index < arraySize; ++index) {
        sums[index] = values[index] + squares[index];
    }

    cout << fixed << setprecision(2);

    for (size_t index = 0; index < arraySize; ++index) {
        cout << index << "; "
             << values[index] << " + "
             << squares[index] << " = "
             << sums[index] << '\n';
    }

    return 0;
} ///:~
