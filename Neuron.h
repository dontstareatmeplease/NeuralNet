#ifndef NEURON_H
#define NEURON_H
#include <iostream>
#include <vector>

class Neuron {
private:
    int m_layer;
    double m_value;
    std::vector<double> m_weights{}; //bias is added to the end of the weights vector
    std::string m_neuronName{}; // name of neuron stored on mongoDB: layer, number

public:
    //takes the name, accesses database, copies neuron to this object
    Neuron(std::string_view neuronName);

    //uploads new bias & weights back to database to store at the end of the training session
    ~Neuron();

    //computes value of neuron given activations of previous layer, weights, and biases
    //sets m_value
    void computeValue();

    //change weights & biases based on gradient
    void adjustParams();

    //getters
    double value() const {return m_value;}
    void setValue(double val) {m_value = val;}
    int layer() const {return m_layer;}
    std::string_view neuronName() const {return m_neuronName;}
    std::vector<double>& weights() {return m_weights;}
};


#endif //NEURON_H
