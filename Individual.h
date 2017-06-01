//
// Created by leandro on 01/06/17.
//

#ifndef LOCATIONROUTING_INDIVIDUAL_H
#define LOCATIONROUTING_INDIVIDUAL_H

#include "LocationRoutingSolution.h"

class Individual {
public:
    Individual(LocationRoutingProblem &problem, LocationRoutingSolution &sol);
    Individual(const LocationRoutingSolution &solution, double p_mut, double p_cross, const vector<double> &i_mut);

    void display(LocationRoutingProblem &problem);
    LocationRoutingSolution &getSolution();
    void mutation(LocationRoutingProblem &problem, Individual &offspring1, Individual &offspring2, Individual &parent1, Individual &parent2, double alpha_p);
    double getP_mut() const;
    double getP_cross() const;
    void setP_mut(double p_mut);
    void setP_cross(double p_cross);
    const vector<double> &getI_mut() const;
    void setI_mut(const vector<double> &i_mut);
private:
    LocationRoutingSolution solution; //Solução do problema
    double p_mut, p_cross; //Taxas de mutação e crossover
    vector<double> i_mut; //Vetor de intensidades de mutação
    /*vector<double> sigma3;
    vector<double> alpha;*/
    static default_random_engine generator;
};

#endif //LOCATIONROUTING_INDIVIDUAL_H
