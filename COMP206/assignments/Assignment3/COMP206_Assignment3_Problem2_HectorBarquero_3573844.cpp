//: COMP206_Assignment3_Problem2_HectorBarquero_STUDENT_ID.cpp

/*
 Title: COMP206_Assignment3_Problem2_HectorBarquero_STUDENT_ID.cpp
 Description: Display a text file one line at a time after Enter is pressed.
 Date: July 16, 2026
 Author: Hector Barquero
 Version: 1.2
 Copyright: 2026 Hector Barquero
*/

/*
 DOCUMENTATION

 Program Purpose:
    Prompt the user for a text filename, open the file and display one line at
    a time. After each displayed line, wait for the user to press Enter before
    continuing to the next line.

 Compile on macOS with Homebrew GCC:
    g++-16 -std=c++17 -Wall -Wextra -pedantic COMP206_Assignment3_Problem2_HectorBarquero_STUDENT_ID.cpp -o COMP206_Assignment3_Problem2_HectorBarquero_STUDENT_ID

 Execution on macOS:
    ./COMP206_Assignment3_Problem2_HectorBarquero_STUDENT_ID.exe

 Notes:
    The filename is obtained through a prompt and getline(), not through
    CLI args. Filenames containing spaces are accepted.

 Classes: none

 Functions:
    main - obtains the filename, reads the file and pauses after every line

 Variables:
    fileName - string - filename entered
    inputFile - ifstream - input stream connected to the requested file
    line - string - current line read from the file
    pauseInput - string - receives the Enter key after each displayed line
    lineNumber - size_t - current one-based line number
*/

/*
 TEST PLAN

 Normal case 1, required sample file:
    >Enter the input filename: excerpt.txt
    The file is displayed one complete line at a time. After each line the program waits for Enter.

 Normal case 2, multi-line file:
    Input file contains three lines.
    Expected result: exactly three lines are displayed, each followed by a pause..

 Normal case 3, blank line:
    Input file contains a blank line between two text lines.
    Expected result: the blank line is displayed and still requires presing Enter.

 Bad Data case 1, blank filename:
    >Enter the input filename:
    >Error: a filename is required.

 Bad Data case 2, file does not exist:
    >Enter the input filename: missing.txt
    >Error: could not open "missing.txt".

 Discussion:
    getline() preserves each complete line, including internal spaces. Every line is read once, so 
    time is O(c), where c is the number of characters in the file. The program stores only the current line, 
    so extra space is O(L),where L is the length of the longest line.
*/

#include <fstream>  // ifstream again
#include <iostream> 
#include <string>  

using namespace std;

int main() {
    cout << "Enter the input filename: ";

    string fileName;
    getline(cin, fileName);

    if (fileName.empty()) {
        cerr << "Error: a filename is required.\n";
        return 1;
    }

    ifstream inputFile(fileName);
    if (!inputFile) {
        cerr << "Error: could not open \"" << fileName << "\".\n";
        return 1;
    }

    string line;
    string pauseInput;
    size_t lineNumber = 1;

    while (getline(inputFile, line)) {
        cout << lineNumber << ": " << line << '\n';
        cout << "Press <Enter> to continue...";
        getline(cin, pauseInput);
        ++lineNumber;
    }

    cout << "End of file.\n";
    return 0;
} ///:~
