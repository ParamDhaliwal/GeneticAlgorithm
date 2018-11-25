//
// Created by veerd on 2018-11-21.
//

#include "tour.hpp"
#include "util.cpp"
#include <utility>

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
tour::tour(list<city> cities)
    : cities_list(move(cities)){}

/**
 * Accessor to get the list of cities
 * stored in a tour.
 *
 * @return cities_list
 */
const list<city> &tour::getCities_list() const {
    return cities_list;
}

/**
 * Helps getting the fitness of a tour.
 *
 * @return
 */
double tour::getFitness() const {
    return determine_fitness(*this);
}
