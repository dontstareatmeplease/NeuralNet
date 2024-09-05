#include "Sigmoid.h"

double sigmoid(double input) {
return 1/(1+exp(-input));
}