//
// Created by veerd on 2018-11-23.
//

#include "genetic_algorithm.hpp"
#include "util.cpp"

genetic_algorithm::genetic_algorithm(population popl) : popl(popl){}

const population &genetic_algorithm::getPopl() const {
    return popl;
}

// TODO
void genetic_algorithm::genetic_algo() {
    // initialize population

    // evaluate population

    while(!termination_criteria_met()) {
        // select solutions for next population

        // perform crossover and mutation

        // evaluate new population

    }
}

