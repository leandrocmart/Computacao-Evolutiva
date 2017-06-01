//
// Created by leandro on 01/06/17.
//

#ifndef LOCATIONROUTING_AE_H
#define LOCATIONROUTING_AE_H

#include "Individual.h"

class AE {
public:
    AE(LocationRoutingProblem &problem, int pop_size, int generation_size, double a_p);
    int getPopulation_Size() const;
    void createInitialPopulation(LocationRoutingProblem &problem);
    int tournamentSelection(vector<Individual> &population, int tournament_size);
    int rouletteSelection(vector<Individual> &population);
    vector<int> rouletteSUSSelection(vector<Individual> &population, int n_pins);
    void run(LocationRoutingProblem &problem, int generation_size);
    void findBest(Individual &best_solution);
    double getAlpha_p() const;
    double getMut_p() const;
    bool isCompeticao_pais_filhos() const;
    void display(LocationRoutingProblem &problem);
    vector<Individual> elitism(vector<Individual> &population, int n_elite);
    void removeWorst(vector<Individual> &population, int n_elite);
private:
    vector<Individual> population;
    int population_size;
    //LocationRoutingSolution best_solution;
    //double cross_p; //Probabilidade de crossover (mutação  = 1 - cp)
    //double mut_p; //Intensidade de mutação ou probabilidade de mutar apenas um gene
    bool competicao_pais_filhos;
    int proporcao_pais_filhos;
    static default_random_engine generator;
    double alpha_p;
};


#endif //LOCATIONROUTING_AE_H
