//: Action.cpp, part of COMP206_Assignment4_HectorBarquero_STUDENT_ID.cpp

/*
 Title: COMP206_Assignment4_HectorBarquero_STUDENT_ID.cpp
 Description: Load and match the valid actions used by the Wonderland adventure game.
 Date: July 26, 2026
 Author: Hector Barquero
 Version: 1.4
 Copyright: 2026 Hector Barquero
*/

/*
 DOCUMENTATION

 Program Purpose:
    Load action definitions from an external text file and store them as Action
    objects. Each action contains a standard name, a collection of command
    aliases and a description.

    Match normalized player commands against the available action names and
    aliases. When an action is found, return the matching Action object and
    separate any remaining command text for later processing by the Control
    and Game classes.

 Compile on macOS with Homebrew GCC:
    g++ -o Wonderland.exe *.cpp

 Execution on macOS:
    ./Wonderland.exe

 Notes:
    Action records are loaded from data/actions.txt.

    Each action record uses the following pipe-separated format:

        action name|alias1,alias2,alias3|description

    Blank lines and lines beginning with # are ignored.

    Action names and aliases are normalized using TextUtils so that player
    commands are not affected by capitalization or punctuation.

    The match function selects the longest valid alias at the beginning of a
    command. This prevents a shorter alias from being selected when a longer,
    more specific command also matches.

 Classes:
    Action - stores the name, aliases and description of one game action

    Actions - loads, stores and searches the collection of valid actions

 Functions:
    Actions::load - opens the action data file, validates each record and stores
                    the resulting Action objects

    Actions::all - returns a constant reference to the complete action collection

    Actions::match - finds the best action matching a command and returns any
                     remaining command text separately

 Variables:
    actions_ - vector<Action> - stores all actions loaded from the action file

    fileName - string - path of the action data file to load

    errorMessage - string - receives an explanation when loading fails

    input - ifstream - input stream connected to the action data file

    line - string - stores each line read from the action data file

    lineNumber - int - tracks the current file line for validation errors

    fields - vector<string> - stores the three pipe-separated action fields

    action - Action - temporary object created for each valid record

    alias - string - reference used to normalize each action alias

    command - string - normalized player command being matched

    remainder - string - command text remaining after the matched action

    bestAction - const Action pointer - points to the strongest matching action

    bestAlias - string - stores the longest alias matched so far
*/

/*
 TEST PLAN

 See the assignment journal for the full test plan, which includes the details
 on test plans for the project as a whole, including this file.

 Discussion:

 See the assignment journal for the full reflection journal, including discussion
 of the order of magnitude of this program.
*/

#include "Action.h"
#include "TextUtils.h"

#include <fstream>

bool Actions::load(const std::string& fileName, std::string& errorMessage) {
    std::ifstream input(fileName);
    if (!input) {
        errorMessage = "Unable to open action file: " + fileName;
        return false;
    }

    actions_.clear();
    std::string line;
    int lineNumber = 0;

    while (std::getline(input, line)) {
        ++lineNumber;
        line = TextUtils::trim(line);
        if (line.empty() || line[0] == '#') {
            continue;
        }

        const std::vector<std::string> fields = TextUtils::split(line, '|');
        if (fields.size() != 3) {
            errorMessage = "Invalid action record at line " + std::to_string(lineNumber);
            return false;
        }

        Action action;
        action.name = TextUtils::normalizeCommand(fields[0]);
        action.aliases = TextUtils::split(fields[1], ',');
        action.description = fields[2];

        for (std::string& alias : action.aliases) {
            alias = TextUtils::normalizeCommand(alias);
        }
        action.aliases.push_back(action.name);
        actions_.push_back(action);
    }

    return true;
}

const std::vector<Action>& Actions::all() const {
    return actions_;
}

const Action* Actions::match(const std::string& command, std::string& remainder) const {
    const Action* bestAction = nullptr;
    std::string bestAlias;

    for (const Action& action : actions_) {
        for (const std::string& alias : action.aliases) {
            if (!alias.empty() && TextUtils::startsWithPhrase(command, alias) && alias.size() > bestAlias.size()) {
                bestAction = &action;
                bestAlias = alias;
            }
        }
    }

    if (bestAction == nullptr) {
        remainder.clear();
        return nullptr;
    }

    if (command.size() == bestAlias.size()) {
        remainder.clear();
    } else {
        remainder = TextUtils::trim(command.substr(bestAlias.size()));
    }

    return bestAction;
}
///:~