//
// Created by Leandro on 15/05/2017.
//

#ifndef LOCATIONROUTING_GA_H
#define LOCATIONROUTING_GA_H

#include "LocationRoutingProblem.h"
#include "LocationRoutingSolution.h"

class GA {
public:
    GA(LocationRoutingProblem &problem, int pop_size, double cp);
    int getPopulation_Size() const;
    void createInitialPopulation(LocationRoutingProblem &problem);
    int tournamentSelection(vector<LocationRoutingSolution> &population, int tournament_size);
    int rouletteSelection(vector<LocationRoutingSolution> &population);
    void run(LocationRoutingProblem &problem, int generation_size);
    void findBest(LocationRoutingSolution &best_solution);
    double getCross_p() const;
    double getMut_p() const;
    bool isCompeticao_pais_filhos() const;
    void display(LocationRoutingProblem &problem);
    vector<LocationRoutingSolution> elitism(vector<LocationRoutingSolution> &population, int n_elite, LocationRoutingProblem &problem);
    void removeWorst(vector<LocationRoutingSolution> &population, int n_elite);
private:
    vector<LocationRoutingSolution> population;
    int population_size;
    //LocationRoutingSolution best_solution;
    double cross_p; //Probabilidade de crossover (mutação  = 1 - cp)
    double mut_p; //Intensidade de mutação ou probabilidade de mutar apenas um gene
    bool competicao_pais_filhos;
    static default_random_engine generator;
};


#endif //LOCATIONROUTING_GA_H
