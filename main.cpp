/* 4 neurons -> 3 neurons -> 4 neuron neural network
    - goal: given 4 numbers, identify the greatest number
    - calculations: training & back propagation will be run locally
    - storage:
        - at the start of each training session, the program will be run and fetch data
          (weights & biases) from a MongoDB database
        - at the end of each session, the new parameters will be written into the mongodb database
          as a new document


- weights tensor (layerCount-1 * max layer size * max prev layer size) 2*4*4
- bias matrix (layerCount-1 * max layer size) 2*4
- values matrix (3*4)
 */

#include <iostream>
#include "DbOperations.h"
#include "GlobalVariables.h"
#include <Eigen/Dense>
#include "Training/MakeTrainingSample.h"
#include "Training/ForwardPropagation.h"

void debug() {
    MatrixXd activations(Global::layerCount, Global::maxLayerSize);
    activations.row(0) = getTrainingSample();
    Eigen::VectorXd result = getExpectedResult(activations.row(0));

    Global::weights.setRandom();
    for (int i = 0; i < Global::weights.dimension(0); ++i) {
        for (int j = 0; j < Global::weights.dimension(1); ++j) {
            for (int k = 0; k < Global::weights.dimension(2); ++k) {
                std::cout << Global::weights(i, j, k) << ' ';
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }
    std::cout << '\n';

    forwardPropagation(activations);
    for (int i = 0; i < activations.rows(); ++i) {
        for (int j = 0; j < activations.cols(); ++j) {
            std::cout << activations(i, j) << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    //importData();
    debug();
    MatrixXd activations(Global::layerCount, Global::maxLayerSize);
    activations.row(0) = getTrainingSample();
    Eigen::VectorXd result = getExpectedResult(activations.row(0));

    //exportData();
    return 0;
}