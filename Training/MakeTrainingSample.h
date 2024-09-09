#ifndef MAKETRAININGSAMPLE_H
#define MAKETRAININGSAMPLE_H
#include "../eigen-3.4.0/Eigen/Dense"

Eigen::VectorXd getTrainingSample();

Eigen::VectorXd getExpectedResult(Eigen::VectorXd sample);
#endif //MAKETRAININGSAMPLE_H
