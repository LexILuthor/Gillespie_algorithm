//
// Created by popcorn on 27/11/2020.
//

#ifndef GILLESPIE_ALGORITHM_GILLESPIE_H
#define GILLESPIE_ALGORITHM_GILLESPIE_H

#endif //GILLESPIE_ALGORITHM_GILLESPIE_H


// gillespie algorithm, it return a matrix that contains the data relative to the number of Susceptible in the first row, Exposed in the second row,Infected in the third row, Recovered in the fourth row
// tmp is the vector of the time (each entry is the time at which an event occurred)

std::vector<std::vector<int> > gillespie(int nSteps, int N, double beta, double ny, double gamma,
                                         std::vector<double> &temp);