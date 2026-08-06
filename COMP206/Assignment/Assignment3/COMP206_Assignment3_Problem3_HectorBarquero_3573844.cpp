//: COMP206_Assignment3_Problem3_HectorBarquero_STUDENT_ID.cpp

/*
 Title: COMP206_Assignment3_Problem3_HectorBarquero_STUDENT_ID.cpp
 Description: Read up to 100 text-file lines into a TextFileReader object.
 Date: July 16, 2026
 Author: Hector Barquero
 Version: 1.3
 Copyright: 2026 Hector Barquero
*/

/*
 DOCUMENTATION

 Program Purpose:
    Define a TextFileReader class containing an array of 100 strings. The class can read up to 100 lines from a named text file, 
    return those lines as one str and display them with 1 based line numbers. TextFileReaderDemo tests the class using a CLI filename.

 Compile on macOS with Homebrew GCC:
    g++-16 -std=c++17 -Wall -Wextra -pedantic COMP206_Assignment3_Problem3_HectorBarquero_STUDENT_ID.cpp -o COMP206_Assignment3_Problem3_HectorBarquero_STUDENT_ID

 Execution on macOS:
    ./COMP206_Assignment3_Problem3_HectorBarquero_STUDENT_ID.exe excerpt.txt

 Notes:
    C++ requires the global main() entry point. TextFileReaderDemo therefore provides a static run() method,
    and global main() forwards to that method.

 Classes:
    TextFileReader - stores and displays up to 100 lines from a text file
    TextFileReaderDemo - coordinates command-line testing of TextFileReader

 Functions:
    TextFileReader() - creates an empty reader
    TextFileReader(fileName) - reads up to 100 lines from the named file
    contents() - combines stored lines into one newline-separated string
    display() - displays stored lines as "line #: <string>"
    isOpen() - reports whether the requested file was opened successfully
    size() - returns the number of stored lines
    TextFileReaderDemo::run() - validates arguments and tests the reader
    main() - forwards program execution to TextFileReaderDemo::run()

 Variables:
    lines - array<string, 100> - fixed storage for file lines
    lineCount - size_t - number of array elements currently in use
    fileOpened - bool - true when the requested file opened successfully
*/

/*
 TEST PLAN

 Normal case 1, required sample file:
    >./COMP206_Assignment3_Problem3_HectorBarquero_STUDENT_ID.exe excerpt.txt
    The contents() result is displayed first. The display() result follows using 1 based line numbers.

 Normal case 2, three-line file:
    Expected size: 3
    Expected display labels: line 1, line 2 and line 3

 Normal case 3, file longer than 100 lines:
    Expected result: only the first 100 lines are stored and displayed.

 Normal case 4, default constructor:
    TextFileReader reader;
    Expected contents(): empty string
    Expected size(): 0

 Bad Data case 1, missing command-line argument:
    >./COMP206_Assignment3_Problem3_HectorBarquero_STUDENT_ID.exe
    >Usage: ./COMP206_Assignment3_Problem3_HectorBarquero_STUDENT_ID.exe <input-file>

 Bad Data case 2, file does not exist:
    >./COMP206_Assignment3_Problem3_HectorBarquero_STUDENT_ID.exe missing.txt
    >Error: could not open "missing.txt".

 Discussion:
    Reading n lines takes O(n) time, where n is limited to 100. contents() also takes O(c) time bc it copies 
    the stored characters into one str. The fixed array uses O(100), or O(1) line slots while the character data
    occupies O(c) space.
*/

#include <array>    
#include <fstream> 
#include <iostream>
#include <sstream> //header providing string seam classes: https://cplusplus.com/reference/sstream/
#include <string>

using namespace std;

class TextFileReader {
private:
    static constexpr size_t maximumLines = 100;
    array<string, maximumLines> lines{};
    size_t lineCount = 0;
    bool fileOpened = false;

public:
    TextFileReader() = default;

    explicit TextFileReader(const string& fileName) {
        ifstream inputFile(fileName);

        if (!inputFile) {
            return;
        }

        fileOpened = true;

        while (lineCount < maximumLines && getline(inputFile, lines[lineCount])) {
            ++lineCount;
        }
    }

    string contents() const {
        ostringstream combined;

        for (size_t index = 0; index < lineCount; ++index) {
            combined << lines[index];
            if (index + 1 < lineCount) {
                combined << '\n';
            }
        }

        return combined.str();
    }

    void display() const {
        for (size_t index = 0; index < lineCount; ++index) {
            cout << "line " << index + 1 << ": " << lines[index] << '\n';
        }
    }

    bool isOpen() const {
        return fileOpened;
    }

    size_t size() const {
        return lineCount;
    }
};

class TextFileReaderDemo {
public:
    static int run(int argc, char* argv[]) {
        if (argc != 2) {
            cerr << "Usage: " << argv[0] << " <input-file>\n";
            return 1;
        }

        const string fileName = argv[1];
        TextFileReader reader(fileName);

        if (!reader.isOpen()) {
            cerr << "Error: could not open \"" << fileName << "\".\n";
            return 1;
        }

        cout << "File contents:\n";
        cout << reader.contents() << "\n\n";

        cout << "Numbered display:\n";
        reader.display();

        cout << "\nLines stored: " << reader.size() << '\n';
        return 0;
    }
};

int main(int argc, char* argv[]) {
    return TextFileReaderDemo::run(argc, argv);
} ///:~
