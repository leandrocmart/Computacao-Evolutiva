//
// Created by Leandro on 11/05/2017.
//

#include "LocationRoutingSolution.h"

/*double randDouble(double a, double b) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    static std::default_random_engine generator (seed);
    std::uniform_real_distribution<double> distribution(a, b);
    return distribution(generator);
}

int randInt(int a, int b) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    static std::default_random_engine generator (seed);
    std::uniform_int_distribution<int> distribution(a, b-1);
    return distribution(generator);
}*/

default_random_engine LocationRoutingSolution::generator((int) chrono::system_clock::now().time_since_epoch().count());

LocationRoutingSolution::LocationRoutingSolution(LocationRoutingProblem &problem, int n) {
    n_hub = 0;
    cost = 0;
    is_hub.assign(problem.getN_node(), 0);
    what_hub.assign(problem.getN_node(), 0);
    createSolution(problem, n);
    evaluateSolution(problem);
    //display(problem);
    //mutation(problem, 0.2);
    //evaluateSolution(problem);
    //display(problem);
}

LocationRoutingSolution::LocationRoutingSolution(LocationRoutingProblem &problem) {
    n_hub = 0;
    cost = 0;
    is_hub.assign(problem.getN_node(), 0);
    what_hub.assign(problem.getN_node(), 0);
}

/*LocationRoutingSolution::LocationRoutingSolution(const LocationRoutingSolution &other){
    this->is_hub = other.getIs_hub(); //qual nó é concentrador
    this->what_hub = other.getWhat_hub(); //qual concentrador está associado a cada nó
    this->hubs = other.getHubs();
    this->n_hub = other.getN_hub(); //números de nós
    this->cost = other.getCost(); //custo da solução
    this->generator = other.getGenerator();
}*/

const vector<int> &LocationRoutingSolution::getIs_hub() const {
    return is_hub;
}

const vector<int> &LocationRoutingSolution::getWhat_hub() const {
    return what_hub;
}

const list<int> &LocationRoutingSolution::getHubs() const {
    return hubs;
}

int LocationRoutingSolution::getN_hub() const {
    return n_hub;
}

double LocationRoutingSolution::getCost() const {
    return cost;
}

vector<int> &LocationRoutingSolution::changeIs_hub() {
    return is_hub;
}

list<int> &LocationRoutingSolution::changeHubs() {
    return hubs;
}

vector<int> &LocationRoutingSolution::changeWhat_hub() {
    return what_hub;
}

void LocationRoutingSolution::display(LocationRoutingProblem &problem) {
    //cout << "\n************ SOLUTION ************" << endl;
    cout << "\nNumber of Hubs: " << getN_hub();
    cout << "\nHubs List: ";
    for(auto i : hubs){
        cout << i << " ";
    }
    cout << "\nHubs: ";
    for(int i = 0; i < problem.getN_node(); i++){
        cout << getIs_hub()[i] << " ";
    }
    cout << "\nAssociated Hubs: ";
    for(int i = 0; i < problem.getN_node(); i++){
        cout << getWhat_hub()[i] << " ";
    }
    cout << "\nSolution Cost: " << getCost() << endl;
}

int LocationRoutingSolution::searchHub(int node) {
    //cout << "$" << what_hub[node] << endl;
    return what_hub[node];
}

void LocationRoutingSolution::createSolution(LocationRoutingProblem &problem, int n) {
    int m; //Número de hubs a serem alocados
    //int max_m = problem.getN_node()/2, min_m = n; //Define o intervalo da quantidade possível de hubs
    int max_m = problem.getN_node(), min_m = n; //Define o intervalo da quantidade possível de hubs
    //unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    //std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution_int(min_m, max_m); //Sorteia no intervalo
    std::uniform_int_distribution<int> distribution(0,  problem.getN_node()-1); //Sorteia no intervalo
    is_hub.assign(problem.getN_node(), 0);
    what_hub.assign(problem.getN_node(), 0);
    int hub;

    m = distribution_int(generator);//(min_m, max_m);
    //cout << m << " " << max_m << " " << min_m << endl;
    for(int i = 0; i < m; i++) {
        hub = distribution(generator);//randInt(0, problem.getN_node());
        //cout << hub << endl;
        if (is_hub[hub] == 0) {
            is_hub[hub] = 1;
            hubs.push_back(hub);
            n_hub++;
        } else {
            i--;
        }
        //what_hub.assign(problem.getN_node(), hub);
    }

    whatHubUpdate(problem);

    /*cout << "Hub: \t";
    for(int i = 0; i < problem.getN_node(); i++)
        cout << is_hub[i] << "\t";

    cout << endl << "WHub: \t";
    for(int i = 0; i < problem.getN_node(); i++)
        cout << what_hub[i] << "\t";*/
}

void LocationRoutingSolution::evaluateSolution(LocationRoutingProblem &problem) {
    double cij = 0;
    int hub_i = 0, hub_j = 0;

    /* for(auto i : what_hub)
         cout << " i: " << i ;*/

    for(int i = 0; i < problem.getN_node(); i++){
        hub_i = searchHub(i);
        if(hub_i == i){
            //cost += problem.getCostFlow()[hub_i][i];
            cost += 100;
        }
        for(int j = 0; j < problem.getN_node(); j++){
            hub_j = searchHub(j);
            //cout << "W: " << problem.getFlow()[i][j] << " - D_ihi: " << i << ":" << hub_i << " " << problem.getDistances()[i][hub_i] << " - D_hihj: " << hub_i << ":" << hub_j << " " << problem.getDistances()[hub_i][hub_j] << " - D_hjj: " << hub_j << ":" << j << " " << problem.getDistances()[hub_j][j];
            cij = (problem.getFlow()[i][j]/problem.total_flow) * (problem.getX() * problem.getDistances()[i][hub_i] + problem.getAlfa() * problem.getDistances()[hub_i][hub_j] + problem.getDelta() * problem.getDistances()[hub_j][j]);
            //cout << " * " << cij << endl;
            cost += cij;
        }
    }
    //cost = cost/1000;
}

void LocationRoutingSolution::whatHubUpdate(LocationRoutingProblem &problem){
    double shorter_distance;
    int shorter_i_hub = 0;

    for(int i = 0; i < problem.getN_node(); i++){
        shorter_distance = std::numeric_limits<double>::infinity();
        for(auto j : hubs){
            //cout << problem.getDistances()[i][j] << " ";
            if(problem.getDistances()[i][j] < shorter_distance){
                shorter_distance = problem.getDistances()[i][j];
                shorter_i_hub = j;
            }
        }
        what_hub[i] = shorter_i_hub;
        //cout << endl;
    }
}

void LocationRoutingSolution::mutation(LocationRoutingProblem &problem){
    /*unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    static std::default_random_engine generator(seed);*/
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    double mp = 1 / problem.getN_node(); //mp = probabilidade de mutar apenas um gene

    for(int i = 0; i < problem.getN_node(); i++){
        if(distribution(generator) < mp){//randDouble(0, 1) < mp){
            if(is_hub[i] == 1){ // Um concentrador deixa de ser concentrador...
                is_hub[i] = 0;
                hubs.remove(i);
                n_hub--;
            } else { // Um não concentrador passa a ser concentrador...
                is_hub[i] = 1;
                hubs.push_back(i);
                n_hub++;
            }
        }
    }
    whatHubUpdate(problem);
    //Atualizar concentradores associados....
}

LocationRoutingSolution LocationRoutingSolution::crossoverNPoint(LocationRoutingProblem &problem, LocationRoutingSolution &parent2, LocationRoutingSolution &offspring1, int n) {
    LocationRoutingSolution offspring2(problem);
    int cut; //Ponto de corte
    /*unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    static std::default_random_engine generator(seed);*/
    std::uniform_int_distribution<int> distribution_int(0, problem.getN_node() - 1); //Sorteia no intervalo

    vector<int> cuts;
    cuts.push_back(0);
    cuts.push_back(problem.getN_node());

    while(cuts.size() < n + 2) {
        cut = distribution_int(generator);//randInt(0, problem.getN_node());
        if(find(cuts.begin(), cuts.end(), cut) == cuts.end()){
            cuts.push_back(cut);
        }
    }

    sort(cuts.begin(), cuts.end());

/*    cout << "\nCuts: ";
    for(int i = 0; i < cuts.size(); i++){
        cout << cuts[i] << " ";
    }
    cout << endl;*/

    for (int k = 0; k < n + 1; k++) {
        if (k % 2 == 0) {
            for (int j = cuts[k]; j < cuts[k + 1]; j++) {
                offspring1.changeIs_hub()[j] = getIs_hub()[j];

                if(getIs_hub()[j]==1){
                    offspring1.hubs.push_back(j);
                }
            }
        } else {
            for (int j = cuts[k]; j < cuts[k + 1]; j++) {
                offspring1.changeIs_hub()[j] = parent2.getIs_hub()[j];

                if(parent2.getIs_hub()[j]==1){
                    offspring1.hubs.push_back(j);
                }
            }
        }
    }

    for (int k = 0; k < n + 1; k++) {
        if (k % 2 == 0) {
            for (int j = cuts[k]; j < cuts[k + 1]; j++) {
                offspring2.changeIs_hub()[j] = parent2.getIs_hub()[j];

                if(parent2.getIs_hub()[j]==1){
                    offspring2.hubs.push_back(j);
                }
            }
        } else {
            for (int j = cuts[k]; j < cuts[k + 1]; j++) {
                offspring2.changeIs_hub()[j] = getIs_hub()[j];

                if(getIs_hub()[j]==1){
                    offspring2.hubs.push_back(j);
                }
            }
        }
    }

    /*for (int i = 0; i < problem.getN_node(); i++) {
        if (i < cut) {
            offspring2.changeIs_hub()[i] = parent2.getIs_hub()[i];
            offspring1.changeIs_hub()[i] = getIs_hub()[i];

            if(parent2.getIs_hub()[i]==1){
                offspring2.hubs.push_back(i);
            }
            if(getIs_hub()[i]==1){
                offspring1.hubs.push_back(i);
            }
        } else {
            offspring2.changeIs_hub()[i] = getIs_hub()[i];
            offspring1.changeIs_hub()[i] = parent2.getIs_hub()[i];

            if(parent2.getIs_hub()[i]==1){
                offspring1.hubs.push_back(i);
            }
            if(getIs_hub()[i]==1){
                offspring2.hubs.push_back(i);
            }
        }
    }*/

    /*cout << "\nWH: " << endl;
    for(int i = 0; i < offspring1.getWhat_hub().size(); i++){
        cout << offspring1.getWhat_hub()[i] << " ";
    }*/

    offspring1.whatHubUpdate(problem); //Atualiza concentradores associados
    offspring2.whatHubUpdate(problem);

    /*cout << "\nWH: " << endl;
    for(int i = 0; i < offspring1.getWhat_hub().size(); i++){
        cout << offspring1.getWhat_hub()[i] << " ";
    }*/

    return offspring2;
}

LocationRoutingSolution LocationRoutingSolution::crossoverUniform(LocationRoutingProblem &problem, LocationRoutingSolution &parent2, LocationRoutingSolution &offspring1, int n) {
    LocationRoutingSolution offspring2(problem);
    /*unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    static std::default_random_engine generator(seed);*/
    std::uniform_real_distribution<double> distribution(0.0, 1.0);

    /*cout << "\n\n---------------------------- 1 - Filho 1 antes do cruzamento:" << endl;
    offspring1.display(problem);//offspring1.display(problem);
    cout << "\n\n---------------------------- 1 - Filho 2 antes do cruzamento:" << endl;
    offspring2.display(problem);//offspring1.display(problem);*/


    for (int i = 0; i < problem.getN_node(); i++) {
        if (distribution(generator) < 0.5) {
            //cout << " if " << is_hub[i] << " " << parent2.is_hub[i];
            offspring2.is_hub[i] = is_hub[i];
            offspring1.is_hub[i] = parent2.is_hub[i];
        } else {
            //cout << " else " << is_hub[i] << " " << parent2.is_hub[i];
            offspring2.is_hub[i] = parent2.is_hub[i];
            offspring1.is_hub[i] = is_hub[i];
        }
    }

    for (int i = 0; i < problem.getN_node(); i++) {
        if (offspring1.is_hub[i] == 1) {
            offspring1.hubs.push_back(i);
        }
        if (offspring2.is_hub[i] == 1) {
            offspring2.hubs.push_back(i);
        }
    }

    /*cout << "\n\n---------------------------- 2 - Filho 1 depois do cruzamento, antes de updateHubs:" << endl;
    offspring1.display(problem);//offspring1.display(problem);
    cout << "\n\n---------------------------- 2 - Filho 2 depois do cruzamento, antes de updateHubs:" << endl;
    offspring2.display(problem);//offspring1.display(problem);*/

    offspring1.whatHubUpdate(problem); //Atualiza concentradores associados
    offspring2.whatHubUpdate(problem);

    /*cout << "\n\n---------------------------- 2.1 - Filho 1 depois do cruzamento, depois de updateHubs:" << endl;
    offspring1.display(problem);//offspring1.display(problem);
    cout << "\n\n---------------------------- 2.1 - Filho 2 depois do cruzamento, depois de updateHubs:" << endl;
    offspring2.display(problem);//offspring1.display(problem);*/

    return offspring2;
}

void LocationRoutingSolution::reset(LocationRoutingProblem &problem){
    n_hub = 0;
    cost = 0;
    is_hub.clear();
    what_hub.clear();
    hubs.clear();
    is_hub.assign(problem.getN_node(), 0);
    what_hub.assign(problem.getN_node(), 0);
}

const default_random_engine &LocationRoutingSolution::getGenerator() {
    return generator;
}
