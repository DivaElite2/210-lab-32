//Lateefah Camacho
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <deque>
#include "Car.h"
using namespace std;

const int INITIAL_CARS = 2; //const for intitial deque size
const int NR_LANES = 4; // LANES 4
const int  TOTAL_TIME_PERIODS = 20;

//Probability constants
const int PROB_PAY_TOLL = 46;
const int PROB_NEW_CAR = 39;
const int PROB_SWITCH_LANES = 15;

class TollBooth {
    private:
//create deque
deque<Car> lanes[NR_LANES];

public:
   TollBooth() {
  //seed Random number
  srand(time(0));
}
void initializeLanes() {
    for (int laneIndex = 0; laneIndex < NR_LANES; laneIndex++) {
        for (int carCount = 0; carCount < INITIAL_CARS; carCount++) {
            Car newCar;
            lanes[laneIndex].push_back(newCar);
    }
 }
    cout << "Initialized with " << INITIAL_CARS << "cars in line "<<endl; 

}

void simulationStep() {
    // For EACH lane, perform one random operation
    for (int laneIndex = 0; laneIndex < NR_LANES; laneIndex++) {
        cout << "Lane " << laneIndex + 1 << ": ";
        
        int randomEvent = rand() % 100 + 1;
        
        // Check if lane is empty and handle 50/50 case
        if (lanes[laneIndex].empty()) {
            // Lane is empty - 50/50 for new car or nothing
            if (randomEvent <= 50) {
                // Add new car
                Car newCar;
                lanes[laneIndex].push_back(newCar);
                cout << "NEW CAR ARRIVES: ";
                newCar.print();
            } else {
                // Do nothing
                cout << "Empty lane - no operation" << endl;
            }
        } else {
            // Lane has cars - use normal probabilities
            if (randomEvent <= PROB_PAY_TOLL) {
                // Car pays toll and leaves from front
                cout << "CAR PAYS TOLL AND LEAVES: ";
                lanes[laneIndex].front().print();
                lanes[laneIndex].pop_front();
            } else if (randomEvent <= PROB_PAY_TOLL + PROB_NEW_CAR) {
                // New car arrives at back  
                Car newCar;
                lanes[laneIndex].push_back(newCar);
                cout << "NEW CAR ARRIVES: ";
                newCar.print();
            } else {
                // Rear car switches lanes
                // The size() > 0 check is redundant here since we're in the "else" of empty()
                int destLane;
                do {
                    destLane = rand() % NR_LANES;
                } while (destLane == laneIndex);  // Find a different lane
                
                // Move the last car from current lane to destination lane
                Car switchingCar = lanes[laneIndex].back();
                lanes[laneIndex].pop_back();
                lanes[destLane].push_back(switchingCar);
                
                cout << "LANE SWITCH: Car moved from lane " << laneIndex + 1 
                     << " to lane " << destLane + 1 << " - ";
                switchingCar.print();
            }
        }
    }
}



void displayLanes() {
    for (int laneIndex = 0; laneIndex < NR_LANES; laneIndex++) {
        cout << "Lane " << laneIndex + 1 << " (" << lanes[laneIndex].size() << " cars): ";
        
        // Iterate through each car in this lane and call print
        for(auto& car : lanes[laneIndex]) {
            car.print();
        }
        cout << endl;  // New line after each lane
    }
    cout << endl;  // Extra space after all lanes
}



};

int main()
{
 TollBooth booth;
 booth.initializeLanes();
 booth.displayLanes();

 // Run for 20 time periods
    for (int time = 1; time <= 20; time++) {
        cout << "\n=== Time Period " << time << " ===" << endl;
        booth.simulationStep();
        booth.displayLanes();  // Show state after operations
    }
    return 0;
}

