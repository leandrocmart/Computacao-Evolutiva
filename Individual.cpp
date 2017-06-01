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

void Individual::mutation(LocationRoutingProblem &problem, Individual &offspring1, Individual &offspring2, Individual &parent1, Individual &parent2, double alpha_p) {
    vector<double> aux_i_mut1(problem.getN_node(), 0), aux_i_mut2(problem.getN_node(), 0);

    /*offspring1.setP_mut(parent1.getP_mut()*alpha_p+parent2.getP_mut()*(1-alpha_p));
    offspring2.setP_mut(parent2.getP_mut()*alpha_p+parent1.getP_mut()*(1-alpha_p));
    offspring1.setP_cross(1 - offspring1.getP_mut());
    offspring2.setP_cross(1 - offspring2.getP_mut());*/

    for(unsigned int l = 0; l < offspring1.getI_mut().size(); l++){
        aux_i_mut1[l] = offspring1.getI_mut()[l]*alpha_p+offspring2.getI_mut()[l]*(1-alpha_p);
    }

    for(unsigned int l = 0; l < offspring2.getI_mut().size(); l++){
        aux_i_mut2[l] = offspring2.getI_mut()[l]*alpha_p+offspring1.getI_mut()[l]*(1-alpha_p);
    }

    offspring1.setI_mut(aux_i_mut1);
    offspring2.setI_mut(aux_i_mut2);

    offspring1.getSolution().mutation(problem, offspring1.getI_mut());
    offspring2.getSolution().mutation(problem, offspring2.getI_mut());
}