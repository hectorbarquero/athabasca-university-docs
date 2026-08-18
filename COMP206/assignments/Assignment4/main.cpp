//: main.cpp

/*
 Title: Wonderland Adventure Game
 Description: Run an object-oriented text adventure based on Alice's Adventures
              in Wonderland using external files for world and parser data.
 Date: July 26, 2026
 Author: Hector Barquero
 Version: 3.4
 Copyright: 2026 Hector Barquero
*/

/*
 DOCUMENTATION

 Program Purpose:
    Provide a complete text-based adventure game in which Alice explores a
    connected set of Wonderland locations, interacts with items and characters,
    maintains an inventory, survives random encounters, stores treasures in a
    safe room and completes a stated goal.

 Compile on macOS with Homebrew GCC:
    g++ -o Wonderland.exe *.cpp

 Execution from the project directory:
    ./Wonderland.exe

 SEE TEST NOTES IN MY LEARNING JOURNAL FOR RUNNING IT WITH CHEAT CODES / DETERMINISTIC TEST CONDITIONS

 Classes:
    Game       - owns game state and coordinates all components
    Location   - stores one room and its exits
    Locations  - loads and manages all rooms
    Item       - stores one interactive object
    Items      - loads and manages all objects
    Character  - stores one Wonderland character
    Characters - loads and manages all characters
    Action     - stores one valid action and its aliases
    Actions    - loads and manages the valid action vocabulary
    Inventory  - stores carried item identifiers with a fixed capacity
    Control    - reads, normalizes and parses player commands

 External Files:
    data/locations.txt  - names, descriptions, safe-room flag and exits
    data/items.txt      - item names, locations, properties and use text
    data/characters.txt - character descriptions, dialogue and encounters
    data/actions.txt    - command names, aliases and help descriptions

 Command-Line Options:
    --data <directory>  - use a different directory for the four game files
    --seed <number>     - set the random-number seed for repeatable tests
    --no-random         - disable random encounters during deterministic tests
*/

/*
 TEST PLAN

 Normal case 1, parser aliases:
    >GO NORTH
    >north
    >N
    Each form is normalized and processed as the same directional action when
    the direction is available.

 Normal case 2, inventory changes:
    >take bottle
    >inventory
    >drop bottle
    The bottle moves from the room to inventory and then back to the room.

 Normal case 3, safe-room storage:
    Collect the Golden Key, Pocket Watch, Painted Rose and Queen's Tart.
    Return to the Hall of Doors and STASH each treasure.
    The program reports four of four treasures safely stored.

 Normal case 4, winning path:
    After stashing all treasures, use the DRINK ME Bottle and enter DOWN from
    the Hall of Doors. The game enters the Quiet Garden and prints the win and
    final score messages.

 Normal case 5, external data:
    Start the executable from the project directory. Verify that locations,
    items, characters and commands match the four text files rather than being
    defined as descriptive text in main().

 Bad data case 1, unknown command:
    >dance rapidly
    The program reports that it does not understand the command and continues.

 Bad data case 2, invalid movement:
    >up
    The program reports that the player cannot go in that direction.

 Bad data case 3, missing object:
    >take crown
    The program reports that the item is not available in the current room.

 Bad data case 4, inventory capacity:
    Take six items, then attempt to take a seventh.
    The program rejects the item until something is dropped or stashed.

 Bad data case 5, missing data file:
    Rename one required text file and run the program.
    The program prints a specific loading error and exits with a failure code.

 Discussion:
    The parser ignores capitalization and punctuation. It supports action aliases,
    one-letter directions and common command forms. Random encounters are enabled
    in normal play but can be disabled for a repeatable automated test. The final
    door requires all four treasures in the safe room and the small-size state.
*/

#include "Game.h"

#include <cstdlib>
#include <iostream>
#include <random>
#include <string>

int main(int argc, char* argv[]) {
    std::string dataDirectory = "data";
    unsigned int seed = std::random_device{}();
    bool encountersEnabled = true;

    for (int i = 1; i < argc; ++i) {
        const std::string argument = argv[i];
        if (argument == "--data" && i + 1 < argc) {
            dataDirectory = argv[++i];
        } else if (argument == "--seed" && i + 1 < argc) {
            try {
                seed = static_cast<unsigned int>(std::stoul(argv[++i]));
            } catch (...) {
                std::cerr << "Invalid seed value.\n";
                return EXIT_FAILURE;
            }
        } else if (argument == "--no-random") {
            encountersEnabled = false;
        } else {
            std::cerr << "Unknown option: " << argument << '\n';
            return EXIT_FAILURE;
        }
    }

    Game game(seed, encountersEnabled);
    std::string errorMessage;
    if (!game.load(dataDirectory, errorMessage)) {
        std::cerr << "Game data error: " << errorMessage << '\n';
        return EXIT_FAILURE;
    }

    game.run();
    return EXIT_SUCCESS;
} ///:~