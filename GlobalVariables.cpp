#include "GlobalVariables.h"
#include "Eigen/Dense"
#include <unsupported/Eigen/CXX11/Tensor>

using Eigen::MatrixXd;
using Eigen::Tensor;

namespace Global {
    double learningRate = 0.01;

    int layerCount = 3;
    int maxLayerSize = 4;
    std::array<int, 3> layerSizes{4, 3, 4};

    MatrixXd biases(layerCount, maxLayerSize);
    Tensor<double, 3> weights(layerCount, maxLayerSize, maxLayerSize);
}