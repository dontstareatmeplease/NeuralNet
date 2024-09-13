/* This project is a stepping stone for a bigger project, which will be a neural network that
  4 neurons -> 3 neurons -> 4 neuron neural network
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
#include "Training/BackPropagation.h"

#define DEBUG

using Eigen::MatrixXd;
using Eigen::Tensor;
using Eigen::VectorXd;

void formatWeights(Tensor<double, 3>& weights) {
    for (int i = 0; i < 4; ++i) {
        weights(1, 3, i) = 0;
        weights(2, i, 3) = 0;
    }
}

int main() {
    //importData();

    MatrixXd activations(Global::layerCount, Global::maxLayerSize);
    activations.row(0) = getTrainingSample().transpose();
    VectorXd result = getExpectedResult(activations.row(0));
    Global::weights.setRandom();
    formatWeights(Global::weights);

    forwardPropagation(activations);

    VectorXd expectedResult = getExpectedResult(activations.row(0));
    Tensor<double, 3> weightsGradient(Global::weights.dimension(0),
                                      Global::weights.dimension(1), Global::weights.dimension(2));
    MatrixXd biasGradient(Global::biases.rows(), Global::biases.cols());

    calculateGradient(activations, weightsGradient, biasGradient, expectedResult);

#ifdef DEBUG
    std::cout << "training sample: " << activations.row(0) << '\n';
    std::cout << "expected result: " << result.transpose() << "\n\n";

    std::cout << "weights: " << '\n';
    for (int i = 1; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                std::cout << Global::weights(i, j, k) << '\t';
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }
    std::cout << '\n';

    std::cout << "biases:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << Global::biases(i, j) << '\t';
        }
        std::cout << '\n';
    }
    std::cout << '\n';

    std::cout << "activations:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << activations(i, j) << '\t';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
#endif
}