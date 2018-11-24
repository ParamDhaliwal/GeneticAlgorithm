//
// Created by veerd on 2018-11-23.
//

#include "city.hpp"
#include "tour.hpp"
#include "population.hpp"
#include <list>

// TODO
static list<city> generate_random_cities() {
    list<city> cities;
    return cities;
}

// TODO
static list<tour> generate_random_tours(list<city> cities) {
    list<tour> tours;
    return tours;
}

// TODO
//  Determine and record the fitness of each tour. The fitness must be a double that represents the
//  quality of the tour. Shorter tours are better quality, and will have better fitness. A good idea is to
//  use the inverse of the total distance travelled possibly multiplied by some scalar.
static double calculate_fitness(tour t) {
    // Use scalar
    return 0;
}

// TODO
static bool termination_criteria_met() {
    return true;
}