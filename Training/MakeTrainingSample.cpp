#include "MakeTrainingSample.h"
#include "../eigen-3.4.0/Eigen/Dense"
#include <random>
#include <iostream>

Eigen::VectorXd getTrainingSample() {
    Eigen::VectorXd sample(4);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (int i = 0; i < 4; ++i) {
        sample[i] = dis(gen);
    }

    return sample;
}

Eigen::VectorXd getExpectedResult(Eigen::VectorXd sample) {
    Eigen::VectorXd result(4);
    result << 0, 0, 0, 0;
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