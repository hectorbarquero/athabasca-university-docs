//: Game.cpp, part of COMP206_Assignment4_HectorBarquero_STUDENT_ID.cpp

/*
 Title: COMP206_Assignment4_HectorBarquero_STUDENT_ID.cpp
 Description: Control the state, rules and execution of the Wonderland adventure game.
 Date: July 26, 2026
 Author: Hector Barquero
 Version: 2.4
 Copyright: 2026 Hector Barquero
*/

/*
 DOCUMENTATION

 Program Purpose:
    Coordinate the primary execution and game-play rules of Wonderland:
    The Four Lost Treasures.

    Load and validate the external location, item, character and action data.
    Maintain the player's location, inventory, score, energy, courage and
    progress toward the winning condition.

    Receive parsed Command objects from the Control class and execute movement,
    inventory, item, character, scoring and game-state actions.

 Compile on macOS with Homebrew GCC:
    g++ -o Wonderland.exe *.cpp

 Execution on macOS:
    ./Wonderland.exe

 Notes:
    This file contains the main Game class implementation. The program entry
    point is contained in main.cpp.

    The program must be executed from the project directory because it loads
    the following external files:

        data/locations.txt
        data/items.txt
        data/characters.txt
        data/actions.txt

    The player begins at the riverbank with an inventory capacity of six items,
    24 energy points and three courage points.

    Energy decreases by one after every three completed turns. The game ends
    when energy or courage reaches zero.

    The player must collect and stash four treasures in the Hall of Doors:

        Golden Key
        Pocket Watch
        Painted Rose
        Queen's Tart

    The player must also use the DRINK ME bottle before entering the Quiet
    Garden through the tiny door.

    Random encounters normally have a 14 percent chance of occurring after an
    eligible turn. Carrying the tart increases the chance that the encountered
    character will be the Queen of Hearts.

    The constructor accepts a random-number seed and an option to disable
    encounters. This permits repeatable automated testing.

 Classes:
    Game - loads the game world, maintains game state, processes player actions
           and determines winning or losing outcomes

 Functions:
    Game::Game - initializes the inventory, starting location, player statistics,
                 game flags and random-number generator

    Game::load - loads the four external data files and validates all location,
                 item, character and exit references

    Game::run - displays the introduction and repeatedly reads and processes
                commands until the game is won or ended

    Game::printIntroduction - displays the game title, goal and basic command
                              instructions

    Game::printHelp - displays all loaded actions and movement aliases

    Game::describeCurrentLocation - displays the long or short description of
                                    the current location

    Game::displayVisibleObjects - displays visible items, stashed items,
                                  characters and exits

    Game::process - dispatches a parsed command to the appropriate game method

    Game::move - validates an exit, changes location and checks the final-door
                 requirements

    Game::look - redisplays the complete current-location description

    Game::showInventory - displays carried items and inventory capacity

    Game::findInventoryItem - finds an item currently carried by the player

    Game::take - transfers an available item into the player's inventory

    Game::drop - removes an item from inventory and places it in the current
                 location

    Game::stash - transfers an inventory item into the Hall of Doors safe-room
                  stash

    Game::use - applies the behaviour associated with a carried item

    Game::talk - displays character dialogue and processes friendly or hostile
                 character interaction

    Game::examine - displays the description of a visible item or character

    Game::throwItem - throws a carried item at a present character and randomly
                      determines the outcome

    Game::showScore - displays score, turns, energy, courage and treasure count

    Game::advanceTurn - increments the turn counter, updates energy and item
                        protection, and optionally checks for a random encounter

    Game::randomEncounter - selects and processes a random character encounter

    Game::finishGame - applies the victory bonus and displays the winning result

    Game::loseGame - ends the game and displays the reason and final score

    Game::stashedTreasureCount - counts treasures stored in the safe-room stash

    Game::currentLocationIsSafe - determines whether the current location is
                                  marked as a safe room

 Constants:
    REQUIRED_TREASURES - size_t - number of treasures required to unlock the
                         final door

    MAX_ENERGY - int - maximum energy value the player can hold

    MAX_COURAGE - int - maximum courage value the player can hold

 Variables:
    locations_ - Locations - stores all loaded game locations and exits

    items_ - Items - stores all loaded game items and their current locations

    characters_ - Characters - stores all loaded characters and their locations

    actions_ - Actions - stores the valid player actions and command aliases

    inventory_ - Inventory - stores identifiers for items carried by the player

    control_ - unique_ptr<Control> - reads and parses player commands

    currentLocationId_ - string - identifier of the player's current location

    score_ - int - accumulated player score

    turns_ - int - number of completed game turns

    energy_ - int - remaining player energy

    courage_ - int - remaining player courage

    protectedTurns_ - int - number of turns remaining for temporary protection

    smallEnough_ - bool - indicates whether the player can pass through the
                          tiny final door

    croquetPlayed_ - bool - indicates whether the croquet scoring event has
                            already been completed

    gameOver_ - bool - indicates that the game has ended without a win

    won_ - bool - indicates that the winning condition has been completed

    encountersEnabled_ - bool - controls whether random encounters may occur

    random_ - random-number generator - produces encounter and thrown-item
              outcomes

    talkedTo_ - set<string> - records characters already counted for dialogue
                scoring

    seed - unsigned int - seed supplied to the random-number generator

    encountersEnabled - bool - constructor option controlling random encounters

    dataDirectory - string - directory containing the external game data files

    errorMessage - string - receives an explanation when loading or validation
                   fails

    command - Command - parsed player instruction processed by the Game class

    direction - string - requested movement direction

    query - string - item or character name supplied by the player

    target - string - target supplied for a use or throw command

    item - Item pointer - selected item involved in a game action

    character - Character pointer - selected character involved in an action
*/

/*
 TEST PLAN

 See the assignment journal for the full test plan, which includes the details
 on test plans for the project as a whole, including this file.

 Discussion:

 See the assignment journal for the full reflection journal, including discussion
 of the order of magnitude of this program.
*/

#include "Game.h"
#include "TextUtils.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

namespace {
const std::size_t REQUIRED_TREASURES = 4;
const int MAX_ENERGY = 30;
const int MAX_COURAGE = 3;
}

Game::Game(unsigned int seed, bool encountersEnabled)
    : inventory_(6),
      currentLocationId_("riverbank"),
      score_(0),
      turns_(0),
      energy_(24),
      courage_(MAX_COURAGE),
      protectedTurns_(0),
      smallEnough_(false),
      croquetPlayed_(false),
      gameOver_(false),
      won_(false),
      encountersEnabled_(encountersEnabled),
      random_(seed) {
}

bool Game::load(const std::string& dataDirectory, std::string& errorMessage) {
    const std::string separator = dataDirectory.empty() || dataDirectory.back() == '/'
                                      ? ""
                                      : "/";

    if (!locations_.load(dataDirectory + separator + "locations.txt", errorMessage) ||
        !items_.load(dataDirectory + separator + "items.txt", errorMessage) ||
        !characters_.load(dataDirectory + separator + "characters.txt", errorMessage) ||
        !actions_.load(dataDirectory + separator + "actions.txt", errorMessage)) {
        return false;
    }

    if (!locations_.contains(currentLocationId_)) {
        errorMessage = "Starting location 'riverbank' is missing from locations.txt.";
        return false;
    }

    for (const Item* item : items_.all()) {
        if (item->location != "inventory" && item->location != "stash" &&
            item->location != "consumed" && !locations_.contains(item->location)) {
            errorMessage = "Item '" + item->id + "' refers to an unknown location.";
            return false;
        }
    }

    for (const Character* character : characters_.all()) {
        if (!locations_.contains(character->location)) {
            errorMessage = "Character '" + character->id + "' refers to an unknown location.";
            return false;
        }
    }

    for (const std::string& id : locations_.ids()) {
        const Location* location = locations_.get(id);
        for (const auto& exit : location->exits) {
            if (!locations_.contains(exit.second)) {
                errorMessage = "Location '" + id + "' has an exit to unknown location '" +
                               exit.second + "'.";
                return false;
            }
        }
    }

    control_ = std::make_unique<Control>(actions_);
    return true;
}

void Game::run() {
    printIntroduction();
    describeCurrentLocation(true);

    while (!gameOver_ && !won_) {
        const Command command = control_->readCommand();
        process(command);
    }
}

void Game::printIntroduction() const {
    std::cout
        << "WONDERLAND: THE FOUR LOST TREASURES\n"
        << "===================================\n"
        << "You are Alice, standing beside a quiet riverbank. The White Rabbit has\n"
        << "scattered four valuable objects through Wonderland: the Golden Key,\n"
        << "Pocket Watch, Painted Rose and Queen's Tart. Find all four, return them\n"
        << "to the Hall of Doors safe room, become small enough for the tiny door,\n"
        << "and escape into the Quiet Garden.\n\n"
        << "Type HELP for commands. Direction commands may be written as GO NORTH,\n"
        << "NORTH or N. Capitalization and punctuation are ignored.\n";
}

void Game::printHelp() const {
    std::cout << "\nAvailable commands:\n";
    for (const Action& action : actions_.all()) {
        std::cout << "  " << std::left << std::setw(10) << action.name
                  << action.description << '\n';
    }
    std::cout << "  Directions: north/n, south/s, east/e, west/w, up/u, down/d\n";
}

void Game::describeCurrentLocation(bool forceLongDescription) {
    Location* location = locations_.get(currentLocationId_);
    if (location == nullptr) {
        loseGame("The world map has become inconsistent.");
        return;
    }

    std::cout << "\n" << location->name << "\n";
    std::cout << std::string(location->name.size(), '-') << "\n";

    if (forceLongDescription || !location->visited) {
        std::cout << location->longDescription << "\n";
        if (!location->visited) {
            score_ += 2;
        }
    } else {
        std::cout << location->shortDescription << "\n";
    }

    location->visited = true;
    displayVisibleObjects();
}

void Game::displayVisibleObjects() const {
    const std::vector<const Item*> visibleItems = items_.at(currentLocationId_);
    if (!visibleItems.empty()) {
        std::vector<std::string> names;
        for (const Item* item : visibleItems) {
            names.push_back(item->name);
        }
        std::cout << "Items here: " << TextUtils::join(names, ", ") << ".\n";
    }

    const Location* location = locations_.get(currentLocationId_);
    if (location != nullptr && location->safe) {
        const std::vector<const Item*> stashedItems = items_.at("stash");
        if (!stashedItems.empty()) {
            std::vector<std::string> names;
            for (const Item* item : stashedItems) {
                names.push_back(item->name);
            }
            std::cout << "Safe-room stash: " << TextUtils::join(names, ", ") << ".\n";
        }
    }

    const std::vector<const Character*> visibleCharacters = characters_.at(currentLocationId_);
    if (!visibleCharacters.empty()) {
        std::vector<std::string> names;
        for (const Character* character : visibleCharacters) {
            names.push_back(character->name);
        }
        std::cout << "Characters here: " << TextUtils::join(names, ", ") << ".\n";
    }

    if (location != nullptr && !location->exits.empty()) {
        std::vector<std::string> directions;
        for (const auto& exit : location->exits) {
            directions.push_back(exit.first);
        }
        std::cout << "Exits: " << TextUtils::join(directions, ", ") << ".\n";
    }
}

void Game::process(const Command& command) {
    if (!command.valid) {
        std::cout << "I do not understand that command. Type HELP for valid actions.\n";
        return;
    }

    if (command.action == "go") {
        move(command.object);
    } else if (command.action == "look") {
        look();
    } else if (command.action == "inventory") {
        showInventory();
    } else if (command.action == "take") {
        take(command.object);
    } else if (command.action == "drop") {
        drop(command.object);
    } else if (command.action == "stash") {
        stash(command.object);
    } else if (command.action == "use") {
        use(command.object, command.target);
    } else if (command.action == "talk") {
        talk(command.object);
    } else if (command.action == "examine") {
        examine(command.object);
    } else if (command.action == "throw") {
        throwItem(command.object, command.target);
    } else if (command.action == "score") {
        showScore();
    } else if (command.action == "help") {
        printHelp();
    } else if (command.action == "quit") {
        gameOver_ = true;
        std::cout << "You leave Wonderland with a score of " << score_ << ".\n";
    } else {
        std::cout << "That action is loaded but has no game behaviour.\n";
    }
}

void Game::move(const std::string& direction) {
    if (direction.empty()) {
        std::cout << "Go where?\n";
        return;
    }

    Location* current = locations_.get(currentLocationId_);
    const auto exit = current->exits.find(direction);
    if (exit == current->exits.end()) {
        std::cout << "You cannot go in that direction.\n";
        return;
    }

    if (currentLocationId_ == "hall_of_doors" && direction == "down") {
        if (stashedTreasureCount() < REQUIRED_TREASURES) {
            std::cout << "The tiny door remains locked. Four treasures must be safe in the hall.\n";
            return;
        }
        if (!smallEnough_) {
            std::cout << "The door is open, but you are too large. The DRINK ME bottle may help.\n";
            return;
        }
    }

    currentLocationId_ = exit->second;
    advanceTurn(true);
    if (gameOver_) {
        return;
    }

    describeCurrentLocation(false);
    if (currentLocationId_ == "quiet_garden") {
        finishGame();
    }
}

void Game::look() {
    describeCurrentLocation(true);
}

void Game::showInventory() const {
    std::cout << inventory_.description(items_) << " (" << inventory_.size() << "/"
              << inventory_.capacity() << " slots used)\n";
}

Item* Game::findInventoryItem(const std::string& query) {
    return items_.findAt(query, {"inventory"});
}

const Item* Game::findInventoryItem(const std::string& query) const {
    return items_.findAt(query, {"inventory"});
}

void Game::take(const std::string& query) {
    if (query.empty()) {
        std::cout << "Take what?\n";
        return;
    }

    std::vector<std::string> locations = {currentLocationId_};
    if (currentLocationIsSafe()) {
        locations.push_back("stash");
    }

    Item* item = items_.findAt(query, locations);
    if (item == nullptr) {
        std::cout << "That item is not available here.\n";
        return;
    }
    if (!item->takeable) {
        std::cout << "You cannot carry " << item->name << ".\n";
        return;
    }
    if (inventory_.full()) {
        std::cout << "Your inventory is full. Drop or stash something first.\n";
        return;
    }

    inventory_.add(item->id);
    item->location = "inventory";
    std::cout << "Taken: " << item->name << ".\n";

    if (!item->treasure && !item->scored && item->points > 0) {
        score_ += item->points;
        item->scored = true;
    }

    advanceTurn(true);
}

void Game::drop(const std::string& query) {
    Item* item = findInventoryItem(query);
    if (item == nullptr) {
        std::cout << "You are not carrying that item.\n";
        return;
    }

    inventory_.remove(item->id);
    item->location = currentLocationId_;
    std::cout << "Dropped: " << item->name << ".\n";
    advanceTurn(true);
}

void Game::stash(const std::string& query) {
    if (!currentLocationIsSafe()) {
        std::cout << "Items can only be stashed safely in the Hall of Doors.\n";
        return;
    }

    Item* item = findInventoryItem(query);
    if (item == nullptr) {
        std::cout << "You are not carrying that item.\n";
        return;
    }

    inventory_.remove(item->id);
    item->location = "stash";
    std::cout << "Stashed safely: " << item->name << ".\n";

    if (item->treasure && !item->scored) {
        score_ += item->points;
        item->scored = true;
    }

    if (stashedTreasureCount() == REQUIRED_TREASURES) {
        std::cout << "All four treasures are safe. The tiny door clicks open.\n";
    }

    advanceTurn(false);
}

void Game::use(const std::string& query, const std::string& target) {
    Item* item = findInventoryItem(query);
    if (item == nullptr) {
        std::cout << "You must be carrying an item before you can use it.\n";
        return;
    }

    if (item->id == "drink_me_bottle") {
        if (item->used) {
            std::cout << "The bottle is empty.\n";
            return;
        }
        smallEnough_ = true;
        energy_ = std::min(MAX_ENERGY, energy_ + 1);
        item->used = true;
        inventory_.remove(item->id);
        item->location = "consumed";
    } else if (item->id == "eat_me_cake") {
        if (item->used) {
            std::cout << "Only crumbs remain.\n";
            return;
        }
        smallEnough_ = false;
        energy_ = std::min(MAX_ENERGY, energy_ + 5);
        item->used = true;
        inventory_.remove(item->id);
        item->location = "consumed";
    } else if (item->id == "mushroom_piece") {
        if (item->used) {
            std::cout << "The mushroom piece has already been eaten.\n";
            return;
        }
        smallEnough_ = false;
        energy_ = std::min(MAX_ENERGY, energy_ + 3);
        item->used = true;
        inventory_.remove(item->id);
        item->location = "consumed";
    } else if (item->id == "bread_and_butter" || item->id == "comfit_box") {
        if (item->used) {
            std::cout << "There is nothing left to eat.\n";
            return;
        }
        energy_ = std::min(MAX_ENERGY, energy_ + 4);
        item->used = true;
        inventory_.remove(item->id);
        item->location = "consumed";
    } else if (item->id == "tea_cup") {
        energy_ = std::min(MAX_ENERGY, energy_ + 2);
    } else if (item->id == "white_rabbit_fan" || item->id == "painted_rose") {
        protectedTurns_ = 4;
        courage_ = std::min(MAX_COURAGE, courage_ + 1);
    } else if (item->id == "pocket_watch") {
        std::cout << "The watch insists that Wonderland time is turn " << turns_ << ".\n";
    } else if ((item->id == "flamingo" || item->id == "croquet_ball") &&
               currentLocationId_ == "queen_garden") {
        const std::string otherId = item->id == "flamingo" ? "croquet_ball" : "flamingo";
        if (inventory_.contains(otherId) && !croquetPlayed_) {
            croquetPlayed_ = true;
            score_ += 10;
            std::cout << "You complete a difficult croquet turn and earn 10 points.\n";
        } else if (!inventory_.contains(otherId)) {
            std::cout << "Croquet requires both the flamingo and the hedgehog ball.\n";
        }
    } else if (item->id == "tart") {
        std::cout << "The tart is evidence and one of the required treasures. You leave it intact.\n";
    } else if (!target.empty()) {
        std::cout << "Using " << item->name << " on " << target << " changes nothing.\n";
    }

    std::cout << item->useText << "\n";
    advanceTurn(true);
}

void Game::talk(const std::string& query) {
    std::vector<Character*> present = characters_.at(currentLocationId_);
    Character* character = nullptr;

    if (query.empty() && present.size() == 1) {
        character = present.front();
    } else {
        character = characters_.findAt(query, currentLocationId_);
    }

    if (character == nullptr) {
        std::cout << "That character is not here.\n";
        return;
    }

    std::cout << character->name << ": " << character->dialogue << "\n";
    if (talkedTo_.insert(character->id).second) {
        score_ += character->friendly ? 2 : 1;
    }

    if (!character->friendly && protectedTurns_ == 0) {
        --courage_;
        std::cout << "The encounter costs one courage point.\n";
        if (courage_ <= 0) {
            loseGame("The Queen's threats drive you from the adventure.");
            return;
        }
    }

    advanceTurn(true);
}

void Game::examine(const std::string& query) const {
    if (query.empty()) {
        std::cout << "Examine what?\n";
        return;
    }

    std::vector<std::string> itemLocations = {currentLocationId_, "inventory"};
    if (currentLocationIsSafe()) {
        itemLocations.push_back("stash");
    }

    const Item* item = items_.findAt(query, itemLocations);
    if (item != nullptr) {
        std::cout << item->description << "\n";
        return;
    }

    const Character* character = characters_.findAt(query, currentLocationId_);
    if (character != nullptr) {
        std::cout << character->description << "\n";
        return;
    }

    std::cout << "You see nothing matching that description.\n";
}

void Game::throwItem(const std::string& itemQuery, const std::string& targetQuery) {
    Item* item = findInventoryItem(itemQuery);
    if (item == nullptr) {
        std::cout << "You are not carrying that item.\n";
        return;
    }
    if (targetQuery.empty()) {
        std::cout << "Throw it at whom?\n";
        return;
    }

    Character* target = characters_.findAt(targetQuery, currentLocationId_);
    if (target == nullptr) {
        std::cout << "That character is not here.\n";
        return;
    }

    std::uniform_int_distribution<int> outcome(0, 1);
    if (outcome(random_) == 0) {
        std::cout << target->name << " ducks, and " << item->name << " lands nearby.\n";
    } else {
        std::cout << item->name << " bumps harmlessly against " << target->name
                  << ", who looks offended.\n";
    }

    inventory_.remove(item->id);
    item->location = currentLocationId_;

    if (!target->friendly && protectedTurns_ == 0) {
        --courage_;
        std::cout << "The hostile response costs one courage point.\n";
        if (courage_ <= 0) {
            loseGame("The confrontation ends your attempt to recover the treasures.");
            return;
        }
    }

    advanceTurn(true);
}

void Game::showScore() const {
    std::cout << "Score: " << score_ << " | Turns: " << turns_
              << " | Energy: " << energy_ << " | Courage: " << courage_
              << " | Treasures safely stashed: " << stashedTreasureCount()
              << "/" << REQUIRED_TREASURES << "\n";
}

void Game::advanceTurn(bool allowEncounter) {
    ++turns_;
    if (turns_ % 3 == 0) {
        --energy_;
    }
    if (protectedTurns_ > 0) {
        --protectedTurns_;
    }

    if (energy_ <= 0) {
        loseGame("You become too exhausted to continue through Wonderland.");
        return;
    }

    if (allowEncounter && encountersEnabled_) {
        randomEncounter();
    }
}

void Game::randomEncounter() {
    std::uniform_int_distribution<int> chance(1, 100);
    if (chance(random_) > 14) {
        return;
    }

    std::vector<Character*> possible = characters_.all();
    if (possible.empty()) {
        return;
    }

    Character* encountered = nullptr;
    const Item* tart = items_.get("tart");
    if (tart != nullptr && tart->location == "inventory" && chance(random_) <= 45) {
        for (Character* character : possible) {
            if (character->id == "queen_of_hearts") {
                encountered = character;
                break;
            }
        }
    }

    if (encountered == nullptr) {
        std::uniform_int_distribution<std::size_t> selection(0, possible.size() - 1);
        encountered = possible[selection(random_)];
    }

    std::cout << "\nRandom encounter: " << encountered->encounterText << "\n";
    if (!encountered->friendly) {
        if (protectedTurns_ > 0) {
            std::cout << "Your protective item helps you pass without trouble.\n";
            return;
        }

        std::uniform_int_distribution<int> response(0, 1);
        if (response(random_) == 0) {
            std::cout << "You remain calm and the encounter passes.\n";
        } else {
            --courage_;
            std::cout << "You lose one courage point.\n";
            if (courage_ <= 0) {
                loseGame("Too many hostile encounters force you to abandon the search.");
            }
        }
    }
}

void Game::finishGame() {
    won_ = true;
    score_ += 20 + energy_ + courage_ * 5;
    std::cout
        << "\nYou step through the tiny door into a quiet garden inside Wonderland.\n"
        << "All four treasures remain safely stored in the Hall of Doors. You win.\n"
        << "Final score: " << score_ << " in " << turns_ << " turns.\n";
}

void Game::loseGame(const std::string& reason) {
    gameOver_ = true;
    std::cout << "\n" << reason << "\nGame over. Final score: " << score_ << ".\n";
}

std::size_t Game::stashedTreasureCount() const {
    std::size_t count = 0;
    for (const Item* item : items_.at("stash")) {
        if (item->treasure) {
            ++count;
        }
    }
    return count;
}

bool Game::currentLocationIsSafe() const {
    const Location* location = locations_.get(currentLocationId_);
    return location != nullptr && location->safe;
}
///:~