//: Location.h part of COMP206_Assignment4_HectorBarquero_STUDENT_ID.cpp and Location.cpp
// See Location.cpp for full documentation

#ifndef LOCATION_H
#define LOCATION_H

#include <map>
#include <string>
#include <vector>

struct Location {
    std::string id;
    std::string name;
    std::string longDescription;
    std::string shortDescription;
    bool safe = false;
    bool visited = false;
    std::map<std::string, std::string> exits;
};

class Locations {
public:
    bool load(const std::string& fileName, std::string& errorMessage);
    bool contains(const std::string& id) const;
    Location* get(const std::string& id);
    const Location* get(const std::string& id) const;
    std::vector<std::string> ids() const;

private:
    std::map<std::string, Location> locations_;
};

#endif
///:~
