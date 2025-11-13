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
        lane.push_back(newCar);
    }
    cout << "Initialized with " << INITIAL_CARS << "cars in line "<<endl; 

}

void simulationStep () {
    //Add simulation Generate random number
    int randomEvent = rand() % 100 + 1;

    if(randomEvent <= 55) { //55% probability
        processCar();
    }else {
        carArrives(); // 45% probability
    }
    displayLine();
}


// process from front
void processCar() {
    if(lane.empty())  return;

        cout << "Car pays tolls" <<endl;
        lane.front().print();// call print on the first car
        lane.pop_front();
      
    
    cout << "processing car" <<endl;

}

void carArrives() {
// TODO: Create a new Car using the constructor
    Car newCar;
    // Add it to the back of the deque
          lane.push_back(newCar);
          cout <<"new car arrives" <<endl;
          newCar.print();
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

