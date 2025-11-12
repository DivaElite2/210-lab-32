//Lateefah Camacho
#include <iostream>
#include <deque>
#include "Car.h"
using namespace std;

const int INITIAL_CARS = 2; //const for intitial deque size

class TollBooth {
    private:
//create deque
deque<Car> lane;

public:
   TollBooth() {
  //seed Random number
  srand(time(0));
}
void initializeLine() {
    for(int i = 0; i < INITIAL_CARS; i++) {
        //Create new car 
        Car newCar;
        // add car to back of line
        lane.push_back(neWCar);
    }
    cout << "Initialized with " << INITIAL_CARS << "cars in line "<<endl; 

}

void simulationStep () {
    //Add simulation Generate random number
}

void processCars() {

}

void carArrives() {
    // TODO: Create a new Car using the constructor
    // Add it to the back of the deque

}

void displayLine() {
   // TODO: Iterate through deque and call print() for each car
}

bool hasCars() {

}


};

int main()
{
    /* code */
    return 0;
}

