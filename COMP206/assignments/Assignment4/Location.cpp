//: Location.cpp, part of COMP206_Assignment4_HectorBarquero_STUDENT_ID.cpp

/*
 Title: COMP206_Assignment4_HectorBarquero_STUDENT_ID.cpp
 Description: Load, store and retrieve locations used in the Wonderland adventure game.
 Date: July 26, 2026
 Author: Hector Barquero
 Version: 1.8
 Copyright: 2026 Hector Barquero
*/

/*
 DOCUMENTATION

 Program Purpose:
    Load location definitions from an external text file and store them as
    Location objects indexed by unique location identifiers.

    Provide methods for checking whether a location exists, retrieving locations
    by identifier and returning the identifiers of all loaded locations.

 Compile on macOS with Homebrew GCC:
    g++ -o Wonderland.exe *.cpp

 Execution on macOS:
    ./Wonderland.exe

 Notes:
    Location records are loaded from data/locations.txt.

    Each location record uses the following pipe-separated format:

        id|name|long description|short description|safe|exits

    Blank lines and lines beginning with # are ignored.

    Location identifiers are converted to lowercase. Exit directions are
    normalized using TextUtils, and destination identifiers are converted to
    lowercase.

    Exit records use the following format:

        direction:destination

    Multiple exits are separated by commas:

        north:forest,east:riverbank,down:rabbit_hole

    Loading fails if a location record does not contain six fields or if an exit
    record does not contain both a direction and a destination.

    Locations are stored in an unordered map using their unique identifier as
    the key.

 Classes:
    Location - stores the identifier, name, descriptions, safe-room status,
               visited status and exits for one game location

    Locations - loads, stores and retrieves Location objects

 Functions:
    Locations::load - opens the location data file, validates each record and
                      stores the resulting Location objects

    Locations::contains - determines whether a location identifier exists

    Locations::get - retrieves a location by its unique identifier

    Locations::ids - returns the identifiers of all stored locations

 Variables:
    locations_ - unordered_map<string, Location> - stores locations indexed by
                 their unique identifiers

    fileName - string - path of the location data file to load

    errorMessage - string - receives an explanation when loading fails

    input - ifstream - input stream connected to the location data file

    line - string - stores each line read from the location data file

    lineNumber - int - tracks the current line for validation errors

    fields - vector<string> - stores the six pipe-separated location fields

    location - Location - temporary object created for each valid record

    exitRecord - string - one direction and destination pair from the exit field

    pair - vector<string> - stores the direction and destination of one exit

    id - string - unique identifier used to search for a location

    found - unordered-map iterator - result of searching for a location

    result - vector<string> - stores the identifiers returned by ids()

    entry - map entry - provides access to each stored identifier and Location
*/

/*
 TEST PLAN

 See the assignment journal for the full test plan, which includes the details
 on test plans for the project as a whole, including this file.

 Discussion:

 See the assignment journal for the full reflection journal, including discussion
 of the order of magnitude of this program.
*/

#include "Location.h"
#include "TextUtils.h"

#include <fstream>

bool Locations::load(const std::string& fileName, std::string& errorMessage) {
    std::ifstream input(fileName);
    if (!input) {
        errorMessage = "Unable to open location file: " + fileName;
        return false;
    }

    locations_.clear();
    std::string line;
    int lineNumber = 0;

    while (std::getline(input, line)) {
        ++lineNumber;
        line = TextUtils::trim(line);
        if (line.empty() || line[0] == '#') {
            continue;
        }

        const std::vector<std::string> fields = TextUtils::split(line, '|');
        if (fields.size() != 6) {
            errorMessage = "Invalid location record at line " + std::to_string(lineNumber);
            return false;
        }

        Location location;
        location.id = TextUtils::lowercase(TextUtils::trim(fields[0]));
        location.name = fields[1];
        location.longDescription = fields[2];
        location.shortDescription = fields[3];
        location.safe = TextUtils::lowercase(fields[4]) == "true";

        if (!fields[5].empty()) {
            for (const std::string& exitRecord : TextUtils::split(fields[5], ',')) {
                const std::vector<std::string> pair = TextUtils::split(exitRecord, ':');
                if (pair.size() != 2) {
                    errorMessage = "Invalid exit record at location line " + std::to_string(lineNumber);
                    return false;
                }
                location.exits[TextUtils::normalizeCommand(pair[0])] = TextUtils::lowercase(TextUtils::trim(pair[1]));
            }
        }

        locations_[location.id] = location;
    }

    return !locations_.empty();
}

bool Locations::contains(const std::string& id) const {
    return locations_.find(id) != locations_.end();
}

Location* Locations::get(const std::string& id) {
    const auto found = locations_.find(id);
    return found == locations_.end() ? nullptr : &found->second;
}

const Location* Locations::get(const std::string& id) const {
    const auto found = locations_.find(id);
    return found == locations_.end() ? nullptr : &found->second;
}

std::vector<std::string> Locations::ids() const {
    std::vector<std::string> result;
    for (const auto& entry : locations_) {
        result.push_back(entry.first);
    }
    return result;
}
///:~
