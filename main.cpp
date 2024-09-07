/* 4 neurons -> 3 neurons -> 4 neuron neural network
    - goal: given 4 numbers, identify the greatest number
    - calculations: training & back propagation will be run locally
    - storage:
        - at the start of each training session, the program will be run and fetch data
          (weights & biases) from a MongoDB database
        - at the end of each session, the new parameters will be written into the mongodb database
          as a new document


- weights tensor (layers-1 * max layer size * max prev layer size) 2*4*4
- bias matrix (layers-1 * max layer size) 2*4
- values matrix (3*4)
 */

#include <iostream>
#include "Sigmoid.h"
#include "DbOperations.h"
#include "GlobalVariables.h"
#include "eigen-3.4.0/Eigen/Dense"


//todo: import library for plotting graphs

int main() {
    importData();

    //exportData();
    return 0;
}