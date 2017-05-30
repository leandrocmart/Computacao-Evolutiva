//
// Created by Leandro on 15/05/2017.
//

#include "GA.h"

default_random_engine GA::generator((int) chrono::system_clock::now().time_since_epoch().count());

GA::GA(LocationRoutingProblem &problem, int pop_size, double cp) {
    population_size = pop_size;
    cross_p = cp;
    mut_p =  1 - cp;
    competicao_pais_filhos = true;
    //int parent1, parent2;
    //LocationRoutingSolution offspring1(problem), offspring2(problem);

    createInitialPopulation(problem);
    //display(problem);
    //getchar();
    //system("pause");
    //parent1 = tournamentSelection(population, 2);
    //parent2 = tournamentSelection(population, 2);
    //cout << "* " << parent1 << " " << parent2 << endl;

    //offspring2 = population[parent1].crossover(problem, population[parent2], offspring1, 1);

    run(problem, 1000);

    /*for(int i = 0; i < population[parent1].getIs_hub().size(); i++){
        cout << population[parent1].getIs_hub()[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < population[parent2].getIs_hub().size(); i++){
        cout << population[parent2].getIs_hub()[i] << " ";
    }

    cout << "\nFilho 1: " << endl;
    offspring1.display(problem);
    cout << "\nFilho 2: " << endl;
    offspring2.display(problem);*/
}

int GA::getPopulation_Size() const {
    return population_size;
}

double GA::getCross_p() const {
    return cross_p;
}

double GA::getMut_p() const {
    return mut_p;
}

bool GA::isCompeticao_pais_filhos() const {
    return competicao_pais_filhos;
}

void GA::createInitialPopulation(LocationRoutingProblem &problem) {
    for(int i = 0; i < getPopulation_Size(); i++){
        LocationRoutingSolution solution(problem, 2);
        population.push_back(solution);
    }
}

void GA::display(LocationRoutingProblem &problem) {
    cout << "\n\n*************** GA ***************" << endl;
    for(int i = 0; i < population.size(); i++){
        cout << "\nSolution " << i + 1;
        population[i].display(problem);
    }
}

int GA::tournamentSelection(vector<LocationRoutingSolution> &population, int tournament_size) {
    vector<int> indexes(tournament_size, -1); //Inicializa o vetor que salvará os índices das soluções a serem escolhidas para o Torneio
    int random_index, solution;
    int j = 0;
    double cost = std::numeric_limits<double>::infinity(); //Infinito
    /*unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    static std::default_random_engine generator(seed);*/
    std::uniform_int_distribution<int> distribution_int(0, population.size() - 1); //Sorteia no intervalo

    //Preenche o vetor de índices com n índices diferentes
    while (j < tournament_size) {
        int count = 0;
        random_index = distribution_int(generator);
        //cout << random_index << " ";
        for (int i = 0; i < tournament_size; i++) {
            if (random_index == indexes[i]) {
                count++;
                break;
            }
        }
        if (count == 0) {
            indexes[j] = random_index;
            j++;
        }
    }

    /*cout << "\n\nIndexes: ";
    for(int i = 0; i < indexes.size(); i++){
        cout << indexes[i] << "-" << population[indexes[i]].getCost() << " ";
    }
    cout << endl;*/

    //Dentre os índices escolhidos, escolhe a melhor solução, ou seja, com menor FO
    for (int i = 0; i < tournament_size; i++) {
        int index = indexes[i];

        if (cost > population[index].getCost()) {
            cost = population[index].getCost();
            solution = index;
        }
    }

    return solution;
}

int GA::rouletteSelection(vector<LocationRoutingSolution> &population) {
    double r, aux = 0;
    /*unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    static std::default_random_engine generator(seed);*/
    std::uniform_real_distribution<double> distribution(0.0, 1.0);

    vector<double> probabilities;
    vector<double> interval;
    double total_fitness = 0;
    int solution;

    for (int i = 0; i < population.size(); i++) {
        total_fitness += population[i].getCost();
    }

    for (int i = 0; i < population.size(); i++) {
        probabilities.push_back(population[i].getCost() / total_fitness);
    }

    interval.push_back(0);

    for (auto i : probabilities) {
        aux += i;
        interval.push_back(aux);
    }

    r = distribution(generator);

    for (unsigned int i = 0; i < interval.size(); i++) {
        if (r < interval[i]) {
            solution = i - 1;
            break;
        }
    }

    return solution;
}

void GA::run(LocationRoutingProblem &problem, int generation_size) {
    int parent1, parent2, survivor, size, n_elite;
    vector<LocationRoutingSolution> new_population, elite;
    LocationRoutingSolution best_solution(problem);
    /*unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    static std::default_random_engine generator(seed);*/
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    n_elite = (int) (population.size() * 0.1);

    for(int i = 0; i < generation_size; i++){
        findBest(best_solution);
        cout << "\n************ Iteration " << i + 1 << " ************";
        best_solution.display(problem);
        //display(problem);
        elite = elitism(population, n_elite, problem); //Melhores "n_elite" soluções entre pais
        size = population.size()/2;

        for(int k = 0; k < size; k++) {
            LocationRoutingSolution offspring1(problem), offspring2(problem);
            parent1 = tournamentSelection(population, 3);
            parent2 = tournamentSelection(population, 3);

            if (distribution(generator) < getCross_p()) {
                /*cout << "\nParents: " << endl;
                population[parent1].display(problem);
                population[parent2].display(problem);*/
                /*cout << "\n\n---------------------------- 0 - Pai 1:" << endl;
                population[parent1].display(problem);//offspring1.display(problem);
                cout << "\n\n---------------------------- 0 - Pai 2:" << endl;
                population[parent2].display(problem);//offspring1.display(problem);*/

                offspring2 = population[parent1].crossoverUniform(problem, population[parent2], offspring1, 2);

                /*cout << "\n\n---------------------------- 3 - Filho 1 depois do cruzamento" << endl;
                offspring1.display(problem);
                cout << "\n\n---------------------------- 3 - Filho 2 depois do cruzamento" << endl;
                offspring2.display(problem);*/
                /* cout << "\nOffsprings 1: " << endl;
                 offspring1.display(problem);
                 offspring2.display(problem);*/
                //system("pause");
            } else { //mp = 1 - cp
                offspring1 = population[parent1];
                offspring2 = population[parent2];
                offspring1.mutation(problem);
                offspring2.mutation(problem);
            }
            //cout << 3 << endl;
            //cout << "\nOffsprings 2: " << endl;
            /*cout << "O1.1" << endl;
            offspring1.display(problem);
            cout << "O2" << endl;
            offspring2.display(problem);*/

            offspring1.evaluateSolution(problem);
            offspring2.evaluateSolution(problem);
            //cout << 3.1 << endl;
            //cout << offspring1.getCost() << " | " << offspring2.getCost() << endl;
            population.push_back(offspring1);
            population.push_back(offspring2);
            //cout << 4 << endl;
        }

        //display(problem);
        if(isCompeticao_pais_filhos()) {
            for (int j = 0; j < getPopulation_Size(); j++) {
                survivor = tournamentSelection(population, 5);
                new_population.push_back(population[survivor]);
            }
        } else {
            new_population.assign(population.begin() + population_size/2, population.end());
        }

        removeWorst(new_population, n_elite); //Remove as "n_elite" piores soluções
        //cout << "NP: " << new_population.size() << " " << elite.size();

        for(int j = 0; j < elite.size(); j++) { //Adiciona as melhores soluções salvas no "elite"
            new_population.push_back(elite[j]);
        }

        //cout << "NP: " << new_population.size() << " ";
        /*cout << "\n * " << new_population.size() << " " << population.size() << endl;
        for(int j = 0; j < population.size(); j++){
            cout << population[j].getCost() << " ";
        }*/

        elite.clear();
        population.clear();
        population.assign(new_population.begin(), new_population.end());
        new_population.clear();
    }
}

void GA::findBest(LocationRoutingSolution &best_solution){
    double OF = std::numeric_limits<double>::infinity();
    int best = 0;

    for(int i = 0; i < population.size(); i++){
        if(population[i].getCost() < OF){
            OF = population[i].getCost();
            best = i;
        }
    }

    best_solution = population[best];
}


bool sortCost(LocationRoutingSolution i, LocationRoutingSolution j) {
    return (i.getCost() < j.getCost());
}

vector<LocationRoutingSolution> GA::elitism(vector<LocationRoutingSolution> &population, int n_elite, LocationRoutingProblem &problem){
    vector<LocationRoutingSolution> elite;
    sort(population.begin(), population.end(), sortCost);

    /*cout << "N Size: " << population.size() * elite_percentage << endl;
    cout << "Elite Size 1.1: " << elite.size() << endl;*/

    for(int i = 0; i < n_elite; i++){
        elite.push_back(population[i]);
    }

    /*for(int i = 0; i < elite.size(); i++){
        elite[i].display(problem);
    }
    cout << "Elite Size 2: " << elite.size() << endl;*/

    return elite;
}

void GA::removeWorst(vector<LocationRoutingSolution> &population, int n_elite){
    sort(population.begin(), population.end(), sortCost);

    for(int i = 0; i < n_elite; i++){
        population.pop_back();
    }
}