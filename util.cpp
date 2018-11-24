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
static void shuffle_cities(tour t) {

}

// TODO
// get_distance_between_cities to calculate the as-the-crow-flies distance between two cities.
static double get_distance_between_cities(city a, city b) {
    return -1;
}

// TODO
// get_tour_distance reports the distance between the cities as they are listed in a tour.
static double get_tour_distance(tour t) {
    return -1;
}

// TODO
// determine_fitness determines the fitness of a tour.
static double determine_fitness(tour t) {
   return -1;
}

// TODO
// select_parents will select the parents for a new tour from a population.
static list<tour> select_parents(population popl) {
    list<tour> parent_tours;
    return parent_tours;
}

// TODO
// crossover creates a new tour from a given set of parent tours.
static tour crossover(list<tour> parent_tours) {
    tour new_tour;
    return new_tour;
}

// TODO
// mutate to mutate a tour.
static void mutate(tour t) {

}

// TODO
// contains_city checks if a tour contains a specified city.
static bool contains_city(tour t, city c) {
    return false;
}

// TODO
static void print_population_details(population popl) {

}

// TODO
static void move_fittest_to_front(population popl) {

}

// TODO
// Given.
static void crossover(population popl) {
    list<tour> parent_tours = select_parents(*popl);
    tour child_tour = crossover(parent_tours);
}

// TODO
// Mutates the entire population.
static void mutate (population popl) {

}