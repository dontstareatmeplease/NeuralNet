#include "DbOperations.h"
#include "GlobalVariables.h"
#include "Private.h"
#include <iostream>

//for MongoDB
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/builder/basic/document.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>

using namespace mongocxx;
using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_array;
using bsoncxx::builder::basic::make_document;

void pingConnection(database& db) {
    const auto ping_cmd = bsoncxx::builder::basic::make_document(bsoncxx::builder::basic::kvp("ping", 1));
    db.run_command(ping_cmd.view());
    std::cout << "Pinged deployment. Successfully connected to MongoDB!" << '\n';
}

void importData() {
    try {
        //connecting to mongodb
        instance inst{};
        uri uri(Private::dbUri);
        client client(uri);
        database db = client["NeuralNet"];
        pingConnection(db);


        //import data from MongoDB
        auto latestFilter = make_document(kvp("latest", true));
        collection weightsCollection = db["weights"];
        fetchWeights(weightsCollection, latestFilter);
        collection biasCollection = db["biases"];
        fetchBiases(biasCollection, latestFilter);
    } catch (const std::exception& e) {
        std::cout<< "Exception: " << e.what() << '\n';
    }
}

//copies data from MongoDB to Global::weights
void fetchWeights(collection& collection, auto& filter) {
    auto latest = collection.find_one(filter.view());
    auto latestView = latest->view();
    auto tempWeights = latestView["data"].get_array().value;

    int arrIndex = 0;
    for (int layerIndex = 0; layerIndex < Global::weights.dimension(0); ++layerIndex) {
        for (int neuronIndex = 0; neuronIndex < Global::weights.dimension(1); ++neuronIndex) {
            for (int weightIndex = 0; weightIndex < Global::weights.dimension(2); ++weightIndex) {
                double cur = tempWeights[arrIndex].get_double();
                Global::weights(layerIndex, neuronIndex, weightIndex) = cur;
                arrIndex++;
            }
        }
    }
}

//copies data from MongoDB to Global::biases
void fetchBiases(collection& collection, auto& filter) {
    auto latest = collection.find_one(filter.view());
    auto latestView = latest->view();
    auto tempBiases = latestView["data"].get_array().value;

    int arrIndex = 0;
    for (int layerIndex = 0; layerIndex < Global::biases.rows(); ++layerIndex) {
        for (int neuronIndex = 0; neuronIndex < Global::biases.cols(); ++neuronIndex) {
            double cur = tempBiases[arrIndex].get_double();
            Global::biases(layerIndex, neuronIndex) = cur;
            arrIndex++;
        }
    }
}

void exportData() {

}

void writeTrainingSet() {

}

void writeWeights() {

}

void writeBiases() {

}