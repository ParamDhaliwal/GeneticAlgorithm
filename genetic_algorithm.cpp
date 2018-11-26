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

    cout << "Base distance: " << base_distance << endl;
    cout << "Best distance: " << get_best_distance(popl) << "\n\n";

    // initialize population
    vector<city> cities_list = generate_random_cities();
    vector<tour> tours_list = generate_random_tours(cities_list);
    popl = new population(tours_list);

    // set base distance
    this->base_distance = get_best_distance(this->popl);

    // evaluate population
    print_population_details(*popl);

    int iteration = 0;

    while(!termination_criteria_met(this->popl, this->base_distance)) {

        iteration++;

        // select solutions for next population
        move_fittest_to_front(popl);

        // perform crossover and mutation
        crossover(*popl->get_tours());

        // MUTATION
        vector<tour>::const_iterator first = popl->get_tours()->begin() + 1;
        vector<tour>::const_iterator last = popl->get_tours()->end();
        vector<tour> tours_without_elite(first, last);

        vector<tour>::const_iterator first_1 = tours_without_elite.begin();
        vector<tour>::const_iterator last_1 = tours_without_elite.end() + MUTATION_POOL_SIZE;
        vector<tour> tours_to_mutate(first, last);
        for (size_t i = 0; i < tours_to_mutate.size(); i++) {
            mutate(&tours_to_mutate.at(i));
        }

        // Replace the tours in the population with the mutated ones
        for (size_t i = 0; i < tours_to_mutate.size(); i++) {
            tour mutated_tour = tours_to_mutate.at(i);
            for (size_t j = 0; j < popl->get_tours()->size(); j++) {
                tour original_tour = popl->get_tours()->at(j);
                if (original_tour.get_tour_id() == mutated_tour.get_tour_id()) {
                    original_tour.set_cities(mutated_tour.get_cities());
                }
            }
        }

        cout << "Iterations: " << iteration << "\n\n";

        // evaluate new population
        print_population_details(*popl);
    }
}

