//Lateefah Camacho
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <deque>
#include "Car.h"
using namespace std;

const int INITIAL_CARS = 2; //const for intitial deque size
const int NR_LANES = 4; // LANES 4

class TollBooth {
    private:
//create deque
deque<Car> lanes[NR_LANES];

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
   cout <<"Current Line (" << lane.size() << "cars): ";
   for(auto& car : lane) {
       car.print();
   }
}

bool hasCars() {
   return !lane.empty();
}

void switchlanes() {
    //check for lanes with cars
    bool canSwitch = false;
    for(int i = 0; i < NR_LANES; i++) {
        if(lanes[i].size() > 0) {
            canSwitch = true;
            break;
        }
    }
    if(!canSwitch) {
        return; // no cars in any lane cant switch
    }
    //Random lane that has cars
    int sourceLane;
    do {
        sourceLane = rand() % NR_LANES; //random lane 0-3
    } while(lanes[sourceLane].empty());
    
        
    //Random lane that is different form source
    int destLane;
    do{
        destLane = rand() % NR_LANES;
    }while (destLane == sourceLane);// keep looking until different lane opens
    //move last car from source to destination
    Car switchingCar = lanes[sourceLane].back();

    //remove it from source lane
    lanes[sourceLane].pop_back();

    //add it to destination lane 
    lanes[destLane].push_back(switchingCar);

    //print what happened
    cout << "Lane Seitch: Car from lane " << sourceLane +1 << " to lane " << destLane + 1 << " -- ";
    switchingCar.print();

}


};

int main()
{
 TollBooth booth;
 booth.initializeLine();
 booth.displayLine();

 int time = 1;
 while(booth.hasCars()) {
    cout << "\n---- Time "<< time << "--------"<<endl;
    booth.simulationStep();
    time++;
 }
 cout << "Que empty" <<endl;

    return 0;
}

