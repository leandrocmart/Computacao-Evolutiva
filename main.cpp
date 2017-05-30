#include <iostream>
#include "LocationRoutingProblem.h"
#include "LocationRoutingSolution.h"
#include "GA.h"

int main() {
    //string input = "AP20.txt"; //argv[1];
    string input = "inst_25_600_80_60_6_1_40cab.txt"; //argv[1];
    string output = input + "_out.txt";
    //LocationRoutingProblem problem(input.c_str(), output.c_str()); //Base de dados "Australia Post"
    LocationRoutingProblem problem(input.c_str(), output.c_str()); //Base de dados "CAB"
    //problem.display();
    GA ga(problem, 400, 0.7);
    //LocationRoutingSolution solution(problem, 3); //1 é a quantidade de hubs da solução inicial
    //solution.display(problem);
    return 0;
}