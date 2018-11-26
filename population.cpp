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
population::population(const std::list <tour> &tours) : tours(tours) {}

/**
 * Gets all the tours.
 * @return
 */
const list<tour> &population::getTours() const {
    return tours;
}
