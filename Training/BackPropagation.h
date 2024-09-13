#ifndef BACKPROPAGATION_H
#define BACKPROPAGATION_H
#include <Eigen/Dense>
#include <unsupported/Eigen/CXX11/Tensor>
using Eigen::Tensor;
using Eigen::VectorXd;
using Eigen::MatrixXd;

void calculateGradient(const MatrixXd& activations, Tensor<double, 3>& weightsGradient,
                     MatrixXd& biasGradient, VectorXd& expectedOutput);

void calculateLossDiff(MatrixXd& activationsGradient, const MatrixXd& activations, VectorXd& expectedOutput);

void getWeightsGradient(int layer, const MatrixXd& intermediate,
                        const MatrixXd& activations, Tensor<double, 3>& weightsGradient);

void getActivationsGradient(int layer, const MatrixXd& intermediate,
                            const Tensor<double, 3>& weights, MatrixXd& activationsGradient);

#endif //BACKPROPAGATION_H