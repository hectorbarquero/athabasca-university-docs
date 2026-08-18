//: Item.cpp, part of COMP206_Assignment4_HectorBarquero_STUDENT_ID.cpp

/*
 Title: COMP206_Assignment4_HectorBarquero_STUDENT_ID.cpp
 Description: Load, store and locate interactive items used in the Wonderland adventure game.
 Date: July 26, 2026
 Author: Hector Barquero
 Version: 2.1
 Copyright: 2026 Hector Barquero
*/

/*
 DOCUMENTATION

 Program Purpose:
    Load item definitions from an external text file and store them as Item
    objects indexed by unique item identifiers.

    Provide methods for retrieving items by identifier, matching player queries
    against item names and aliases, locating items at permitted locations and
    retrieving collections of items by location or as a complete list.

 Compile on macOS with Homebrew GCC:
    g++ -o Wonderland.exe *.cpp

 Execution on macOS:
    ./Wonderland.exe

 Notes:
    Item records are loaded from data/items.txt.

    Each item record uses the following pipe-separated format:

        id|name|aliases|description|location|takeable|treasure|points|use text

    Blank lines and lines beginning with # are ignored.

    Item identifiers and locations are converted to lowercase. Item aliases and
    names are normalized using TextUtils so capitalization and punctuation do
    not affect player commands.

    The point value field is converted from text to an integer using stoi().
    Invalid point values cause loading to fail with an error message.

    Items are stored in an unordered map using their unique identifier as the
    key. Pointer collections returned by at() and all() refer to Item objects
    stored inside this map.

 Classes:
    Item - stores the identifier, name, aliases, description, location, item
           properties, point value and use text for one game item

    Items - loads, stores, matches and retrieves Item objects

 Functions:
    Items::load - opens the item data file, validates each record and stores the
                  resulting Item objects

    Items::get - retrieves an item by its unique identifier

    Items::matches - determines whether a player query matches an item's
                     normalized aliases

    Items::findAt - returns an item matching a query at one of the permitted
                    locations

    Items::at - returns all items assigned to a specified location

    Items::all - returns all items stored by the Items object

 Variables:
    items_ - unordered_map<string, Item> - stores items indexed by their unique
             identifiers

    fileName - string - path of the item data file to load

    errorMessage - string - receives an explanation when loading fails

    input - ifstream - input stream connected to the item data file

    line - string - stores each line read from the item data file

    lineNumber - int - tracks the current line for validation errors

    fields - vector<string> - stores the nine pipe-separated item fields

    item - Item - temporary object created for each valid item record

    alias - string - reference used to normalize each item alias

    id - string - unique identifier used to retrieve an item

    found - unordered-map iterator - result of searching for an item identifier

    query - string - item name or alias supplied for matching

    normalized - string - normalized form of the item query

    allowedLocations - vector<string> - locations in which an item may be found

    location - string - identifier of the location being searched

    entry - map entry - provides access to each stored identifier and Item

    result - vector<Item pointer> - stores pointers returned by at() or all()
*/

/*
 TEST PLAN

 See the assignment journal for the full test plan, which includes the details
 on test plans for the project as a whole, including this file.

 Discussion:

 See the assignment journal for the full reflection journal, including discussion
 of the order of magnitude of this program.
*/

#include "Item.h"
#include "TextUtils.h"

#include <algorithm>
#include <fstream>

bool Items::load(const std::string& fileName, std::string& errorMessage) {
    std::ifstream input(fileName);
    if (!input) {
        errorMessage = "Unable to open item file: " + fileName;
        return false;
    }

    items_.clear();
    std::string line;
    int lineNumber = 0;

    while (std::getline(input, line)) {
        ++lineNumber;
        line = TextUtils::trim(line);
        if (line.empty() || line[0] == '#') {
            continue;
        }

        const std::vector<std::string> fields = TextUtils::split(line, '|');
        if (fields.size() != 9) {
            errorMessage = "Invalid item record at line " + std::to_string(lineNumber);
            return false;
        }

        Item item;
        item.id = TextUtils::lowercase(TextUtils::trim(fields[0]));
        item.name = fields[1];
        item.aliases = TextUtils::split(fields[2], ',');
        item.description = fields[3];
        item.location = TextUtils::lowercase(TextUtils::trim(fields[4]));
        item.takeable = TextUtils::lowercase(fields[5]) == "true";
        item.treasure = TextUtils::lowercase(fields[6]) == "true";

        try {
            item.points = std::stoi(fields[7]);
        } catch (...) {
            errorMessage = "Invalid point value at item line " + std::to_string(lineNumber);
            return false;
        }

        item.useText = fields[8];
        for (std::string& alias : item.aliases) {
            alias = TextUtils::normalizeCommand(alias);
        }
        item.aliases.push_back(TextUtils::normalizeCommand(item.name));
        item.aliases.push_back(item.id);
        items_[item.id] = item;
    }

    return !items_.empty();
}

Item* Items::get(const std::string& id) {
    const auto found = items_.find(id);
    return found == items_.end() ? nullptr : &found->second;
}

const Item* Items::get(const std::string& id) const {
    const auto found = items_.find(id);
    return found == items_.end() ? nullptr : &found->second;
}

bool Items::matches(const Item& item, const std::string& query) const {
    const std::string normalized = TextUtils::normalizeCommand(query);
    return std::find(item.aliases.begin(), item.aliases.end(), normalized) != item.aliases.end();
}

Item* Items::findAt(const std::string& query, const std::vector<std::string>& allowedLocations) {
    for (auto& entry : items_) {
        if (std::find(allowedLocations.begin(), allowedLocations.end(), entry.second.location) != allowedLocations.end() &&
            matches(entry.second, query)) {
            return &entry.second;
        }
    }
    return nullptr;
}

const Item* Items::findAt(const std::string& query, const std::vector<std::string>& allowedLocations) const {
    for (const auto& entry : items_) {
        if (std::find(allowedLocations.begin(), allowedLocations.end(), entry.second.location) != allowedLocations.end() &&
            matches(entry.second, query)) {
            return &entry.second;
        }
    }
    return nullptr;
}

std::vector<Item*> Items::at(const std::string& location) {
    std::vector<Item*> result;
    for (auto& entry : items_) {
        if (entry.second.location == location) {
            result.push_back(&entry.second);
        }
    }
    return result;
}

std::vector<const Item*> Items::at(const std::string& location) const {
    std::vector<const Item*> result;
    for (const auto& entry : items_) {
        if (entry.second.location == location) {
            result.push_back(&entry.second);
        }
    }
    return result;
}

std::vector<Item*> Items::all() {
    std::vector<Item*> result;
    for (auto& entry : items_) {
        result.push_back(&entry.second);
    }
    return result;
}

std::vector<const Item*> Items::all() const {
    std::vector<const Item*> result;
    for (const auto& entry : items_) {
        result.push_back(&entry.second);
    }
    return result;
}
///:~
