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

/**
 * Helps setting random coordinates for the cities.
 *
 * @param c
 */
static void set_random_cities_coordinates(city *c) {
    c->set_x(static_cast<int>((random() * MAP_BOUNDARY) / RAND_MAX));
    c->set_y(static_cast<int>((random() * MAP_BOUNDARY) / RAND_MAX));
}

/**
 * Helps generate random cities.
 *
 * @return
 */
static vector<city> generate_random_cities() {
    vector<city> cities;
    for (int city_id = 0; city_id < CITIES_IN_TOUR; city_id++) {
        city *c = new city(city_id, -1, -1);
        set_random_cities_coordinates(c);
        cities.push_back(*c);
    }
    return cities;
}

/**
 * Helps generate random tours.
 *
 * @param cities
 * @return
 */
static vector<tour> generate_random_tours(vector<city> cities) {
    vector<tour> tours;
    for (int i = 0; i < POPULATION_SIZE; i++) {
        tour *t = new tour(i, cities);
        tours.push_back(*t);
    }
    return tours;
}

// shuffle_cities to shuffle the cities in a tour.
//static void shuffle_cities(vector<tour> &t) {
//    vector<tour> my_vector (t, t + CITIES_IN_TOUR);
//    vector<reference_wrapper<const tour >> my_vector(t.begin(), t.end());
//    srand(unsigned(time(0)));
//    shuffle(my_vector.begin(), my_vector.end(), mt19937(random_device()()));
//    vector<tour> shuffled_list{my_vector.begin(), my_vector.end()};
//}

/**
 * Helps getting the distance between two cities.
 *
 * @param a
 * @param b
 * @return
 */
static double get_distance_between_cities(city a, city b) {
    double x_distance = a.get_x() - b.get_x();
    double y_distance = a.get_y() - b.get_y();
    double distance = sqrt((x_distance * x_distance) + (y_distance * y_distance));
    return distance;
}

/**
 * Reports the distance between the cities as
 * they are listed in a tour.
 *
 * @param t
 * @return
 */
static double get_tour_distance(tour t) {
    double total_distance = 0;
    for (int i = 0; i < t.get_cities_list().size() - 1; i++) {
        city a = t.get_cities_list().at(i);
        city b = t.get_cities_list().at(i + 1);
        total_distance += get_distance_between_cities(a, b);
    }
    return total_distance;
}

/**
 * Helps finding and retrieving the shortest tour
 * of all the others.
 *
 * @param tours
 * @return
 */
static tour get_shortest_tour(vector<tour> tours) {
    tour shortest_tour;
    double min_distance = __DBL_MAX__;
    for (int i = 0; i < tours.size(); i++) {
        tour t = tours.at(i);
        double distance = get_tour_distance(t);
        if (distance < min_distance) {
            min_distance = distance;
            shortest_tour = t;
        }
    }
    return shortest_tour;
}

/**
 * Helps getting the best distance from
 * the population of the tours.
 *
 * @param popl
 * @return
 */
static double get_best_distance(population *popl) {
    tour t = get_shortest_tour(*(popl->get_tours()));
    return get_tour_distance(t);
}

/**
 * Helps observing a predetermined improvement for us
 * to iteratively run genetic algorithm.
 *
 * @param popl
 * @param baseDistance
 * @return
 */
static bool termination_criteria_met(population *popl, double baseDistance) {
    double improvement = baseDistance / get_best_distance(popl);
    return improvement > IMPROVEMENT_FACTOR;
}

/**
 * Determines the fitness of a tour.
 *
 * @param t
 * @return
 */
static double determine_fitness(tour t) {
    return FITNESS_MULTIPLIER / get_tour_distance(t);
}

/**
 * Selects the parents for a new tour from a population.
 *
 * @param popl
 * @return
 */
static vector<tour> select_parents(population * popl) {
    vector<tour> tours = *(popl->get_tours());
    vector<tour> parents;
    auto rng = std::default_random_engine{};
    for (int i = 0; i < NUMBER_OF_PARENTS; i++) {

        vector<tour> shuffled_tours;
        shuffled_tours.swap(tours);
        std::shuffle(shuffled_tours.begin(), shuffled_tours.end(), rng);

//        vector<tour> parent_pool;
        vector<tour>::const_iterator first = shuffled_tours.begin();
        vector<tour>::const_iterator last = shuffled_tours.begin() + PARENT_POOL_SIZE;
        vector<tour> parent_pool(first, last);
        parents.push_back(get_shortest_tour(parent_pool));
    }
    return parents;
}

// TODO
// crossover creates a new tour from a given set of parent tours.
static tour crossover(vector<tour> parent_tours) {
    tour new_tour;
    return new_tour;
}

// TODO
// mutate to mutate a tour.
static void mutate(tour t) {

}

// contains_city checks if a tour contains a specified city.
static bool contains_city(tour t, city c) {
    for (const city a: t.get_cities_list()) {
        if (a.get_city_id() == c.get_city_id()) {
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