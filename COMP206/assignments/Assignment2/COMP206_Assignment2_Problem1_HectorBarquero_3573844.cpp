//: COMP206_Assignment2_Problem1_HectorBarquero_STUDENT_ID.cpp

/*
 Title: COMP206_Assignment2_Problem1_HectorBarquero_STUDENT_ID.cpp
 Description: Demonstrate inheritance and overridden animal sound methods.
 Date: Jun 28, 2026
 Author: Hector Barquero
 Version: 1.7
 Copyright: 2026 Hector Barquero
*/

/*
 DOCUMENTATION

 Program Purpose:
    Define an Animal base class and Pig, Sheep, Duck and Cow child classes.
    Each child overrides sound(). AnimalTest creates the correct child class from
    a command-line animal name and invokes its sound through an Animal pointer.

 Compile on macOS with Homebrew GCC:
    g++-16 -std=c++17 -Wall -Wextra -pedantic COMP206_Assignment2_Problem1_HectorBarquero_STUDENT_ID.cpp -o COMP206_Assignment2_Problem1_HectorBarquero_STUDENT_ID

 Execution on macOS:
    ./COMP206_Assignment2_Problem1_HectorBarquero_STUDENT_ID.exe
    ./COMP206_Assignment2_Problem1_HectorBarquero_STUDENT_ID.exe pig

 Classes:
    Animal - base class containing sound behaviour
    Pig, Sheep, Duck, Cow - child classes with animal sounds
    AnimalTest - creates animal from a CLI animal name

 Variables:
    animalType - string - animal name supplied on the command line
    animal - unique_ptr<Animal> - owns the selected polymorphic animal
*/

/*
 TEST PLAN

 Normal case 1, lowercase:
    >./COMP206_Assignment2_Problem1_HectorBarquero_STUDENT_ID.exe pig
    >I am an animal
    >I am a pig
    >oink

 Normal case 2, camel case lettering in CLI:
    >./COMP206_Assignment2_Problem1_HectorBarquero_STUDENT_ID.exe CoW // <--- (camel case lettering)
    > ...
    > moo

 Bad Data case 1, unknown animal including integers or wrong type:
    >./COMP206_Assignment2_Problem1_HectorBarquero_STUDENT_ID.exe dog
    >Unknown animal "dog". Use pig, sheep, duck or cow.

 Bad Data case 2, too many args:
    >./COMP206_Assignment2_Problem1_HectorBarquero_STUDENT_ID.exe pig cow
    >Usage: ./COMP206_Assignment2_Problem1_HectorBarquero_STUDENT_ID.exe [pig|sheep|duck|cow]

 Discussion:
    A virtual sound method enables runtime polymorphism. The base constructor runs before each child constructor, 
    so construction of a child prints "I am an animal" and the child-specific constructor msg.
*/

#include <algorithm> // transform: https://cplusplus.com/reference/algorithm/ here -> https://cplusplus.com/reference/algorithm/transform/
#include <cctype>    // tolower which i used in assignment 1
#include <iostream> 
#include <memory>    // make_unique, which creates a unique_ptr: https://en.cppreference.com/cpp/header/memory
#include <string>  

using namespace std;

class Animal {
public:
    Animal() {
        cout << "I am an animal\n";
    }

    virtual ~Animal() = default;

    virtual void sound() const {
        cout << "An animal makes a sound based on the animal that it is.\n";
    }
};

class Pig final : public Animal {
public:
    Pig() {
        cout << "I am a pig\n";
    }

    void sound() const override {
        cout << "oink\n";
    }
};

class Sheep final : public Animal {
public:
    Sheep() {
        cout << "I am a sheep\n";
    }

    void sound() const override {
        cout << "baah\n";
    }
};

class Duck final : public Animal {
public:
    Duck() {
        cout << "I am a duck\n";
    }

    void sound() const override {
        cout << "quack\n";
    }
};

class Cow final : public Animal {
public:
    Cow() {
        cout << "I am a cow\n";
    }

    void sound() const override {
        cout << "moo\n";
    }
};

class AnimalTest {
public:
    static int run(string animalType) {
        transform(animalType.begin(), animalType.end(), animalType.begin(),
                  [](unsigned char character) {
                      return static_cast<char>(tolower(character));
                  });

        unique_ptr<Animal> animal;

        if (animalType == "pig") {
            animal = make_unique<Pig>();
        } else if (animalType == "sheep") {
            animal = make_unique<Sheep>();
        } else if (animalType == "duck") {
            animal = make_unique<Duck>();
        } else if (animalType == "cow") {
            animal = make_unique<Cow>();
        } else {
            cout << "Unknown animal \"" << animalType
                 << "\". Use pig, sheep, duck or cow.\n";
            return 1;
        }

        animal->sound();
        return 0;
    }
};

int main(int argc, char* argv[]) {
    if (argc == 2) {
        return AnimalTest::run(argv[1]);
    }

    if (argc > 2) {
        cout << "Use: " << argv[0] << " [pig|sheep|duck|cow]\n";
        return 1;
    }

    cout << "Animal demonstration\n\n";

    Pig pig1;
    Pig pig2;
    Sheep sheep1;
    Sheep sheep2;
    Duck duck1;
    Duck duck2;
    Cow cow1;
    Cow cow2;

    cout << '\n';
    pig1.sound();
    pig2.sound();
    sheep1.sound();
    sheep2.sound();
    duck1.sound();
    duck2.sound();
    cow1.sound();
    cow2.sound();

    return 0;
} ///:~