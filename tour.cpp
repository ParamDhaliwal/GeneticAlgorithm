//
// Created by veerd on 2018-11-21.
//

#include "tour.hpp"
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
 * @param fitness
 */
tour::tour(list<city> cities, double fitness)
    : cities_list(move(cities)),
      fitness(fitness){}