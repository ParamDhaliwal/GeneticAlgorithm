//
// Created by veerd on 2018-11-23.
//

#include "genetic_algorithm.hpp"
#include "util.cpp"

/**
 * Default constructor.
 */
genetic_algorithm::genetic_algorithm() = default;

/**
 * Overloaded constructor.
 *
 * @param popl
 */
genetic_algorithm::genetic_algorithm(population *popl) : popl(popl) {}

/**
 * Gets the genetic population.
 *
 * @return
 */
const population &genetic_algorithm::getPopl() const {
    return *popl;
}

/**
 * Initializes, evaluates, selects, crossovers,
 * mutates, and again evaluates "population".
 */
void genetic_algorithm::genetic_algo() {

    // initialize population
    list<city> cities_list = generate_random_cities();
    list<tour> tours_list = generate_random_tours(cities_list);
    popl = new population(tours_list);

    // evaluate population
    print_population_details(*popl);

    while(!termination_criteria_met()) {
        // select solutions for next population
        move_fittest_to_front(*popl);

        // perform crossover and mutation
        crossover(*popl);
        mutate(*popl);

        // evaluate new population
        print_population_details(*popl);
    }
}

