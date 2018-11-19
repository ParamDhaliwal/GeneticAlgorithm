//
// Created by veerd on 2018-11-18.
//

#include "city.hpp"
#include "constants.hpp"

/**
 * Overloaded constructor for city.
 *
 * @param name
 * @param x_coordinate
 * @param y_coordinate
 */
city::city(int name, int x_coordinate, int y_coordinate)
    : city_id(name),
      x(x_coordinate),
      y(y_coordinate){}

/**
 * Checks the range set for x and y coordinates.
 *
 * @param range
 */
void city::check_coordinate(int range)
{
    if(range < 0 || range > MAP_BOUNDARY) {
        throw invalid_argument("the range should be between [0, 10000]");
    }
}
