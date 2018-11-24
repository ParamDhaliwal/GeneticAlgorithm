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
    return -1;
}

// TODO
static bool termination_criteria_met() {
    return true;
}

// TODO
// shuffle_cities to shuffle the cities in a tour.
static void shuffle_cities() {

}

// TODO
// get_distance_between_cities to calculate the as-the-crow-flies distance between two cities.
static double get_distance_between_cities() {
    return -1;
}

// TODO
// get_tour_distance reports the distance between the cities as they are listed in a tour.
static double get_tour_distance() {
    return -1;
}

// TODO
// determine_fitness determines the fitness of a tour.
static void determine_fitness() {

}

// TODO
// select_parents will select the parents for a new tour from a population.
static void select_parents() {

}

// TODO
// crossover creates a new tour from a given set of parent tours.
static void crossover() {

}

// TODO
// mutate to mutate a tour.
static void mutate() {

}

// TODO
// contains_city checks if a tour contains a specified city.
static bool contains_city() {
    return false;
}
