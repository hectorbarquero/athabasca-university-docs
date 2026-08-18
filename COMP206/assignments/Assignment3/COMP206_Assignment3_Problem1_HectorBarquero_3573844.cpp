//: COMP206_Assignment3_Problem1_HectorBarquero_STUDENT_ID.cpp

/*
 Title: COMP206_Assignment3_Problem1_HectorBarquero_STUDENT_ID.cpp
 Description: Count whitespace-separated words in a text file.
 Date: July 16, 2026
 Author: Hector Barquero
 Version: 1.2
 Copyright: 2026 Hector Barquero
*/

/*
 DOCUMENTATION

 Program Purpose:
    Open a text file supplied as a command-line argument and count the
    whitespace-separated words contained in the file.

 Compile on macOS with Homebrew GCC:
    g++-16 -std=c++17 -Wall -Wextra -pedantic COMP206_Assignment3_Problem1_HectorBarquero_STUDENT_ID.cpp -o COMP206_Assignment3_Problem1_HectorBarquero_STUDENT_ID

 Execution on macOS:
    ./COMP206_Assignment3_Problem1_HectorBarquero_STUDENT_ID.exe excerpt.txt

 Notes:
    This program uses a command-line argument to obtain the input filename.
    A word is any sequence that the stream extraction operator reads between
    whitespace characters. Punctuation remains part of the extracted word.

 Classes: none

 Functions:
    main - validates the CLI, opens the file and counts the words

 Variables:
    inputFile - ifstream - input stream connected to the requested file
    word - string - stores each whitespace-separated word read from the file
    wordCount - size_t - number of words successfully extracted
*/

/*
 TEST PLAN

 Normal case 1, required sample file:
    >./COMP206_Assignment3_Problem1_HectorBarquero_STUDENT_ID.exe excerpt.txt
    >File: excerpt.txt
    >Word count: 327

 Normal case 2, empty file:
    >./COMP206_Assignment3_Problem1_HectorBarquero_STUDENT_ID.exe empty.txt
    >File: empty.txt
    >Word count: 0

 Normal case 3, mixed whitespaces:
    Input file contains: one<space>two<tab>three<newline>four
    Expected word count: 4

 Bad Data case 1, missing command-line argument:
    >./COMP206_Assignment3_Problem1_HectorBarquero_STUDENT_ID.exe
    >Usage: ./COMP206_Assignment3_Problem1_HectorBarquero_STUDENT_ID.exe <input-file>

 Bad Data case 2, file does not exist:
    >./COMP206_Assignment3_Problem1_HectorBarquero_STUDENT_ID.exe missing.txt
    >Error: could not open "missing.txt".

 Discussion:
    Stream extraction with operator naturally skips spaces, tabs and linebreaks. The algorithm reads each word once, 
    so time is O(w), where w is the number of words. Only one word is stored at a time, so extra space is O(1).
*/

#include <fstream>  // ifstream for input class to operate on files: https://cplusplus.com/reference/fstream/ifstream/
#include <iostream> 
#include <string>  

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <input-file>\n";
        return 1;
    }

    const string fileName = argv[1];
    ifstream inputFile(fileName);

    if (!inputFile) {
        cerr << "Error: could not open \"" << fileName << "\".\n";
        return 1;
    }

    string word;
    size_t wordCount = 0;

    while (inputFile >> word) {
        ++wordCount;
    }

    cout << "File: " << fileName << '\n';
    cout << "Word count: " << wordCount << '\n';

    return 0;
} ///:~
