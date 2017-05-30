//
// Created by Leandro on 04/05/2017.
//

#ifndef CE_LRP_LOCATIONROUTING_H
#define CE_LRP_LOCATIONROUTING_H

#include "LocationRoutingProblem.h"

//typedef LocationRoutingSolution (*crossover)(LocationRoutingProblem&, LocationRoutingSolution&, LocationRoutingSolution&, int n);

using namespace std;

class LocationRoutingSolution {
public:
    LocationRoutingSolution(LocationRoutingProblem &problem, int n);
    LocationRoutingSolution(LocationRoutingProblem &problem);
    //LocationRoutingSolution(const LocationRoutingSolution &other);
    const vector<int> &getIs_hub() const;
    const vector<int> &getWhat_hub() const;
    const list<int> &getHubs() const;
    int getN_hub() const;
    double getCost() const;
    vector<int> &changeIs_hub();
    vector<int> &changeWhat_hub();
    list<int> &changeHubs();
    void createSolution(LocationRoutingProblem &problem, int n);
    void evaluateSolution(LocationRoutingProblem &problem);
    void mutation(LocationRoutingProblem &problem);
    LocationRoutingSolution crossoverNPoint(LocationRoutingProblem &problem, LocationRoutingSolution &parent2, LocationRoutingSolution &offspring1, int n);
    LocationRoutingSolution crossoverUniform(LocationRoutingProblem &problem, LocationRoutingSolution &parent2, LocationRoutingSolution &offspring1, int n);
    int searchHub(int node);
    void whatHubUpdate(LocationRoutingProblem &problem);
    void display(LocationRoutingProblem &problem);
    void reset(LocationRoutingProblem &problem);
    static const default_random_engine &getGenerator();
private:
    vector<int> is_hub; //qual nó é concentrador
    vector<int> what_hub; //qual concentrador está associado a cada nó
    list<int> hubs;
    int n_hub; //números de nós
    double cost; //custo da solução
    static default_random_engine generator;
};

#endif //CE_LRP_LOCATIONROUTING_H
