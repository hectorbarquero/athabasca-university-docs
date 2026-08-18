//: Character.cpp, part of COMP206_Assignment4_HectorBarquero_STUDENT_ID.cpp

/*
 Title: COMP206_Assignment4_HectorBarquero_STUDENT_ID.cpp
 Description: Load, store and locate characters used in the Wonderland adventure game.
 Date: July 26, 2026
 Author: Hector Barquero
 Version: 1.7
 Copyright: 2026 Hector Barquero
*/

/*
 DOCUMENTATION

 Program Purpose:
    Load character definitions from an external text file and store them as
    Character objects indexed by a unique character identifier.

    Provide methods for matching character names and aliases, locating a
    character at a particular game location, retrieving all characters at a
    location and retrieving the complete collection of characters.

 Compile on macOS with Homebrew GCC:
    g++ -o Wonderland.exe *.cpp

 Execution on macOS:
    ./Wonderland.exe

 Notes:
    Character records are loaded from data/characters.txt.

    Each character record uses the following pipe-separated format:

        id|name|aliases|description|location|friendly|dialogue|encounter text

    Blank lines and lines beginning with # are ignored.

    Character identifiers and locations are converted to lowercase. Character
    names and aliases are normalized using TextUtils so that capitalization and
    punctuation do not affect player commands.

    Characters are stored in an unordered map using their unique identifier as
    the key. Pointer collections returned by at() and all() refer to Character
    objects stored inside this map.

 Classes:
    Character - stores the identifying information, location, behaviour and
                dialogue for one game character

    Characters - loads, stores, matches and retrieves Character objects

 Functions:
    Characters::load - opens the character data file, validates each record and
                       stores the resulting Character objects

    Characters::matches - determines whether a query matches one of a
                          character's normalized aliases

    Characters::findAt - returns a matching character located in the specified
                         room

    Characters::at - returns all characters currently assigned to a specified
                     location

    Characters::all - returns all characters stored by the Characters object

 Variables:
    characters_ - unordered_map<string, Character> - stores characters indexed
                  by their unique identifiers

    fileName - string - path of the character data file to load

    errorMessage - string - receives an explanation when loading fails

    input - ifstream - input stream connected to the character data file

    line - string - stores each line read from the character data file

    lineNumber - int - tracks the current line for validation errors

    fields - vector<string> - stores the eight pipe-separated character fields

    character - Character - temporary object created for each valid record

    alias - string - reference used to normalize each character alias

    query - string - character name or alias supplied for matching

    normalized - string - normalized form of the character query

    location - string - identifier of the location being searched

    entry - map entry - provides access to each stored identifier and Character

    result - vector<Character pointer> - stores pointers returned by at() or all()
*/

/*
 TEST PLAN

 See the assignment journal for the full test plan, which includes the details
 on test plans for the project as a whole, including this file.

 Discussion:

 See the assignment journal for the full reflection journal, including discussion
 of the order of magnitude of this program.
*/

#include "Character.h"
#include "TextUtils.h"

#include <algorithm>
#include <fstream>

bool Characters::load(const std::string& fileName, std::string& errorMessage) {
    std::ifstream input(fileName);
    if (!input) {
        errorMessage = "Unable to open character file: " + fileName;
        return false;
    }

    characters_.clear();
    std::string line;
    int lineNumber = 0;

    while (std::getline(input, line)) {
        ++lineNumber;
        line = TextUtils::trim(line);
        if (line.empty() || line[0] == '#') {
            continue;
        }

        const std::vector<std::string> fields = TextUtils::split(line, '|');
        if (fields.size() != 8) {
            errorMessage = "Invalid character record at line " + std::to_string(lineNumber);
            return false;
        }

        Character character;
        character.id = TextUtils::lowercase(TextUtils::trim(fields[0]));
        character.name = fields[1];
        character.aliases = TextUtils::split(fields[2], ',');
        character.description = fields[3];
        character.location = TextUtils::lowercase(TextUtils::trim(fields[4]));
        character.friendly = TextUtils::lowercase(fields[5]) == "true";
        character.dialogue = fields[6];
        character.encounterText = fields[7];

        for (std::string& alias : character.aliases) {
            alias = TextUtils::normalizeCommand(alias);
        }
        character.aliases.push_back(TextUtils::normalizeCommand(character.name));
        character.aliases.push_back(character.id);
        characters_[character.id] = character;
    }

    return !characters_.empty();
}

bool Characters::matches(const Character& character, const std::string& query) const {
    const std::string normalized = TextUtils::normalizeCommand(query);
    return std::find(character.aliases.begin(), character.aliases.end(), normalized) != character.aliases.end();
}

Character* Characters::findAt(const std::string& query, const std::string& location) {
    for (auto& entry : characters_) {
        if (entry.second.location == location && matches(entry.second, query)) {
            return &entry.second;
        }
    }
    return nullptr;
}

const Character* Characters::findAt(const std::string& query, const std::string& location) const {
    for (const auto& entry : characters_) {
        if (entry.second.location == location && matches(entry.second, query)) {
            return &entry.second;
        }
    }
    return nullptr;
}

std::vector<Character*> Characters::at(const std::string& location) {
    std::vector<Character*> result;
    for (auto& entry : characters_) {
        if (entry.second.location == location) {
            result.push_back(&entry.second);
        }
    }
    return result;
}

std::vector<const Character*> Characters::at(const std::string& location) const {
    std::vector<const Character*> result;
    for (const auto& entry : characters_) {
        if (entry.second.location == location) {
            result.push_back(&entry.second);
        }
    }
    return result;
}

std::vector<Character*> Characters::all() {
    std::vector<Character*> result;
    for (auto& entry : characters_) {
        result.push_back(&entry.second);
    }
    return result;
}

std::vector<const Character*> Characters::all() const {
    std::vector<const Character*> result;
    for (const auto& entry : characters_) {
        result.push_back(&entry.second);
    }
    return result;
}
///:~
