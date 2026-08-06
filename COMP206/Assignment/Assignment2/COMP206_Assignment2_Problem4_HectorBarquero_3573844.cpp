//: COMP206_Assignment2_Problem4_HectorBarquero_STUDENT_ID.cpp

/*
 Title: COMP206_Assignment2_Problem4_HectorBarquero_STUDENT_ID.cpp
 Description: Demonstrate a Rodent inheritance hierarchy and refined behaviours.
 Date: Jun 28, 2026
 Author: Hector Barquero
 Version: 1.7
 Copyright: 2026 Hector Barquero
*/

/*
 DOCUMENTATION

 Program Purpose:
    Define a Rodent base class with common eat, sleep, groom and move behaviours. Mouse, Gerbil, Hamster and GuineaPig are 
    child classes which override only behaviours that are meaningfully different for the species.

 Behaviour Notes:
    All rodents eat, sleep, groom and move. The child outputs use simplified, species-specific 
    examples: mice eat seeds and grains; gerbils dig burrows; hamsters carry food in cheek pouches; 
    guinea pigs commonly eat grass or hay.

 Compile on macOS with Homebrew GCC:
    g++-16 -std=c++17 -Wall -Wextra -pedantic COMP206_Assignment2_Problem4_HectorBarquero_STUDENT_ID.cpp -o COMP206_Assignment2_Problem4_HectorBarquero_STUDENT_ID

 Execution on macOS:
    ./COMP206_Assignment2_Problem4_HectorBarquero_STUDENT_ID.exe

 Classes:
    Rodent - base class containing common behaviours
    Mouse, Gerbil, Hamster, GuineaPig - child classes with refined species specific behaviour

 Variables:
    rodents - vector<unique_ptr<Rodent>> - owns one instance of every rodent type
*/

/*
 TEST PLAN

 Normal case 1, Mouse:
    Verify that mouse prints mouse specific eating/movement, but inherits sleep and groom

 Normal case 2, Gerbil:
    Verify that Gerbil prints seed eating and burrow digging movement.

 Normal case 3, Hamster:
    Verify that Hamster prints cheek pouch food storage and nest resting.

 Normal case 4, GuineaPig:
    Verify that GuineaPig prints hay/grass eating and walking/running.

 Polymorphism case:
    Store every child object in a unique_ptr<Rodent> collection and invoke the behaviours through 
    Rodent ptr. Verify that overridden methods run.

 Discussion:
    The virtual destructor permits safe cleanup through base-class pointers. Child classes inherit the generic 
    behaviours that don't need refinement like grooming.
*/

#include <iostream>
#include <memory>   // ptr again
#include <string>   
#include <vector>   // vector dynamic size arrays, encapsulating: https://en.cppreference.com/cpp/container/vector

using namespace std;

class Rodent {
public:
    virtual ~Rodent() = default;

    virtual string type() const {
        return "Rodent";
    }

    virtual void eat() const {
        cout << "rodent eating\n";
    }

    virtual void sleep() const {
        cout << "rodent sleeping in a sheltered resting place\n";
    }

    virtual void groom() const {
        cout << "rodent grooming its fur\n";
    }

    virtual void move() const {
        cout << "rodent moving on four legs\n";
    }

    void demonstrateBehaviours() const {
        cout << type() << " behaviours:\n";
        eat();
        sleep();
        groom();
        move();
        cout << '\n';
    }
};

class Mouse final : public Rodent {
public:
    string type() const override {
        return "Mouse";
    }

    void eat() const override {
        cout << "mouse eating seeds and grains\n";
    }

    void move() const override {
        cout << "mouse scurrying and climbing\n";
    }
};

class Gerbil final : public Rodent {
public:
    string type() const override {
        return "Gerbil";
    }

    void eat() const override {
        cout << "gerbil eating seeds and plant material\n";
    }

    void move() const override {
        cout << "gerbil running and digging a burrow\n";
    }
};

class Hamster final : public Rodent {
public:
    string type() const override {
        return "Hamster";
    }

    void eat() const override {
        cout << "hamster eating and carrying food in its cheek pouches\n";
    }

    void sleep() const override {
        cout << "hamster sleeping in its nest\n";
    }

    void move() const override {
        cout << "hamster running and burrowing\n";
    }
};

class GuineaPig final : public Rodent {
public:
    string type() const override {
        return "Guinea pig";
    }

    void eat() const override {
        cout << "guinea pig eating grass and hay\n";
    }

    void move() const override {
        cout << "guinea pig walking and running close to the ground\n";
    }
};

int main() {
    vector<unique_ptr<Rodent>> rodents;
    rodents.push_back(make_unique<Mouse>());
    rodents.push_back(make_unique<Gerbil>());
    rodents.push_back(make_unique<Hamster>());
    rodents.push_back(make_unique<GuineaPig>());

    for (const unique_ptr<Rodent>& rodent : rodents) {
        rodent->demonstrateBehaviours();
    }

    return 0;
} ///:~