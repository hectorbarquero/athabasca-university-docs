//: COMP206_Assignment1_Problem4_HectorBarquero_STUDENT_ID.cpp

/*
 Title: COMP206_Assignment1_Problem4_HectorBarquero_STUDENT_ID.cpp
 Description: Make an interactive help menu of c++ flow control topics.
 Author: Hector Barquero
 Version: 1.3
 Copyright: 2026 Hector Barquero
*/

/*
 DOCUMENTATION

 Program Purpose:
    Display a repeating help menu and use a switch statement to show a short definition for the selected control flow choice. Repeat until exit.

 Compile on macOS with Homebrew GCC:
    g++-16 -std=c++17 -Wall -Wextra -pedantic COMP206_Assignment1_Problem4_HectorBarquero_STUDENT_ID.cpp -o COMP206_Assignment1_Problem4_HectorBarquero_STUDENT_ID

 Execution on macOS:
    ./COMP206_Assignment1_Problem4_HectorBarquero_STUDENT_ID.exe

 Classes: none

 Variables:
    selection - char - menu choice provided by the user
*/

/*
 TEST PLAN

 Normal case 1:
    >Selection: 1
    The program displays if statement definition and returns to menu

    or: 
    >Selection: 5
    The program displays the definition of a do-while loop and returns to menu

    or: 
    >Selection: x
    >Thank you. Good bye.
    The program exits.

    or: 
    >Selection: X
    >Thank you. Good bye.
    The program exits.

 Bad Data case:
    >Selection: 9
    >Invalid selection. Enter 1-5 or x.
    The program returns to the menu without exiting.

 Discussion:
    A do-while loop is used to keep the menu active, while a switch statement handles selection. The program accepts both lowercase and uppercase x to exit.
*/

#include <iostream>

using namespace std;

static void displayMenu() {
    cout << "C++ Help Menu\n"
         << "Select Help on:\n"
         << "1. If\n"
         << "2. Switch\n"
         << "3. For\n"
         << "4. While\n"
         << "5. Do-while\n"
         << "x. Exit\n"
         << "Selection: ";
}

int main() {
    char selection = '\0';

    do {
        displayMenu();
        cin >> selection;

        switch (selection) {
            case '1':
                cout << "if: Selects whether a statement or block runs based on a Boolean condition. An optional else handles the false case. "
                     << "a Boolean condition. An optional else handles the false case.\n\n";
                break;

            case '2':
                cout << "switch: Selects one branch by comparing one expression "
                     << "with case labels. break normally prevents fall-through.\n\n";
                break;

            case '3':
                cout << "for: Repeats a statement or block using initialization, "
                     << "a continuation condition and an update expression.\n\n";
                break;

            case '4':
                cout << "while: Repeats a statement or block while its condition "
                     << "is true. The condition is checked before each iteration.\n\n";
                break;

            case '5':
                cout << "do-while: Repeats a statement or block while its condition "
                     << "is true. The condition is checked after each iteration, "
                     << "so the body runs at least once.\n\n";
                break;

            case 'x':
            case 'X':
                break;

            default:
                cout << "Invalid selection. Enter 1-5 or x.\n\n";
                break;
        }
    } while (selection != 'x' && selection != 'X');

    cout << "Thank you. Good bye.\n";

    return 0;
} ///:~