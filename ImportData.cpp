#include "ImportData.h"
#include "GlobalVariables.h"
#include <iostream>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>

void importData() {
    try {
        //connecting to mongodb
        mongocxx::instance inst{};
        mongocxx::uri uri("mongodb+srv://kevin:hurricane@firstproject.m9dq4lf.mongodb.net/?retryWrites=true&w=majority&appName=FirstProject");
        mongocxx::client client(uri);
        auto db = client["NeuralNet"];
        const auto ping_cmd = bsoncxx::builder::basic::make_document(bsoncxx::builder::basic::kvp("ping", 1));
        db.run_command(ping_cmd.view());
        std::cout << "Pinged your deployment. Successfully connected to MongoDB!\n";

        fetchWeights();
        fetchBiases();
    } catch (const std::exception& e) {
        // Handle errors
        std::cout<< "Exception: " << e.what() << std::endl;
    }
}

void fetchWeights() {

}

void fetchBiases() {

}