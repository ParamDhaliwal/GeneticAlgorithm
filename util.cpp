//
// Created by veerd on 2018-11-23.
//

#include "city.hpp"
#include "tour.hpp"
#include "population.hpp"
#include "constants.hpp"
#include <utility>
#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <random>
#include <cmath>

using namespace std;

static void set_random_cities_coordinates(city *c) {
    c->setX(static_cast<int>((random() * MAP_BOUNDARY) / RAND_MAX));
    c->setY(static_cast<int>((random() * MAP_BOUNDARY) / RAND_MAX));
}

static list<city> generate_random_cities() {
    list<city> cities;
    for (int city_id = 0; city_id < CITIES_IN_TOUR; city_id++) {
        city *c = new city(city_id, -1, -1);
        set_random_cities_coordinates(c);
        cities.push_back(*c);
    }
    return cities;
}

static list<tour> generate_random_tours(list<city> cities) {
    list<tour> tours;
    for (int i = 0; i < POPULATION_SIZE; i++) {
        tour *t = new tour(cities);
        tours.push_back(*t);
    }
    return tours;
}

// TODO
static bool termination_criteria_met() {
    return true;
}

// shuffle_cities to shuffle the cities in a tour.
static void shuffle_cities(list<tour> &t) {
//    vector<tour> my_vector (t, t + CITIES_IN_TOUR);
    vector<reference_wrapper<const tour >> my_vector(t.begin(), t.end());
    srand(unsigned(time(0)));
    shuffle(my_vector.begin(), my_vector.end(), mt19937(random_device()()));
    list<tour> shuffled_list{my_vector.begin(), my_vector.end()};
}

// get_distance_between_cities to calculate the as-the-crow-flies distance between two cities.
static double get_distance_between_cities(city a, city b) {
    double x_distance = a.getX() - b.getX();
    double y_distance = a.getY() - b.getY();
    double distance = sqrt((x_distance * x_distance) + (y_distance * y_distance));
    return distance;
}

// TODO
// get_tour_distance reports the distance between the cities as they are listed in a tour.
static double get_tour_distance(tour t) {
    double total_distance = 0;
    for (int i = 0; i < t.getCities_list().size(); i++) {
//        total_distance += get_distance_between_cities(t.getCities_list(), t.getCities_list());
    }
    return total_distance;
}

// determine_fitness determines the fitness of a tour.
static double determine_fitness(tour t) {
    return FITNESS_MULTIPLIER / get_tour_distance(t);
}

// TODO - Edited
/**
 * Determine and record the fitness of each tour. The fitness must be a double that represents the quality of the tour.
 * Shorter tours are better quality, and will have better fitness. A good idea is to
 * use the inverse of the total distance travelled possibly multiplied by some scalar.
 * @param t
 * @return
 */
static double calculate_fitness(tour t) {
    return SCALAR * determine_fitness(t);
}

// TODO
// select_parents will select the parents for a new tour from a population.
/**
 * Choose each parent by selecting a subset of tours from the population to represent potential parents, and
 * then select thenfittest from the subset. That is, each parent is the fittest of a subset of size
 * PARENT_POOL_SIZE of the population, randomly selected.
 *
 * @param popl
 * @return
 */
static list<tour> select_parents(population popl) {
    // Figure out how to select a random subset of list.;
    // Create two such sets.
    // Select fittest tour from each set.
    // Two of the fittest will be the parents.
    list<tour> parent_tours;
    for(int i = 0; i < NUMBER_OF_PARENTS; i++) {
//        list<tour> shuffled_list;
    }
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

// contains_city checks if a tour contains a specified city.
static bool contains_city(tour t, city c) {
    for (const city a: t.getCities_list()) {
        if (a.getCity_id() == c.getCity_id()) {
            return true;
        }
    }
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
    list<tour> parent_tours = select_parents(popl);
    tour child_tour = crossover(parent_tours);
}

// TODO
// Mutates the entire population.
static void mutate(population popl) {

}