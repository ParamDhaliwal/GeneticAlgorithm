//
// Created by veerd on 2018-11-23.
//

#include <list>
#include "population.hpp"

/**
 * Default constructor.
 */
population::population() = default;

/**
 * Overloaded constructor.
 *
 * @param tours
 */
population::population(vector <tour> &tours) : tours(tours) {}

/**
 * Gets all the tours.
 * @return
 */
vector<tour> * population::get_tours() {
    return &(this->tours);
}
