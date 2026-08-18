//: COMP206_Assignment1_Problem5_HectorBarquero_STUDENT_ID.cpp

/*
 Title: COMP206_Assignment1_Problem5_HectorBarquero_STUDENT_ID.cpp
 Description: Find and display all prime numbers from 1 through 10,000.
 Date: Jun 13, 2026
 Author: Hector Barquero
 Version: 1.3
 Copyright: 2026 Hector Barquero
*/

/*
 DOCUMENTATION

 Program Purpose:
    Use two nested for loops and the modulus operator to print every prime number from 1 through 10000

 Compile on macOS with Homebrew GCC:
    g++-16 -std=c++17 -Wall -Wextra -pedantic COMP206_Assignment1_Problem5_HectorBarquero_STUDENT_ID.cpp -o COMP206_Assignment1_Problem5_HectorBarquero_STUDENT_ID

 Execution on macOS:
    ./COMP206_Assignment1_Problem5_HectorBarquero_STUDENT_ID.exe

 Classes: none

 Variables:
    candidate - int - number currently being tested for prime
    divisor - int - possible divisor tested against prime check
    primeCount - int - number of primes and output position counter
    isPrime - bool - remains true unless an even divisor is found
*/

/*
 TEST PLAN

 Normal case:
    Run the program without entering any input.

    Expected output.
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29...

    Expected end of output:
    The last prime should be 9973.

 Bad Data case:
    Not applicable again. This program doesn't accept user input and is a traditional programming problem, it runs when executed.

 Discussion:
    The outer loop selects prime candidates. The inner loop tests possible divisors using candidate % divisor. 
    Testing stops after the square rt of the candidate because a larger factor would require a smaller paired factor.
*/

#include <iomanip>  // setw again
#include <iostream>

using namespace std;

int main() {
    constexpr int MAXIMUM_NUMBER = 10000;
    constexpr int NUMBERS_PER_ROW = 10;
    int primeCount = 0;

    cout << "Prime numbers from 1 to 10,000:\n\n";

    // ignores 1 bc it's not a prime
    for (int candidate = 2; candidate <= MAXIMUM_NUMBER; ++candidate) {
        bool isPrime = true;

        // test candidate
        for (int divisor = 2; divisor * divisor <= candidate; ++divisor) {
            if (candidate % divisor == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            cout << setw(6) << candidate;
            ++primeCount;

            if (primeCount % NUMBERS_PER_ROW == 0) {
                cout << '\n';
            }
        }
    }

    if (primeCount % NUMBERS_PER_ROW != 0) {
        cout << '\n';
    }

    return 0;
} ///:~