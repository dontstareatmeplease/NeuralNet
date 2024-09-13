#include "MakeTrainingSample.h"
#include <Eigen/Dense>
#include <random>
#include "../GlobalVariables.h"
#include <iostream>

Eigen::VectorXd getTrainingSample() {
    Eigen::VectorXd sample(Global::maxLayerSize);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (int i = 0; i < Global::layerSizes[0]; ++i) {
        sample[i] = dis(gen);
    }

    return sample;
}

Eigen::VectorXd getExpectedResult(const Eigen::VectorXd& sample) {
    Eigen::VectorXd result(Global::maxLayerSize);
    result.setZero();
    double max = 0;
    int maxIndex;
    for (int i = 0; i < result.size(); ++i) {
        if (sample[i] > max) {
            max = sample[i];
            maxIndex = i;
        }
    }
    result[maxIndex] = 1;
    return result;
}