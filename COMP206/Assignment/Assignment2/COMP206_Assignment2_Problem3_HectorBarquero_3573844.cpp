//: COMP206_Assignment2_Problem3_HectorBarquero_STUDENT_ID.cpp

/*
 Title: COMP206_Assignment2_Problem3_HectorBarquero_STUDENT_ID.cpp
 Description: Model an elevator that validates movement and returns to floor one.
 Date: Jun 28, 2026
 Author: Hector Barquero
 Version: 1.7
 Copyright: 2026 Hector Barquero
*/

/*
 DOCUMENTATION

 Program Purpose:
    Define an Elevator class for an n storey building. The default constructor creates a five storey building. 
    The destructor returns the elevator to the first floor and confirms the termination condition with a msg.

 Compile on macOS with Homebrew GCC:
    g++-16 -std=c++17 -Wall -Wextra -pedantic COMP206_Assignment2_Problem3_HectorBarquero_STUDENT_ID.cpp -o COMP206_Assignment2_Problem3_HectorBarquero_STUDENT_ID

 Execution on macOS:
    ./COMP206_Assignment2_Problem3_HectorBarquero_STUDENT_ID.exe

 Classes:
    Elevator - stores the building height for n and current elevator floor

 Variables:
    totalFloors - int - # of floors in the building
    currentFloor - int - elevator's actual floor
    targetFloor - int - the destination floor
*/

/*
 TEST PLAN

 Scenario 1, default construction:
    Create an elevator with no arg. Verify that it reports five floors and begins on floor one.

 Scenario 2, move upward:
    Create a 10 floor elevator and move from floor one to floor seven.

 Scenario 3, move downward:
    Move the same elevator from before from floor seven to floor three.

 Scenario 4, bad case, invalid destination:
    Request floor 11 in a 10 floor building. Movement is rejected and the elevator remains on the floor stored in memory.

 Scenario 5, dynamic cleanup:
    Create an elevator with unique_ptr, move it to floor six, then call reset(). Verify that the destructor returns it to floor one
    and prints:
    >Elevator ending: elevator returned to the first floor.

 Edge bad case, invalid building size:
    If constucted with a nonvalid int (0), i confirm and verify that >1 and warn user to use one floor.

 Discussion:
    C++ doesn't use .js style garbage collection for local objects. Destruction occurs automatically at the end of scope. 
    unique_ptr::reset() demonstrates explicit destruction of a dynamically allocated elevator.
*/

#include <iostream> 
#include <memory> //ptr again

using namespace std;

class Elevator {
private:
    int totalFloors;
    int currentFloor;

public:
    Elevator()
        : totalFloors(5), currentFloor(1) {
        cout << "Elevator created in a 5 storey building on floor 1.\n";
    }

    explicit Elevator(int numberOfFloors)
        : totalFloors(numberOfFloors), currentFloor(1) {
        if (totalFloors < 1) {
            cout << "Warning: a building must have at least one floor. "
                 << "Using one floor.\n";
            totalFloors = 1;
        }

        cout << "Elevator created in a " << totalFloors
             << " storey building on floor 1.\n";
    }

    ~Elevator() {
        if (currentFloor != 1) {
            cout << "Returning elevator from floor " << currentFloor
                 << " to floor 1.\n";
            currentFloor = 1;
        }

        cout << "Elevator ending: elevator returned to the first floor.\n";
    }

    int getCurrentFloor() const {
        return currentFloor;
    }

    int getTotalFloors() const {
        return totalFloors;
    }

    bool moveTo(int targetFloor) {
        if (targetFloor < 1 || targetFloor > totalFloors) {
            cout << "Cannot move to floor " << targetFloor
                 << ". Valid floors are 1 to " << totalFloors << ".\n";
            return false;
        }

        if (targetFloor == currentFloor) {
            cout << "Elevator is already on floor " << currentFloor << ".\n";
            return true;
        }

        cout << "Elevator moving from floor " << currentFloor
             << " to floor " << targetFloor << ".\n";
        currentFloor = targetFloor;
        return true;
    }
};

int main() {
    cout << "Scenario 1: default five-storey building\n";
    {
        Elevator elevator;
        cout << "Current floor: " << elevator.getCurrentFloor() << "\n\n";
    }

    cout << "\nScenario 2 and 3: upward and downward movement\n";
    {
        Elevator elevator(10);
        elevator.moveTo(7);
        elevator.moveTo(3);
        cout << '\n';
    }

    cout << "\nScenario 4: invalid destination\n";
    {
        Elevator elevator(10);
        elevator.moveTo(11);
        cout << "Current floor remains " << elevator.getCurrentFloor() << ".\n\n";
    }

    cout << "\nScenario 5: repeated destination\n";
    {
        Elevator elevator(8);
        elevator.moveTo(4);
        elevator.moveTo(4);
        cout << '\n';
    }

    cout << "\nScenario 6: dynamic object cleanup with reset()\n";
    {
        unique_ptr<Elevator> elevator = make_unique<Elevator>(12);
        elevator->moveTo(6);
        elevator.reset();
        cout << "Dynamic Elevator has been destroyed.\n\n";
    }

    cout << "\nScenario 7: invalid building size\n";
    {
        Elevator elevator(0);
        cout << "Building floors: " << elevator.getTotalFloors() << '\n';
    }

    return 0;
} ///:~