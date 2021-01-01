//
// Created by popcorn on 26/11/2020.
//
#include <iostream>
#include <vector>
#include "myFunctions.h"
#include <algorithm>
#include <cmath>


/*
std::vector<double> rand_Unif(int nSamples, double a, double b) {
    std::vector<double> sample(nSamples, 0);
    generate(sample.begin(), sample.end(), rand); //generate random numbers between 0 and RAND_MAX
    transform(sample.begin(), sample.end(), sample.begin(), [a, b](double x) {
        return ((x / ((double) RAND_MAX + 1)) * (b - a)) + a;
    });//normalize the random generated numbers to fit an Unif(a,b)
    return sample;
}


std::vector<double> rand_Exponential(int nSamples, double lambda) {
    std::vector<double> sample = rand_Unif(nSamples);
    transform(sample.begin(), sample.end(), sample.begin(), [lambda](double x) {
        return -log(x) / lambda;
    });
    return sample;

}

 */

void initializeSEIRandTemp( std::vector<std::vector<int> > &SEIR,std::vector<double> &temp, int &N){
    SEIR[0][0] = N - 1;
    SEIR[1][0] = 0;
    SEIR[2][0] = 1;
    SEIR[3][0] = 0;
    temp.push_back(0);

}

void  new_Exposed(std::vector<std::vector<int> > &SEIR,int &j){
    SEIR[0].push_back(SEIR[0][j - 1] - 1);
    SEIR[1].push_back(SEIR[1][j - 1] + 1);
    SEIR[2].push_back(SEIR[2][j - 1]);
    SEIR[3].push_back(SEIR[3][j - 1]);
}

void new_Infected(std::vector<std::vector<int> > &SEIR, int &j){
    SEIR[0].push_back(SEIR[0][j - 1]);
    SEIR[1].push_back(SEIR[1][j - 1] - 1);
    SEIR[2].push_back(SEIR[2][j - 1] + 1);
    SEIR[3].push_back(SEIR[3][j - 1]);
}

void new_Recovered(std::vector<std::vector<int> > &SEIR, int &j){
    SEIR[0].push_back(SEIR[0][j - 1]);
    SEIR[1].push_back(SEIR[1][j - 1]);
    SEIR[2].push_back(SEIR[2][j - 1] - 1);
    SEIR[3].push_back(SEIR[3][j - 1] + 1);
}