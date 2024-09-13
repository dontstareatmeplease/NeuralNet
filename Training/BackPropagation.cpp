#include "BackPropagation.h"
#include "../GlobalVariables.h"
#include <Eigen/Dense>
#include <unsupported/Eigen/CXX11/Tensor>
#include <iostream>
#include "Normalization.h"
#include "ForwardPropagation.h"

using Eigen::MatrixXd;
using Eigen::VectorXd;
using Eigen::Tensor;
void calculateGradient(const MatrixXd& activations, Tensor<double, 3>& weightsGradient,
                       MatrixXd& biasGradient, VectorXd& expectedOutput) {

    MatrixXd activationsGradient(activations.rows(), activations.cols());
    calculateLossDiff(activationsGradient, activations, expectedOutput);
    MatrixXd diffSigmoids = activations.unaryExpr([](double x) { return diffSigmoid(x); });

    for (int layer = Global::layerCount-1; layer > 0 ; --layer) {
        //calculates the common factor for the gradients of all elements of the current layer
        MatrixXd intermediate = activationsGradient.row(layer).transpose() * diffSigmoids.row(layer);

        getWeightsGradient(layer, intermediate, activations, weightsGradient);

        getActivationsGradient(layer, intermediate, Global::weights, activationsGradient);

        biasGradient.row(layer) = activationsGradient.row(layer).array() * diffSigmoids.row(layer).array();
    }
}

void calculateLossDiff(MatrixXd& activationsGradient, const MatrixXd& activations, VectorXd& expectedOutput) {
    Eigen::RowVectorXd rowExpected;
    if (expectedOutput.rows() != 1) {
        rowExpected = expectedOutput.transpose();
    } else {
        rowExpected = expectedOutput;
    }

    activationsGradient.row(Global::layerCount-1) = 2*(activations.row(Global::layerCount-1) - rowExpected);
}

void getWeightsGradient(int layer, const MatrixXd& intermediate, const MatrixXd& activations, Tensor<double, 3>& weightsGradient) {
    MatrixXd curWeightGradient = intermediate.array().rowwise() * activations.array().row(layer-1);
    for (int i = 0; i < curWeightGradient.rows(); ++i) {
        for (int j = 0; j < curWeightGradient.cols(); ++j) {
            weightsGradient(layer, i, j) = curWeightGradient(i, j);
        }
    }
}

//todo: ask ai to verify the averaging process
void getActivationsGradient(int layer, const MatrixXd& intermediate,
                            const Tensor<double, 3>& weights, MatrixXd& activationsGradient) {
    MatrixXd curWeight = extractLayer(weights, layer);
    MatrixXd preAverage = curWeight.array() * intermediate.array();
    activationsGradient.row(layer-1) = preAverage.colwise().mean();
}