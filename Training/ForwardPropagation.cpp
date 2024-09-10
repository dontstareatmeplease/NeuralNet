#include "ForwardPropagation.h"
#include "../GlobalVariables.h"
#include <Eigen/Dense>
#include <unsupported/Eigen/CXX11/Tensor>
#include "Normalization.h"

using Eigen::MatrixXd;
using Eigen::VectorXd;

MatrixXd extractLayer(const Tensor<double, 3>& tensor, int layerIndex) {
    // Define the dimensions of the slice
    Eigen::array<Eigen::Index, 3> offsets = {layerIndex, 0, 0};
    Eigen::array<Eigen::Index, 3> extents = {1, Global::maxLayerSize, Global::maxLayerSize};

    // Extract the slice and reshape it to a matrix
    Tensor<double, 3> layerTensor = tensor.slice(offsets, extents);
    MatrixXd layerMatrix = Eigen::Map<MatrixXd>(layerTensor.data(), Global::maxLayerSize, Global::maxLayerSize);

    return layerMatrix;
}

void forwardPropagation(MatrixXd& activations) {
    for (int layerIndex = 0; layerIndex < Global::layerCount-1; ++layerIndex) {
        MatrixXd curWeights = extractLayer(Global::weights, layerIndex+1);
        VectorXd activationVector = curWeights * activations.row(layerIndex).transpose() - Global::biases.row(layerIndex+1).transpose();
        activationVector = activationVector.unaryExpr([](double x) { return sigmoid(x); });
        activations.row(layerIndex+1) = activationVector;
    }
}

Eigen::VectorXd calculateLoss(Eigen::VectorXd& actual, Eigen::VectorXd& expected) {
    //todo: make both column or row vectors
    return (actual-expected).array().square();
}