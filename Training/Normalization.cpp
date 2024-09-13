#include "Normalization.h"

double sigmoid(double input) {
    return 1/(1+exp(-input));
}

double diffSigmoid(double sigmoid) {
    return sigmoid*(1-sigmoid);
}