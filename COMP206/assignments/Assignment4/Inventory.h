//: Inventory.h part of COMP206_Assignment4_HectorBarquero_STUDENT_ID.cpp and Inventory.cpp
// See Inventory.cpp for full documentation

#ifndef INVENTORY_H
#define INVENTORY_H

#include <cstddef>
#include <string>
#include <vector>

class Items;

class Inventory {
public:
    explicit Inventory(std::size_t capacity = 6);

    bool add(const std::string& itemId);
    bool remove(const std::string& itemId);
    bool contains(const std::string& itemId) const;
    bool full() const;
    bool empty() const;
    std::size_t size() const;
    std::size_t capacity() const;
    const std::vector<std::string>& itemIds() const;
    std::string description(const Items& items) const;

private:
    std::size_t capacity_;
    std::vector<std::string> itemIds_;
};

#endif
///:~
