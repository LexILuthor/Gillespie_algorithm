//
// Created by popcorn on 27/11/2020.
//

#include <iostream>
#include <vector>
#include<cstdlib>
#include <random>
#include "myFunctions.h"
#include "gillespie.h"

std::vector<std::vector<int> >
gillespie(int nSteps, int N, double beta, double ny, double gamma, std::vector<double> &temp) {
    //Here you can change the seed of the generator
    std::default_random_engine generator(0);


    std::vector<std::vector<int> > SEIR(4, std::vector<int>(1, 0));


    double move = (double) 1 / N;
    //setting the initial conditions
    initializeSEIRandTemp(SEIR, temp, N);
    double lambda = 1;
    int j = 1;

    // here we simulate the process
    while (j < nSteps && lambda != 0) {
        //number of Susceptible
        int s = SEIR[0][j - 1];

        //number of Exposed
        int e = SEIR[1][j - 1];

        //Number of Infected
        int i = SEIR[2][j - 1];

        //number of Recovered
        int r = SEIR[3][j - 1];


        if (r == N) {
            //everyone recovered
            return SEIR;
        }


        // compute the parameter lambda of the exponential and the probabilities of
        // S->E, E->I, I->R
        double se = beta * s * i * move;
        double ei = ny * e;
        double ir = gamma * i;
        lambda = (se + ei + ir);
        se = se / lambda;
        ei = ei / lambda;
        ir = ir / lambda;


        //generate the time of the next event with an exponential with parameter lambda
        std::exponential_distribution<double> exp_distribution(lambda);
        double event = exp_distribution(generator);
        temp.push_back(temp.back() + event);


        //Randomly decide which event happened
        double tmp = rand() / ((double) RAND_MAX + 1);
        if (tmp < se) {
            //new Exposed
            new_Exposed(SEIR, j);
        } else if (tmp < (se + ei)) {
            //new infected
            new_Infected(SEIR, j);
        } else {
            //new Recovered
            new_Recovered(SEIR, j);
        }
        j++;
    }

    return SEIR;

}

