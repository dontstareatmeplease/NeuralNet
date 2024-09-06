#ifndef NEURON_H
#define NEURON_H
#include <iostream>

class Neuron {
private:
    int m_layerIndex;
    int m_neuronIndex;
    double m_value{};

public:
    //takes the name, accesses database, copies neuron to this object
    Neuron(int layerIndex, int neuronIndex);

    //uploads new bias & weights back to database to store at the end of the training session
    ~Neuron();

    //computes value of neuron given activations of previous layer, weights, and biases
    //sets m_value
    void computeValue();

    //getters
    double value() const {return m_value;}
    void setValue(double val) {m_value = val;}
    int layerIndex() const {return m_layerIndex;}
    int neuronIndex() const {return m_neuronIndex;}
};


#endif //NEURON_H
