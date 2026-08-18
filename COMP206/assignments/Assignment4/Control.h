//: Control.h part of COMP206_Assignment4_HectorBarquero_STUDENT_ID.cpp and Control.cpp
// See Control.cpp for full documentation

#ifndef CONTROL_H
#define CONTROL_H

#include <map>
#include <string>

class Actions;

struct Command {
    std::string raw;
    std::string action;
    std::string object;
    std::string target;
    bool valid = false;
};

class Control {
public:
    explicit Control(const Actions& actions);

    Command readCommand() const;
    Command parse(const std::string& input) const;

private:
    std::string removeLeadingPreposition(const std::string& text) const;
    const Actions& actions_;
    std::map<std::string, std::string> directionAliases_;
};

#endif
///:~
