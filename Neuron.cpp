#include "Neuron.h"
#include "Sigmoid.h"
#include <iostream>
#include <vector>

Neuron::Neuron(std::string_view neuronName) {

}

Neuron::~Neuron() {

}

void Neuron::computeValue() {
    if (layer() == 1) {return;}

    //placeholder vector for previous layer of neurons
    std::vector<Neuron> prevLayer = {};
    std::vector<double>& weights = Neuron::weights();

    double sum = 0;
    for (int i = 0; i < prevLayer.size(); ++i) {
        sum+= prevLayer[i].value()*weights[i];
    }

    sum -= weights[weights.size()-1];
    Neuron::setValue(sigmoid(sum));
}

void Neuron::adjustParams() { //todo: needs parameters

}