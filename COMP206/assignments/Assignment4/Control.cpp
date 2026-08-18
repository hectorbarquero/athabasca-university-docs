//: Control.cpp, part of COMP206_Assignment4_HectorBarquero_STUDENT_ID.cpp

/*
 Title: COMP206_Assignment4_HectorBarquero_STUDENT_ID.cpp
 Description: Read and interpret player commands for the Wonderland adventure game.
 Date: July 26, 2026
 Author: Hector Barquero
 Version: 1.9
 Copyright: 2026 Hector Barquero
*/

/*
 DOCUMENTATION

 Program Purpose:
    Read text commands entered by the player and convert them into structured
    Command objects that can be processed by the Game class.

    Normalize capitalization and punctuation, recognize abbreviated movement
    commands, match commands against the loaded Actions collection and separate
    action words, objects and targets.

 Compile on macOS with Homebrew GCC:
    g++ -o Wonderland.exe *.cpp

 Execution on macOS:
    ./Wonderland.exe

 Notes:
    The Control constructor initializes aliases for the six movement directions:

        north, south, east, west, up and down

    Each direction also accepts its single-letter abbreviation.

    Commands such as the following are treated as equivalent:

        north
        n
        go north
        Go North!

    Leading prepositions and articles such as "to", "at", "on", "with" and
    "the" are removed from command objects and targets when appropriate.

    The parser supports commands containing both an object and a target:

        throw rock at goblin
        use key on door
        use rope with hook

    If the input stream closes, readCommand() creates a valid quit command so
    that the game can terminate cleanly.

 Classes:
    Command - stores the original input, action, object, target and validity
              state of one interpreted player command

    Control - reads, normalizes and parses player input into Command objects

 Functions:
    Control::Control - stores the Actions collection and initializes movement
                       direction aliases

    Control::readCommand - prompts for player input and passes the entered text
                           to parse()

    Control::removeLeadingPreposition - removes supported leading prepositions
                                        and articles from command text

    Control::parse - normalizes input, identifies the requested action and
                     separates any object and target values

 Variables:
    actions_ - const Actions reference - collection of valid game actions used
               to match player input

    directionAliases_ - map<string, string> - maps full and abbreviated
                        direction commands to standard direction names

    input - string - original text entered by the player

    command - Command - structured result produced from the player input

    words - string array - supported leading words removed from command text

    text - string - text supplied to removeLeadingPreposition()

    result - string - trimmed text after leading words have been removed

    changed - bool - indicates whether another leading word was removed

    word - string - one supported preposition or article

    normalized - string - lowercase and punctuation-normalized player input

    direction - map iterator - result of searching for a direct movement alias

    remainder - string - text remaining after the action name or alias

    action - const Action pointer - matching action returned by Actions::match()

    found - map iterator - result of searching for a direction following go

    atPosition - size_t - position of " at " in a throw command

    onPosition - size_t - position of " on " in a use command

    withPosition - size_t - position of " with " in a use command

    usesOn - bool - indicates whether a use command contains " on "

    splitPosition - size_t - position separating an object from its target

    separatorLength - size_t - number of characters in the selected separator
*/

/*
 TEST PLAN

 See the assignment journal for the full test plan, which includes the details
 on test plans for the project as a whole, including this file.

 Discussion:

 See the assignment journal for the full reflection journal, including discussion
 of the order of magnitude of this program.
*/

#include "Control.h"
#include "Action.h"
#include "TextUtils.h"

#include <iostream>

Control::Control(const Actions& actions) : actions_(actions) {
    directionAliases_ = {
        {"north", "north"}, {"n", "north"},
        {"south", "south"}, {"s", "south"},
        {"east", "east"}, {"e", "east"},
        {"west", "west"}, {"w", "west"},
        {"up", "up"}, {"u", "up"},
        {"down", "down"}, {"d", "down"}
    };
}

Command Control::readCommand() const {
    std::cout << "\n> ";
    std::string input;
    std::getline(std::cin, input);

    if (!std::cin) {
        Command command;
        command.raw = input;
        command.action = "quit";
        command.valid = true;
        return command;
    }

    return parse(input);
}

std::string Control::removeLeadingPreposition(const std::string& text) const {
    static const std::string words[] = {"to ", "at ", "on ", "with ", "the "};
    std::string result = TextUtils::trim(text);

    bool changed = true;
    while (changed) {
        changed = false;
        for (const std::string& word : words) {
            if (result.rfind(word, 0) == 0) {
                result = TextUtils::trim(result.substr(word.size()));
                changed = true;
            }
        }
    }
    return result;
}

Command Control::parse(const std::string& input) const {
    Command command;
    command.raw = input;

    const std::string normalized = TextUtils::normalizeCommand(input);
    if (normalized.empty()) {
        return command;
    }

    const auto direction = directionAliases_.find(normalized);
    if (direction != directionAliases_.end()) {
        command.action = "go";
        command.object = direction->second;
        command.valid = true;
        return command;
    }

    std::string remainder;
    const Action* action = actions_.match(normalized, remainder);
    if (action == nullptr) {
        return command;
    }

    command.action = action->name;
    remainder = removeLeadingPreposition(remainder);

    if (command.action == "go") {
        const auto found = directionAliases_.find(remainder);
        command.object = found == directionAliases_.end() ? remainder : found->second;
    } else if (command.action == "throw") {
        const std::size_t atPosition = remainder.find(" at ");
        if (atPosition == std::string::npos) {
            command.object = remainder;
        } else {
            command.object = TextUtils::trim(remainder.substr(0, atPosition));
            command.target = removeLeadingPreposition(remainder.substr(atPosition + 4));
        }
    } else if (command.action == "use") {
        const std::size_t onPosition = remainder.find(" on ");
        const std::size_t withPosition = remainder.find(" with ");
        const bool usesOn = onPosition != std::string::npos;
        const std::size_t splitPosition = usesOn ? onPosition : withPosition;
        if (splitPosition == std::string::npos) {
            command.object = remainder;
        } else {
            command.object = TextUtils::trim(remainder.substr(0, splitPosition));
            const std::size_t separatorLength = usesOn ? 4 : 6;
            command.target = removeLeadingPreposition(remainder.substr(splitPosition + separatorLength));
        }
    } else {
        command.object = remainder;
    }

    command.valid = true;
    return command;
}
///:~
