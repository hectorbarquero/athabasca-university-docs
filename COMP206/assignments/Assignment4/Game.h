//: Game.h part of COMP206_Assignment4_HectorBarquero_STUDENT_ID.cpp and Game.cpp
// See Game.cpp for full documentation

#ifndef GAME_H
#define GAME_H

#include "Action.h"
#include "Character.h"
#include "Control.h"
#include "Inventory.h"
#include "Item.h"
#include "Location.h"

#include <memory>
#include <random>
#include <set>
#include <string>

class Game {
public:
    Game(unsigned int seed, bool encountersEnabled);

    bool load(const std::string& dataDirectory, std::string& errorMessage);
    void run();

private:
    void printIntroduction() const;
    void printHelp() const;
    void describeCurrentLocation(bool forceLongDescription = false);
    void process(const Command& command);

    void move(const std::string& direction);
    void look();
    void showInventory() const;
    void take(const std::string& query);
    void drop(const std::string& query);
    void stash(const std::string& query);
    void use(const std::string& query, const std::string& target);
    void talk(const std::string& query);
    void examine(const std::string& query) const;
    void throwItem(const std::string& itemQuery, const std::string& targetQuery);
    void showScore() const;

    void advanceTurn(bool allowEncounter = true);
    void randomEncounter();
    void finishGame();
    void loseGame(const std::string& reason);

    Item* findInventoryItem(const std::string& query);
    const Item* findInventoryItem(const std::string& query) const;
    std::size_t stashedTreasureCount() const;
    bool currentLocationIsSafe() const;
    void displayVisibleObjects() const;

    Locations locations_;
    Items items_;
    Characters characters_;
    Actions actions_;
    Inventory inventory_;
    std::unique_ptr<Control> control_;

    std::string currentLocationId_;
    int score_;
    int turns_;
    int energy_;
    int courage_;
    int protectedTurns_;
    bool smallEnough_;
    bool croquetPlayed_;
    bool gameOver_;
    bool won_;
    bool encountersEnabled_;
    std::set<std::string> talkedTo_;
    std::mt19937 random_;
};

#endif
///:~
