//
// Created by Leandro on 11/05/2017.
//

#include "LocationRoutingProblem.h"

LocationRoutingProblem::LocationRoutingProblem(const char *input, const char *output) {
    total_flow = total_distance =  total_cost_flow = 0;
    //read(input);
    readCAB(input);
    //display();
}

int LocationRoutingProblem::getN_node() const {
    return n_node;
}

const vector<vector<double>> &LocationRoutingProblem::getFlow() const {
    return flow;
}

const vector<vector<double>> &LocationRoutingProblem::getCostFlow() const {
    return cost_flow;
}

const vector<pair<double, double>> &LocationRoutingProblem::getCoordenates() const {
    return coordenates;
}

const vector<vector<double>> &LocationRoutingProblem::getDistances() const {
    return distances;
}

double LocationRoutingProblem::getX() const {
    return x;
}

double LocationRoutingProblem::getAlfa() const {
    return alfa;
}

double LocationRoutingProblem::getDelta() const {
    return delta;
}

void LocationRoutingProblem::read(const char* input, int n_node) {
    ifstream fin(input);

    if (fin.is_open()) {
        string ch;
        char *v_aux;
        int i, j, w;
        double c;
        vector<double> aux_flow;
        vector<double> aux_cost;
        aux_flow.assign(n_node, 0);
        aux_cost.assign(n_node, 0);
        flow.assign(n_node, aux_flow);
        cost_flow.assign(n_node, aux_cost);
        //setN_nodes(atoi(ch.c_str()));

        do{
            getline(fin, ch);
            v_aux = strtok(strdup(ch.c_str()), " \t");
            i = atoi(v_aux);
            //cout << v_aux << endl;
            v_aux = strtok(NULL, " \t");
            j = atoi(v_aux);
            //cout << v_aux << endl;
            v_aux = strtok(NULL, ". \t");
            w = atoi(v_aux);
            //cout << v_aux << endl;
            v_aux = strtok(NULL, " \t;");
            c = atof(v_aux);
            //cout << v_aux << endl;
            flow[i-1][j-1]=w;
            cost_flow[i-1][j-1]=c;
        } while(!fin.eof());

    } else {
        cout << "Error opening file." << endl;
    }

    fin.close();
}

void LocationRoutingProblem::readAP(const char* input) {
    ifstream fin(input);

    if (fin.is_open()) {
        string ch;
        char *v_aux;
        int n_hub;
        double c, xi, yi, wij;
        pair<double, double> auxCoordenate;
        vector<double> aux_flow, aux_cost, aux_distances;
        //setN_nodes(atoi(ch.c_str()));

        getline(fin, ch);
        n_node = atoi(ch.c_str());
        aux_flow.assign(n_node, 0);
        aux_cost.assign(n_node, 0);
        aux_distances.assign(n_node, 0);
        flow.assign(n_node, aux_flow);
        cost_flow.assign(n_node, aux_cost);
        distances.assign(n_node, aux_distances);

        for(int i = 0; i < getN_node(); i++){
            getline(fin, ch);
            v_aux = strtok(strdup(ch.c_str()), " \t");
            xi = atof(v_aux);
            v_aux = strtok(NULL, " \t");
            yi = atof(v_aux);
            //cout << xi << " - " << yi << endl;
            auxCoordenate = make_pair(xi, yi);
            coordenates.push_back(auxCoordenate);
        }

        distanceCalculation(coordenates, distances);

        for(int i = 0; i < getN_node(); i++) {
            getline(fin, ch);
            v_aux = strtok(strdup(ch.c_str()), " \t");
            wij = atof(v_aux);
            flow[i][0] = wij;
            for (int j = 1; j < getN_node(); j++) {
                v_aux = strtok(NULL, " \t");
                wij = atof(v_aux);
                flow[i][j] = wij;
            }
        }
        /*for(int i = 0; i < getN_node(); i++){
            for(int j = 0; j < getN_node(); j++){
                cout << flow[i][j] << "\t";
            }
            cout << endl;
        }*/

        getline(fin, ch);
        v_aux = strtok(strdup(ch.c_str()), " \t");
        n_hub = atoi(v_aux);

        getline(fin, ch);
        v_aux = strtok(strdup(ch.c_str()), " \t");
        x = atof(v_aux);

        getline(fin, ch);
        v_aux = strtok(strdup(ch.c_str()), " \t");
        alfa = atof(v_aux);

        getline(fin, ch);
        v_aux = strtok(strdup(ch.c_str()), " \t");
        delta = atof(v_aux);
    }
    else {
        cout << "Error opening file." << endl;
    }

    fin.close();
}

void LocationRoutingProblem::distanceCalculation(vector<pair<double, double>> &coordenates, vector<vector<double>> &distances){
    double dij;

    for(int i = 0; i < getN_node(); i++){
        for(int j = i + 1; j < getN_node(); j++) {
            dij = sqrt(pow((coordenates[i].first - coordenates[i].second), 2) + pow((coordenates[j].first - coordenates[j].second), 2));
            distances[i][j] = distances[j][i] = dij/1000;
        }
    }

   /* for(int i = 0; i < getN_node(); i++){
        for(int j = 0; j < getN_node(); j++){
            cout << distances[i][j] << "\t";
        }
        cout << endl;
    }*/
}

void LocationRoutingProblem::readCAB(const char* input) {
    ifstream fin(input);

    if (fin.is_open()) {
        string ch;
        char *v_aux;
        int n_hub;
        double a, b, c, wij, dij, cij;
        pair<double, double> auxCoordenate;
        vector<double> aux_flow, aux_cost, aux_distances;
        //setN_nodes(atoi(ch.c_str()));

        getline(fin, ch);
        n_node = atoi(ch.c_str());
        aux_flow.assign(n_node, 0);
        aux_cost.assign(n_node, 0);
        aux_distances.assign(n_node, 0);
        flow.assign(n_node, aux_flow);
        cost_flow.assign(n_node, aux_cost);
        distances.assign(n_node, aux_distances);

        getline(fin, ch);

        for(int i = 0; i < getN_node(); i++) {
            getline(fin, ch);
            v_aux = strtok(strdup(ch.c_str()), " \t");
            wij = atof(v_aux);
            total_flow+=wij;
            flow[i][0] = wij;
            for (int j = 1; j < getN_node(); j++) {
                v_aux = strtok(NULL, " \t");
                wij = atof(v_aux);
                flow[i][j] = wij;
                total_flow+=wij;
            }
        }

        getline(fin, ch);

        for(int i = 0; i < getN_node(); i++) {
            getline(fin, ch);
            v_aux = strtok(strdup(ch.c_str()), " \t");
            cij = atof(v_aux);
            if(i!=0)
            total_cost_flow += cij;
            cost_flow[i][0] = cij;
            for (int j = 1; j < getN_node(); j++) {
                v_aux = strtok(NULL, " \t");
                cij = atof(v_aux);
                cost_flow[i][j] = cij;
                if(i!=j)
                total_cost_flow += cij;
            }
        }

        getline(fin, ch);

        for(int i = 0; i < getN_node(); i++) {
            getline(fin, ch);
            v_aux = strtok(strdup(ch.c_str()), " \t");
            dij = atof(v_aux);
            total_distance += dij;
            distances[i][0] = dij;
            for (int j = 1; j < getN_node(); j++) {
                v_aux = strtok(NULL, " \t");
                dij = atof(v_aux);
                distances[i][j] = dij;
                total_distance += dij;
            }
        }

        getline(fin, ch);

        getline(fin, ch);
        v_aux = strtok(strdup(ch.c_str()), " \t");
        a = atof(v_aux);

        getline(fin, ch);
        v_aux = strtok(strdup(ch.c_str()), " \t");
        b = atof(v_aux);

        getline(fin, ch);
        v_aux = strtok(strdup(ch.c_str()), " \t");
        c = atof(v_aux);
    }
    else {
        cout << "Error opening file." << endl;
    }

    x = delta = 1;
    alfa = 0.2;

    //cout << total_flow <<" " << total_cost_flow << " " << total_distance << endl;
    fin.close();
}


void LocationRoutingProblem::display() {
    cout << "\n************ LRP DATA ************" << endl << endl;
    cout << "Problem Size (number of nodes): " << getN_node() << endl;
    cout << "\nFlow Matrix: " << endl;

    for(int i = 0; i < getN_node(); i++){
        for(int j = 0; j < getN_node(); j++){
            cout << getFlow()[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nCost Flow Matrix: " << endl;
    for(int i = 0; i < getN_node(); i++){
        for(int j = 0; j < getN_node(); j++){
            cout << getCostFlow()[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nDistances Matrix: " << endl;
    for(int i = 0; i < getN_node(); i++){
        for(int j = 0; j < getN_node(); j++){
            cout << getDistances()[i][j] << " ";
        }
        cout << endl;
    }

    /*cout << "\nTransportation Coefficients: " << endl;
    cout << "X: " << getX() << "\nAlfa: " << getAlfa() << "\nDelta: " << getDelta() << endl;*/
}