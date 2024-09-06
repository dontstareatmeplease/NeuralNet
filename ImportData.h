//fetches data from MongoDB

#ifndef IMPORTDATA_H
#define IMPORTDATA_H
//todo: install mongocxx

//functioned called from main, will call all other functions
void importData();

void startDbConnection();

//create mdspans for weights, biases, and values
void createContainers();

void fetchWeights();

void fetchBiases();

void endDbConnection();
#endif //IMPORTDATA_H