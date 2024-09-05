cmake_minimum_required(VERSION 3.26)
project(NeuralNet_Training)

set(CMAKE_CXX_STANDARD 23)

add_executable(NeuralNet_Training main.cpp
        Neuron.cpp
        Sigmoid.cpp)
