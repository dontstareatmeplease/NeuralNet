//fetches data from MongoDB

#ifndef IMPORTDATA_H
#define IMPORTDATA_H
#include <mongocxx/client.hpp>

using namespace mongocxx;
void pingConnection(database& db);

void importData();

void fetchWeights(collection& collection, auto& filter);

void fetchBiases(collection& collection, auto& filter);

void exportData();

void writeTrainingSet();

void writeWeights();

void writeBiases();

#endif //IMPORTDATA_H