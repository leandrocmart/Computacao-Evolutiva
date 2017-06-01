//
// Created by leandro on 01/06/17.
//

#include "AE.h"

default_random_engine AE::generator((int) chrono::system_clock::now().time_since_epoch().count());

AE::AE(LocationRoutingProblem &problem, int pop_size, int generation_size, double a_p) {
    population_size = pop_size;
    //cross_p = cp;
    //mut_p =  1 - cp;
    competicao_pais_filhos = true;
    //int parent1, parent2;
    //LocationRoutingSolution offspring1(problem), offspring2(problem);
    alpha_p = a_p;
    createInitialPopulation(problem);
    //display(problem);
    //getchar();

    run(problem, generation_size);
}

int AE::getPopulation_Size() const {
    return population_size;
}

double AE::getAlpha_p() const {
    return alpha_p;
}

bool AE::isCompeticao_pais_filhos() const {
    return competicao_pais_filhos;
}

void AE::createInitialPopulation(LocationRoutingProblem &problem) {
    for(int i = 0; i < getPopulation_Size(); i++){
        LocationRoutingSolution solution(problem, 2);
        Individual individual(problem, solution);
        population.push_back(individual);
    }
}

void AE::display(LocationRoutingProblem &problem) {
    cout << "\n\n*************** GA ***************" << endl;
    for(unsigned int i = 0; i < population.size(); i++){
        cout << "\nSolution " << i + 1;
        population[i].display(problem);
    }
}

int AE::tournamentSelection(vector<Individual> &population, int tournament_size) {
    vector<int> indexes(tournament_size, -1); //Inicializa o vetor que salvará os índices das soluções a serem escolhidas para o Torneio
    int random_index, solution = 0;
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
        for(int i = 0; i < tournament_size; i++) {
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
    for(unsigned int i = 0; i < indexes.size(); i++){
        cout << indexes[i] << "-" << population[indexes[i]].getCost() << " ";
    }
    cout << endl;*/

    //Dentre os índices escolhidos, escolhe a melhor solução, ou seja, com menor FO
    for(int i = 0; i < tournament_size; i++) {
        int index = indexes[i];

        if (cost > population[index].getSolution().getCost()) {
            cost = population[index].getSolution().getCost();
            solution = index;
        }
    }

    return solution;
}

int AE::rouletteSelection(vector<Individual> &population) {
    double r, aux = 0;
    /*unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    static std::default_random_engine generator(seed);*/
    std::uniform_real_distribution<double> distribution(0.0, 1.0);

    vector<double> probabilities;
    vector<double> interval;
    double total_fitness = 0;
    int solution = 0;

    for(unsigned int i = 0; i < population.size(); i++) {
        total_fitness += population[i].getSolution().getCost();
    }

    for(unsigned int i = 0; i < population.size(); i++) {
        probabilities.push_back((1 - (population[i].getSolution().getCost() / total_fitness))/(population.size() - 1));
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

vector<int> AE::rouletteSUSSelection(vector<Individual> &population, int n_pins) {
    double r, aux = 0, spacing, total_fitness = 0;
    /*unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    static std::default_random_engine generator(seed);*/
    std::uniform_real_distribution<double> distribution(0.0, 1.0);

    vector<double> probabilities;
    vector<double> interval;
    vector<int> solutions;
    int solution = 0;

    spacing = (double) 1/n_pins;

    for(unsigned int i = 0; i < population.size(); i++) {
        total_fitness += population[i].getSolution().getCost();
    }

    for(unsigned int i = 0; i < population.size(); i++) {
        probabilities.push_back((1 - (population[i].getSolution().getCost() / total_fitness))/(population.size() - 1));
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

    solutions.push_back(solution);
    r += spacing;
    int k = 0;

    for(int i = 1; i < n_pins; i++){
        for (unsigned int j = k; j < interval.size(); j++) {
            if (r < interval[j]) {
                solution = j - 1;
                solutions.push_back(solution);
                if(r + spacing < 1) {
                    r = r + spacing;
                    k = j;
                } else {
                    r = r + spacing - 1;
                    k = 0;
                }
                break;
            }
        }
    }

    /*cout << "\n\nSolutions: ";
    for(auto i : solutions){
        cout << i << " ";
    }*/

    return solutions;
}

void AE::run(LocationRoutingProblem &problem, int generation_size) {
    int parent1, parent2, survivor, size, n_elite;
    double p_c1, p_c2;
    vector<double> aux_i_mut1(problem.getN_node(), 0), aux_i_mut2(problem.getN_node(), 0);
    vector<Individual> new_population, elite;
    LocationRoutingSolution best_sol(problem);
    Individual best_solution(problem, best_sol);
    /*unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    static std::default_random_engine generator(seed);*/
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    n_elite = (int) (population.size() * 0.1);

    for(int i = 0; i < generation_size; i++){
        findBest(best_solution);
        cout << "\n************ Iteration " << i + 1 << " ************";
        //best_solution.display(problem);
        //display(problem);
        elite = elitism(population, n_elite); //Melhores "n_elite" soluções entre pais
        size = (int) population.size()/2;

        for(int k = 0; k < size; k++) {
            LocationRoutingSolution off1(problem), off2(problem);
            Individual offspring1(problem, off1), offspring2(problem, off2);
            parent1 = tournamentSelection(population, 10);
            parent2 = tournamentSelection(population, 3);
            p_c1 = population[parent1].getP_cross();
            p_c2 = population[parent1].getP_cross();

            if (distribution(generator) < (p_c1 + p_c2) / 2) {
                /*cout << "\nCROSSOVER: " << endl;
                cout << "\nParents: " << endl;
                population[parent1].display(problem);
                population[parent2].display(problem);*/

                //Atualiza as taxas de crossover e mutação
                offspring2.getSolution() = population[parent1].getSolution().crossoverUniform(problem, population[parent2].getSolution(), offspring1.getSolution(), 2);
                offspring1.setP_cross(population[parent1].getP_cross()*getAlpha_p()+population[parent2].getP_cross()*(1-getAlpha_p()));
                offspring2.setP_cross(population[parent2].getP_cross()*getAlpha_p()+population[parent1].getP_cross()*(1-getAlpha_p()));
                offspring1.setP_mut(1 - offspring1.getP_cross());
                offspring2.setP_mut(1 - offspring2.getP_cross());

                /*offspring1.display(problem);
                offspring2.display(problem);
                getchar();*/
            } else { //mp = 1 - cp
                /*cout << "\nMUTATION: " << endl;
                population[parent1].display(problem);
                population[parent2].display(problem);*/

                offspring1 = population[parent1];
                offspring2 = population[parent2];

                //Atualiza as taxas de crossover e mutação
                offspring1.setP_mut(population[parent1].getP_mut()*getAlpha_p()+population[parent2].getP_mut()*(1-getAlpha_p()));
                offspring2.setP_mut(population[parent2].getP_mut()*getAlpha_p()+population[parent1].getP_mut()*(1-getAlpha_p()));
                offspring1.setP_cross(1 - offspring1.getP_mut());
                offspring2.setP_cross(1 - offspring2.getP_mut());

                //Faz a mutação dos parâmetros e da solução
                offspring1.mutation(problem, offspring1, offspring2, population[parent1], population[parent2], getAlpha_p());
                offspring2.mutation(problem, offspring1, offspring2, population[parent1], population[parent2], getAlpha_p());

                /*offspring1.display(problem);
                offspring2.display(problem);
                getchar();*/
            }

            offspring1.getSolution().evaluateSolution(problem);
            offspring2.getSolution().evaluateSolution(problem);
            population.push_back(offspring1);
            population.push_back(offspring2);
        }

        //display(problem);
        if(isCompeticao_pais_filhos()) {
            for(int j = 0; j < getPopulation_Size(); j++) {
                survivor = tournamentSelection(population, 5);
                new_population.push_back(population[survivor]);
            }
        } else {
            new_population.assign(population.begin() + population_size/2, population.end());
        }

        removeWorst(new_population, n_elite); //Remove as "n_elite" piores soluções
        //cout << "NP: " << new_population.size() << " " << elite.size();

        for(unsigned int j = 0; j < elite.size(); j++) { //Adiciona as melhores soluções salvas no "elite"
            new_population.push_back(elite[j]);
        }

        //cout << "NP: " << new_population.size() << " ";
        /*cout << "\n * " << new_population.size() << " " << population.size() << endl;
        for(unsigned int j = 0; j < population.size(); j++){
            cout << population[j].getCost() << " ";
        }*/

        elite.clear();
        population.clear();
        population.assign(new_population.begin(), new_population.end());
        new_population.clear();
    }
}

void AE::findBest(Individual &best_solution){
    double OF = std::numeric_limits<double>::infinity();
    int best = 0;

    for(unsigned int i = 0; i < population.size(); i++){
        if(population[i].getSolution().getCost() < OF){
            OF = population[i].getSolution().getCost();
            best = i;
        }
    }

    best_solution = population[best];
}


bool sortCost(Individual i, Individual j) {
    return (i.getSolution().getCost() < j.getSolution().getCost());
}

vector<Individual> AE::elitism(vector<Individual> &population, int n_elite){
    vector<Individual> elite;
    sort(population.begin(), population.end(), sortCost);

    for(int i = 0; i < n_elite; i++){
        elite.push_back(population[i]);
    }

    return elite;
}

void AE::removeWorst(vector<Individual> &population, int n_elite){
    sort(population.begin(), population.end(), sortCost);

    for(int i = 0; i < n_elite; i++){
        population.pop_back();
    }
}