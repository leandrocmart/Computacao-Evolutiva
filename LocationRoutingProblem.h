//
// Created by Leandro on 04/05/2017.
//

#ifndef CE_LRP_LOCATIONROUTINGP_H
#define CE_LRP_LOCATIONROUTINGP_H

#include <vector>
#include <list>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <fstream>
#include <string.h>
#include <time.h>
#include <chrono>

using namespace std;

class LocationRoutingProblem {
public:
    LocationRoutingProblem(const char* input, const char* output);
    int getN_node() const;
    const vector<vector<double>> &getFlow() const;
    const vector<vector<double>> &getCostFlow() const;
    const vector<pair<double, double>> &getCoordenates() const;
    const vector<vector<double>> &getDistances() const;
    double getX() const;
    double getAlfa() const;
    double getDelta() const;
    void read(const char* input, int n_node);
    void readAP(const char* input);
    void readCAB(const char* input);
    void distanceCalculation(vector<pair<double, double>> &coordenates, vector<vector<double>> &distances);
    void display();
    double total_flow, total_distance, total_cost_flow;
private:
    int n_node; //número de nós do problema
    vector<vector<double>> flow;; //matriz de fluxo para cada par de nó (origem, destino)
    vector<vector<double>> cost_flow; //tabela de custo para cada unidade de fluxo, para cada par de nó (origem, destino)
    vector<pair<double, double>> coordenates; //vetor de coordenadas para cálculo das distâncias
    vector<vector<double>> distances; //matriz de distâncias
    double x, alfa, delta; //coeficientes de transporte
};

#endif //CE_LRP_LOCATIONROUTINGP_H
