#ifndef NEURALNET_TRAINING_GLOBALVARIABLES_H
#define NEURALNET_TRAINING_GLOBALVARIABLES_H
#include <vector>
#include "eigen-3.4.0/Eigen/Dense"
#include "eigen-3.4.0/unsupported/Eigen/CXX11/Tensor"

using Eigen::MatrixXd;
using Eigen::Tensor;

namespace Global {
    extern int layers;
    extern int maxLayerSize;
    extern std::array<int, 3> layerSizes;

    extern MatrixXd biases;
    extern MatrixXd activations;
    extern Tensor<double, 3> weights;
}
#endif //NEURALNET_TRAINING_GLOBALVARIABLES_H