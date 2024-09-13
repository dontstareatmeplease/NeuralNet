#ifndef MAKETRAININGSAMPLE_H
#define MAKETRAININGSAMPLE_H
#include <Eigen/Dense>

Eigen::VectorXd getTrainingSample();

Eigen::VectorXd getExpectedResult(const Eigen::VectorXd& sample);
#endif //MAKETRAININGSAMPLE_H
