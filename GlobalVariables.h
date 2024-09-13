#ifndef NEURALNET_TRAINING_GLOBALVARIABLES_H
#define NEURALNET_TRAINING_GLOBALVARIABLES_H
#include <vector>
#include <Eigen/Dense>
#include <unsupported/Eigen/CXX11/Tensor>

using Eigen::MatrixXd;
using Eigen::Tensor;

namespace Global {
    extern double learningRate;

    extern int layerCount;
    extern int maxLayerSize;
    extern std::array<int, 3> layerSizes;

    extern MatrixXd biases;
    extern Tensor<double, 3> weights;
}
#endif //NEURALNET_TRAINING_GLOBALVARIABLES_H