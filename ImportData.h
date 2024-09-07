//fetches data from MongoDB

#ifndef IMPORTDATA_H
#define IMPORTDATA_H
//todo: install mongocxx

//functioned called from main, will call all other functions
void importData();

void fetchWeights();

void fetchBiases();
#endif //IMPORTDATA_H