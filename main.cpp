/* 4 neurons -> 2 neurons -> 4 neuron neural network
    - goal: given 4 numbers, identify the greatest number
    - calculations: training & back propagation will be run locally
    - storage: each neuron will be stored on MongoDB database
 */

#include <iostream>
#include "Neuron.h"
#include "Sigmoid.h"


//todo: import library for matrix algebra
//todo: import library for plotting graphs
using Layer = std::vector<Neuron>;

//sets up neural network
//draws data from
void setUp() {
    Layer l1;
    for (int i = 0; i < 4; ++i) {
        //todo: import from mongodb;
    }

    Layer l2;
    for (int i = 0; i < 3; ++i) {

    }

    Layer l3;
    for (int i = 0; i < 4; ++i) {

    }
}

int main() {
    std::cout << sigmoid(0);
    //setUp();
    return 0;
}