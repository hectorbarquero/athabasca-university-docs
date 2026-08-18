//: Action.h , part of COMP206_Assignment4_HectorBarquero_STUDENT_ID.cpp and Action.cpp
// See Action.cpp for documentation

#ifndef ACTION_H
#define ACTION_H

#include <string>
#include <vector>

struct Action {
    std::string name;
    std::vector<std::string> aliases;
    std::string description;
};

class Actions {
public:
    bool load(const std::string& fileName, std::string& errorMessage);
    const std::vector<Action>& all() const;
    const Action* match(const std::string& command, std::string& remainder) const;

private:
    std::vector<Action> actions_;
};

#endif
///:~
