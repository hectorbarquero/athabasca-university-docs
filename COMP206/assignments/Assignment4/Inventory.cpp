//: Inventory.cpp, part of COMP206_Assignment4_HectorBarquero_STUDENT_ID.cpp

/*
 Title: COMP206_Assignment4_HectorBarquero_STUDENT_ID.cpp
 Description: Manage the player's carried items in the Wonderland adventure game.
 Date: July 26, 2026
 Author: Hector Barquero
 Version: 1.6
 Copyright: 2026 Hector Barquero
*/

/*
 DOCUMENTATION

 Program Purpose:
    Store and manage the identifiers of items carried by the player.

    Enforce the inventory capacity, prevent duplicate items, add and remove item
    identifiers, report the current inventory state and generate a readable
    description of the items being carried.

 Compile on macOS with Homebrew GCC:
    g++ -o Wonderland.exe *.cpp

 Execution on macOS:
    ./Wonderland.exe

 Notes:
    The Inventory class stores item identifiers rather than complete Item
    objects. Item details are retrieved from the Items collection when a
    readable inventory description is required.

    The inventory capacity is supplied to the constructor. In the current game,
    the Game class creates an inventory with a capacity of six items.

    An item cannot be added if the inventory is full or if the same item
    identifier is already present.

    Removing an item affects only the inventory's list of identifiers. The Game
    class is responsible for updating the corresponding Item object's location.

 Classes:
    Inventory - stores and manages identifiers for items carried by the player

 Functions:
    Inventory::Inventory - initializes the maximum inventory capacity

    Inventory::add - adds an item identifier if capacity is available and the
                     item is not already present

    Inventory::remove - removes an item identifier from the inventory

    Inventory::contains - determines whether an item identifier is currently
                          stored in the inventory

    Inventory::full - determines whether the inventory has reached its capacity

    Inventory::empty - determines whether the inventory contains no items

    Inventory::size - returns the number of item identifiers currently stored

    Inventory::capacity - returns the maximum number of items that may be stored

    Inventory::itemIds - returns a constant reference to the stored item
                         identifier collection

    Inventory::description - converts stored item identifiers into item names
                             and returns a readable inventory description

 Variables:
    capacity_ - size_t - maximum number of items that may be carried

    itemIds_ - vector<string> - identifiers of all items currently carried

    capacity - size_t - maximum capacity supplied to the constructor

    itemId - string - identifier of an item being added, removed or searched for

    found - vector iterator - position of a matching item identifier

    items - const Items reference - item collection used to obtain item names

    names - vector<string> - readable names of carried items

    id - string - one item identifier stored in the inventory

    item - const Item pointer - item object matching a stored identifier
*/

/*
 TEST PLAN

 See the assignment journal for the full test plan, which includes the details
 on test plans for the project as a whole, including this file.

 Discussion:

 See the assignment journal for the full reflection journal, including discussion
 of the order of magnitude of this program.
*/

#include "Inventory.h"
#include "Item.h"
#include "TextUtils.h"

#include <algorithm>

Inventory::Inventory(std::size_t capacity) : capacity_(capacity) {
}

bool Inventory::add(const std::string& itemId) {
    if (full() || contains(itemId)) {
        return false;
    }
    itemIds_.push_back(itemId);
    return true;
}

bool Inventory::remove(const std::string& itemId) {
    const auto found = std::find(itemIds_.begin(), itemIds_.end(), itemId);
    if (found == itemIds_.end()) {
        return false;
    }
    itemIds_.erase(found);
    return true;
}

bool Inventory::contains(const std::string& itemId) const {
    return std::find(itemIds_.begin(), itemIds_.end(), itemId) != itemIds_.end();
}

bool Inventory::full() const {
    return itemIds_.size() >= capacity_;
}

bool Inventory::empty() const {
    return itemIds_.empty();
}

std::size_t Inventory::size() const {
    return itemIds_.size();
}

std::size_t Inventory::capacity() const {
    return capacity_;
}

const std::vector<std::string>& Inventory::itemIds() const {
    return itemIds_;
}

std::string Inventory::description(const Items& items) const {
    if (itemIds_.empty()) {
        return "You are carrying nothing.";
    }

    std::vector<std::string> names;
    for (const std::string& id : itemIds_) {
        const Item* item = items.get(id);
        names.push_back(item == nullptr ? id : item->name);
    }

    return "You are carrying " + TextUtils::join(names, ", ") + ".";
}
///:~