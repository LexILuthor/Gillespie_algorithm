//
// Created by popcorn on 27/11/2020.
//

#include <iostream>
#include <vector>
#include<cstdlib>
#include <random>
//#include "myFunctions.h"
#include "gillespie.h"

std::vector<std::vector<int> >
gillespie(int nSteps, int N, double beta, double ny, double gamma, std::vector<double> &temp) {
    std::vector<std::vector<int> > SEIR(4, std::vector<int>(1, 0));


    //Here you can change the seed of the generator
    std::default_random_engine generator(0);


    double move = (double) 1 / N;
    //setting the initial conditions
    SEIR[0][0] = N - 1;
    SEIR[1][0] = 0;
    SEIR[2][0] = 1;
    SEIR[3][0] = 0;
    temp.push_back(0);

    double lambda = 1;
    int j = 1;

    // here we simulate the process
    while (j < nSteps && lambda!=0) {
        int s = SEIR[0][j - 1];
        int e = SEIR[1][j - 1];
        int i = SEIR[2][j - 1];
        int r = SEIR[3][j - 1];
        if (r == N) {
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

        //generate the time of the event with an exponential with parameter lambda
        std::exponential_distribution<double> exp_distribution(lambda);
        double events = exp_distribution(generator);
        temp.push_back(temp.back() + events);


        //Randomly decide which event happened
        double tmp = rand() / ((double) RAND_MAX + 1);
        if (tmp < se) {
            SEIR[0].push_back(SEIR[0][j - 1] - 1);
            SEIR[1].push_back(SEIR[1][j - 1] + 1);
            SEIR[2].push_back(SEIR[2][j - 1]);
            SEIR[3].push_back(SEIR[3][j - 1]);
        } else if (tmp < (se + ei)) {
            SEIR[0].push_back(SEIR[0][j - 1]);
            SEIR[1].push_back(SEIR[1][j - 1] - 1);
            SEIR[2].push_back(SEIR[2][j - 1] + 1);
            SEIR[3].push_back(SEIR[3][j - 1]);
        } else {
            SEIR[0].push_back(SEIR[0][j - 1]);
            SEIR[1].push_back(SEIR[1][j - 1]);
            SEIR[2].push_back(SEIR[2][j - 1] - 1);
            SEIR[3].push_back(SEIR[3][j - 1] + 1);
        }
        j++;
    }

    return SEIR;

}

