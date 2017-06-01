//
// Created by leandro on 01/06/17.
//

#include "Individual.h"

default_random_engine Individual::generator((int) chrono::system_clock::now().time_since_epoch().count());

Individual::Individual(const LocationRoutingSolution &solution, double p_mut, double p_cross,
                       const vector<double> &i_mut) : solution(solution), p_mut(p_mut), p_cross(p_cross),
                                                      i_mut(i_mut) {}

Individual::Individual(LocationRoutingProblem &problem, LocationRoutingSolution &sol) : solution(sol) {
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    p_cross = distribution(generator);
    p_mut = 1 - p_cross;

    for(int i = 0; i < problem.getN_node(); i++){
        i_mut.push_back(distribution(generator));
    }
    //i_mut.assign(problem.getN_node(), distribution(generator));
}

void Individual::display(LocationRoutingProblem &problem) {
    //cout << "\n************ SOLUTION ************" << endl;
    /*cout << "\nNumber of Hubs: " << solution.getN_hub();
    cout << "\nHubs List: ";
    for(auto i : solution.getHubs()){
        cout << i << " ";
    }
    cout << "\nHubs: ";
    for(int i = 0; i < problem.getN_node(); i++){
        cout << solution.getIs_hub()[i] << " ";
    }
    cout << "\nAssociated Hubs: ";
    for(int i = 0; i < problem.getN_node(); i++){
        cout << solution.getWhat_hub()[i] << " ";
    }
    cout << "\nSolution Cost: " << solution.getCost() << endl;*/
    cout << "\nCrossover P: " << p_cross;
    cout << "\nMutation P: " << p_mut;
    cout << "\nMutation Intensity: ";

    for(int i = 0; i < i_mut.size(); i++){
        cout << i_mut[i] << " ";
    }
}

LocationRoutingSolution &Individual::getSolution() {
    return solution;
}

double Individual::getP_mut() const {
    return p_mut;
}

double Individual::getP_cross() const {
    return p_cross;
}

void Individual::setP_mut(double p_mut) {
    Individual::p_mut = p_mut;
}

void Individual::setP_cross(double p_cross) {
    Individual::p_cross = p_cross;
}

const vector<double> &Individual::getI_mut() const {
    return i_mut;
}

void Individual::setI_mut(const vector<double> &i_mut) {
    Individual::i_mut = i_mut;
}

vector<double> &Individual::getI_mut() {
    return i_mut;
}
