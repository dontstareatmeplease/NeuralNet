#include "GlobalVariables.h"
#include "Eigen/Dense"
#include "unsupported/Eigen/CXX11/Tensor"

using Eigen::MatrixXd;
using Eigen::Tensor;

namespace Global {
    int layers = 3;
    int maxLayerSize = 4;
    std::array<int, 3> layerSizes{4, 3, 4};

    MatrixXd biases(layers-1, maxLayerSize);
    MatrixXd activations(layers, maxLayerSize);
    Tensor<double, 3> weights(layers - 1, maxLayerSize, maxLayerSize);
}