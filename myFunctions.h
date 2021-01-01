//
// Created by popcorn on 26/11/2020.
//


    #ifndef GILLESPIE_ALGORITHM_MYFUNCTIONS_H
    #define GILLESPIE_ALGORITHM_MYFUNCTIONS_H

    #endif //GILLESPIE_ALGORITHM_MYFUNCTIONS_H

/*
std::vector<double> rand_Unif(int nSamples = 1, double a = 0, double b = 1);

std::vector<double> rand_Exponential(int nSamples = 1, double lambda = 1);
*/


void initializeSEIRandTemp(std::vector<std::vector<int> > &SEIR, std::vector<double> &temp, int &N);

void new_Exposed(std::vector<std::vector<int> > &SEIR, int &j);

void new_Infected(std::vector<std::vector<int> > &SEIR, int &j);

void new_Recovered(std::vector<std::vector<int> > &SEIR, int &j);