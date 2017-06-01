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
    //void mutation();
    double getP_mut() const;
    double getP_cross() const;
    void setP_mut(double p_mut);
    void setP_cross(double p_cross);

    const vector<double> &getI_mut() const;
    vector<double> &getI_mut();

    void setI_mut(const vector<double> &i_mut);

private:
    LocationRoutingSolution solution;
    double p_mut, p_cross;
    vector<double> i_mut;
    /*vector<double> sigma3;
    vector<double> alpha;*/
    static default_random_engine generator;
};

#endif //LOCATIONROUTING_INDIVIDUAL_H
