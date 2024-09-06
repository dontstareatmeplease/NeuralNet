#include "Neuron.h"
#include <iostream>

Neuron::Neuron(int layerIndex, int neuronIndex) :
m_layerIndex{layerIndex},
m_neuronIndex{neuronIndex}
{

}

Neuron::~Neuron() {

}

void Neuron::computeValue() {}