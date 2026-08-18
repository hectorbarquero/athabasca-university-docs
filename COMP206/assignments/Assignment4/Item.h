//: Item.h part of COMP206_Assignment4_HectorBarquero_STUDENT_ID.cpp and Item.cpp
// See Item.cpp for full documentation

#ifndef ITEM_H
#define ITEM_H

#include <map>
#include <string>
#include <vector>

struct Item {
    std::string id;
    std::string name;
    std::vector<std::string> aliases;
    std::string description;
    std::string location;
    bool takeable = true;
    bool treasure = false;
    int points = 0;
    std::string useText;
    bool used = false;
    bool scored = false;
};

class Items {
public:
    bool load(const std::string& fileName, std::string& errorMessage);
    Item* get(const std::string& id);
    const Item* get(const std::string& id) const;
    Item* findAt(const std::string& query, const std::vector<std::string>& allowedLocations);
    const Item* findAt(const std::string& query, const std::vector<std::string>& allowedLocations) const;
    std::vector<Item*> at(const std::string& location);
    std::vector<const Item*> at(const std::string& location) const;
    std::vector<Item*> all();
    std::vector<const Item*> all() const;

private:
    bool matches(const Item& item, const std::string& query) const;
    std::map<std::string, Item> items_;
};

#endif
///:~
