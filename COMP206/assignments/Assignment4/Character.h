//: Character.h part of COMP206_Assignment4_HectorBarquero_STUDENT_ID.cpp and Character.cpp
// See Character.cpp for full documentation

#ifndef CHARACTER_H
#define CHARACTER_H

#include <map>
#include <string>
#include <vector>

struct Character {
    std::string id;
    std::string name;
    std::vector<std::string> aliases;
    std::string description;
    std::string location;
    bool friendly = true;
    std::string dialogue;
    std::string encounterText;
};

class Characters {
public:
    bool load(const std::string& fileName, std::string& errorMessage);
    Character* findAt(const std::string& query, const std::string& location);
    const Character* findAt(const std::string& query, const std::string& location) const;
    std::vector<Character*> at(const std::string& location);
    std::vector<const Character*> at(const std::string& location) const;
    std::vector<Character*> all();
    std::vector<const Character*> all() const;

private:
    bool matches(const Character& character, const std::string& query) const;
    std::map<std::string, Character> characters_;
};

#endif
///:~
