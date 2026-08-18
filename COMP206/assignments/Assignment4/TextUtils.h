//: TextUtils.h part of COMP206_Assignment4_HectorBarquero_STUDENT_ID.cpp and TextUtils.cpp
// See TextUtils.cpp for full documentation

#ifndef TEXTUTILS_H
#define TEXTUTILS_H

#include <string>
#include <vector>

namespace TextUtils {
std::string trim(const std::string& value);
std::string lowercase(const std::string& value);
std::string normalizeCommand(const std::string& value);
std::vector<std::string> split(const std::string& value, char delimiter);
std::string join(const std::vector<std::string>& values, const std::string& separator);
bool startsWithPhrase(const std::string& text, const std::string& phrase);
}

#endif
///:~
