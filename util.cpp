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
#include <iomanip>

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

//static population generate_random_population() {
//    population *popl = new population();
//    auto rng = std::default_random_engine{};
//    for (int i = 0; i < POPULATION_SIZE; i++) {
//        vector<city> cities = generate_random_cities();
//        vector<city> shuffled_tours;
//        shuffled_tours.swap(cities);
//        shuffle(shuffled_tours.begin(), shuffled_tours.end(), rng);
//        tour *t = new tour();
////        cities.push_back(t->add_city());
//        popl->add_tour(t);
//    }
//    return *popl;
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
    for (auto i = 0; i < t.get_cities().size() - 1; i++) {
        city a = t.get_cities().at(i);
        city b = t.get_cities().at(i + 1);
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
    for (auto i = 0; i < tours.size(); i++) {
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
static bool termination_criteria_met(population *popl, double base_distance) {
    double improvement = base_distance / get_best_distance(popl);
    cout << "Improvement: " << improvement << "\n\n";
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
//    return parents;
}

// contains_city checks if a tour contains a specified city.
static bool contains_city(tour t, city c) {
    for (const city a: t.get_cities()) {
        if (a.get_city_id() == c.get_city_id()) {
            return true;
        }
    }
    return false;
}

/**
 * Creates a new tour from a given set of parent tours.
 *
 * @param parent_tours
 * @return
 */
static tour crossover(vector<tour> parent_tours) {


    tour child;
    tour parent1 = parent_tours.at(0);
    tour parent2 = parent_tours.at(1);

    int random_index = (random() * parent_tours.size()) / RAND_MAX;

    // Populate cities from parent1
    for (int i = 0; i < random_index; i++) {
        child.add_city(parent1.get_cities().at(i));
    }

    // Top-up the mixed tour with cities from parent2 starting from randomIndex
    for (auto i = random_index; i < parent2.get_cities().size(); i++) {
        city c = parent2.get_cities().at(i);
        if (!contains_city(child, c)) {
            child.add_city(c);
        }
    }

    // If there are still cities to be added, select them from parent2 starting from the beginning
    if (child.get_cities().size() < parent1.get_cities().size()) {
        for (int i = 0; i < random_index; i++) {
            city c = parent2.get_cities().at(i);
            if (!contains_city(child, c)) {
                child.add_city(c);
            }
        }
    }
    return child;
}

/**
 * Mutates a tour.
 * @param t
 */
static void mutate(tour *t) {
    for (auto i = 0; i < t->get_cities().size(); i++) {
        city c = t->get_cities().at(i);
        int mutation_value = (random() * 100) / RAND_MAX;
        if (mutation_value < MUTATION_RATE) {
            // Random boolean value indicating whether to swap
            // the city with previous adjacent city or the next.
            bool swap_with_next = random() % 2 == 0;
            if (swap_with_next) {
                // If last city, then swap it with the first
                if (i == t->get_cities().size() - 1) {
                    iter_swap(t->get_cities().begin() + i, t->get_cities().begin());
                } else {
                    iter_swap(t->get_cities().begin() + i, t->get_cities().begin() + i + 1);
                }
            } else {
                // If first city, then swap it with the last
                if (i == 0) {
                    iter_swap(t->get_cities().begin() + i, t->get_cities().end() - 1);
                } else {
                    iter_swap(t->get_cities().begin() + i, t->get_cities().begin() + i - 1);
                }
            }
        }
    }
}

/**
 * Prints population's details.
 *
 * @param popl
 */
static void print_population_details(population popl) {
    for (size_t i = 0; i < popl.get_tours()->size(); i++) {
        tour t = popl.get_tours()->at(i);
        cout << "Fitness level: " << setw(1) << determine_fitness(t) << right << endl;
        cout << "Tour distance: " << setw(2) << get_tour_distance(t) << left << "\n" << endl;
    }
}

/**
 * Helps moving fittest to the front of a list.
 *
 * @param popl
 */
static void move_fittest_to_front(population *popl) {
    vector<tour> *tours = popl->get_tours();
    tour t = get_shortest_tour(*tours);
    tours->insert(tours->begin(), t);
}