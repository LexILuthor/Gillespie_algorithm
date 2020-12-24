#include <iostream>
#include <fstream>
#include <vector>
#include<cstdlib>
//#include "myFunctions.h"
#include "gillespie.h"

int main() {

    char outputpath[] = "C:\\Users\\popcorn\\Desktop\\0\\UniTo\\Tesi\\Pugliese\\Modelli Probabilistici\\Gillespie_algorithm\\OutputFIle\\gillespie.csv";
    char inputpath[] = "C:\\Users\\popcorn\\Desktop\\0\\UniTo\\Tesi\\Pugliese\\Modelli Probabilistici\\Gillespie_algorithm\\OutputFIle\\InputGillespie.txt";

    //Number of steps
    int nSteps;

    //Population
    int N;

    //S->E
    double beta;

    // E-> I
    double ny;

    // I->R
    double gamma;


    std::string line;
    std::ifstream infile(inputpath);
    if (infile.is_open()) {

        getline(infile, line, ':');
        getline(infile, line);
        nSteps = std::stoi(line);

        getline(infile, line, ':');
        getline(infile, line);
        N = std::stoi(line);

        getline(infile, line, ':');
        getline(infile, line);
        beta = std::stod(line);

        getline(infile, line, ':');
        getline(infile, line);
        ny = std::stod(line);

        getline(infile, line, ':');
        getline(infile, line);
        gamma = std::stod(line);

        infile.close();
    } else std::cout << "Unable to open file";

    /*
    std::cout<<"nSteps: "<<nSteps<<'\n';
    std::cout<<"N: "<<N<<'\n';
    std::cout<<"beta: "<<beta<<'\n';
    std::cout<<"ny: "<<ny<<'\n';
    std::cout<<"gamma: "<<gamma<<'\n';
    */




    std::vector<double> temp;

    // Gillespie algorithm.
    // SEIR is a matrix that contains the data relative to the number of infected recovred etc..
    // tmp is the vector of the time (each entry is the time at which an event occurred)
    std::vector<std::vector<int> > SEIR = gillespie(nSteps, N, beta, ny, gamma, temp);

    // writing on the csv file
    std::ofstream outfile(outputpath);
    if (!outfile.is_open()) {
        std::cout << "Unable to open file";
    } else {
        for (int i = 0; i < SEIR[0].size(); i++) {

            outfile << SEIR[0][i] << ",\t" << SEIR[1][i] << ",\t" << SEIR[2][i] << ",\t" << SEIR[3][i] << ",\t"
                    << temp[i] << "\n";
        }
        outfile.close();
    }
    return 0;

}