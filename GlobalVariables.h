#ifndef NEURALNET_TRAINING_GLOBALVARIABLES_H
#define NEURALNET_TRAINING_GLOBALVARIABLES_H
#include <vector>
using namespace std;
namespace Global {
    array<double, 2*4*4> g_weights {};
    array<double, 2*4> g_biases{};
    array<double, 3*4> g_activations{};
}
#endif //NEURALNET_TRAINING_GLOBALVARIABLES_H
