#ifndef NEURALNET_TRAINING_GLOBALVARIABLES_H
#define NEURALNET_TRAINING_GLOBALVARIABLES_H
#include <vector>
//#include <mdspan>
using namespace std;
namespace Global {
    array<double, 2*4*4> g_weights {};
    array<double, 2*4> g_biases{};
    array<double, 3*4> g_activations{};
    //mdspan g_weightsView(g_weights.data(), 2, 4, 4);
    //mdspan g_biasView(g_biases.data(), 2, 4);
    //mdspan g_activationsView(g_activations.data(), 3, 4);
}
#endif //NEURALNET_TRAINING_GLOBALVARIABLES_H
