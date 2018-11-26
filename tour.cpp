//
// Created by veerd on 2018-11-21.
//


#include <utility>
#include "tour.hpp"
#include "util.cpp"

using namespace std;

/**
 * Default constructor.
 */
tour::tour() = default;

/**
 * Overloaded constructor.
 *
 * @param cities
 */
tour::tour(int tour_id, vector<city> cities)
    : tour_id(tour_id),
      cities(cities){}

/**
 * Helps adding cities in a tour.
 */
void tour::add_city(city c) {
    cities.push_back(c);
}

/**
 * Sets cities list.
 *
 * @param cities_list
 */
void tour::set_cities(const vector<city> &cities) {
    tour::cities = cities;
}

/**
 * Gets list of cities stored in a tour.
 *
 * @return cities_list
 */
vector<city> &tour::get_cities() {
    return cities;
}

/**
 * Gets tour's id.
 *
 * @return tour_id
 */
int tour::get_tour_id() const {
    return tour_id;
}

/**
 * Helps getting the fitness of a tour.
 *
 * @return fitness after determining
 */
double tour::get_fitness() const {
    return determine_fitness(*this);
}
