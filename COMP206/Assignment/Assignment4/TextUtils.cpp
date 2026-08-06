//: TextUtils.cpp, part of COMP206_Assignment4_HectorBarquero_STUDENT_ID.cpp

/*
 Title: COMP206_Assignment4_HectorBarquero_STUDENT_ID.cpp
 Description: Provide shared string-processing utilities for the Wonderland adventure game.
 Date: July 26, 2026
 Author: Hector Barquero
 Version: 2.3
 Copyright: 2026 Hector Barquero
*/

/*
 DOCUMENTATION

 Program Purpose:
    Provide reusable text-processing functions used throughout the Wonderland
    adventure game.

    Remove surrounding whitespace, convert strings to lowercase, normalize
    player commands, split delimited records, join collections of strings and
    determine whether a command begins with a complete action phrase.

 Compile on macOS with Homebrew GCC:
    g++ -o Wonderland.exe *.cpp

 Execution on macOS:
    ./Wonderland.exe

 Notes:
    All functions are contained in the TextUtils namespace.

    normalizeCommand() converts alphabetic characters to lowercase, preserves
    numbers, replaces punctuation and other separators with spaces, collapses
    repeated separators and removes leading and trailing whitespace.

    Character classification functions such as isspace(), isalnum() and
    tolower() receive unsigned char values to avoid undefined behaviour for
    negative character values.

    split() trims each resulting field after separating the input using the
    supplied delimiter.

    startsWithPhrase() verifies that the matched phrase is either the complete
    input or is followed by a space. This prevents partial-word matches.

 Classes:
    none

 Namespace:
    TextUtils - contains shared string-processing utility functions

 Functions:
    TextUtils::trim - removes whitespace from the beginning and end of a string

    TextUtils::lowercase - returns a lowercase copy of a string

    TextUtils::normalizeCommand - converts command text into lowercase words
                                  separated by single spaces

    TextUtils::split - separates a string using a specified delimiter and
                       returns the trimmed fields

    TextUtils::join - combines a vector of strings using a supplied separator

    TextUtils::startsWithPhrase - determines whether text begins with a complete
                                 phrase rather than a partial word

 Variables:
    value - string - source string supplied to a utility function

    first - size_t - index of the first non-whitespace character

    last - size_t - position following the final non-whitespace character

    result - string - transformed copy returned by lowercase()

    c - unsigned char - one character being classified or converted

    cleaned - string - normalized command being constructed

    previousWasSpace - bool - indicates whether the previous output character
                       was a separator

    delimiter - char - character used to divide a string into fields

    parts - vector<string> - collection of fields created by split()

    stream - stringstream - reads delimiter-separated fields from a string

    part - string - one field extracted by split()

    values - vector<string> - collection of strings supplied to join()

    separator - string - text inserted between values by join()

    output - ostringstream - constructs the combined output string

    i - size_t - index of the current value being joined

    text - string - complete normalized command being examined

    phrase - string - action name or alias expected at the start of the command
*/

/*
 TEST PLAN

 See the assignment journal for the full test plan, which includes the details
 on test plans for the project as a whole, including this file.

 Discussion:

 See the assignment journal for the full reflection journal, including discussion
 of the order of magnitude of this program.
*/

#include "TextUtils.h"

#include <algorithm>
#include <cctype>
#include <sstream>

namespace TextUtils {

std::string trim(const std::string& value) {
    std::size_t first = 0;
    while (first < value.size() && std::isspace(static_cast<unsigned char>(value[first]))) {
        ++first;
    }

    std::size_t last = value.size();
    while (last > first && std::isspace(static_cast<unsigned char>(value[last - 1]))) {
        --last;
    }

    return value.substr(first, last - first);
}

std::string lowercase(const std::string& value) {
    std::string result = value;
    std::transform(result.begin(), result.end(), result.begin(), [](unsigned char c) {
        return static_cast<char>(std::tolower(c));
    });
    return result;
}

std::string normalizeCommand(const std::string& value) {
    std::string cleaned;
    cleaned.reserve(value.size());

    bool previousWasSpace = true;
    for (unsigned char c : value) {
        if (std::isalnum(c)) {
            cleaned.push_back(static_cast<char>(std::tolower(c)));
            previousWasSpace = false;
        } else if (!previousWasSpace) {
            cleaned.push_back(' ');
            previousWasSpace = true;
        }
    }

    return trim(cleaned);
}

std::vector<std::string> split(const std::string& value, char delimiter) {
    std::vector<std::string> parts;
    std::stringstream stream(value);
    std::string part;

    while (std::getline(stream, part, delimiter)) {
        parts.push_back(trim(part));
    }

    return parts;
}

std::string join(const std::vector<std::string>& values, const std::string& separator) {
    std::ostringstream output;
    for (std::size_t i = 0; i < values.size(); ++i) {
        if (i > 0) {
            output << separator;
        }
        output << values[i];
    }
    return output.str();
}

bool startsWithPhrase(const std::string& text, const std::string& phrase) {
    if (text == phrase) {
        return true;
    }
    return text.size() > phrase.size() &&
           text.compare(0, phrase.size(), phrase) == 0 &&
           text[phrase.size()] == ' ';
}

} // namespace TextUtils
///:~