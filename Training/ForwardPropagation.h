#ifndef FORWARDPROPAGATION_H
#define FORWARDPROPAGATION_H
#include <iostream>
#include <Eigen/Dense>
#include <unsupported/Eigen/CXX11/Tensor>

void forwardPropagation(Eigen::MatrixXd& activations);

Eigen::MatrixXd extractLayer(const Eigen::Tensor<double, 3>& tensor, int layerIndex);

#endif //FORWARDPROPAGATION_H
