//
// Created by veerd on 2018-11-18.
//

#include "city.hpp"
#include "constants.hpp"

/**
 * Default constructor.
 */
 city::city() = default;

/**
 * Overloaded constructor for city.
 *
 * @param city_id
 * @param x
 * @param y
 */
city::city(int city_id, int x, int y)
    : city_id(city_id),
      x(x),
      y(y){}

/**
 * Accessor to get city's id.
 *
 * @return city_id
 */
int city::getCity_id() const {
    return city_id;
}

/**
 * Mutator for a city's x coordinate.
 *
 * @param x
 */
void city::setX(int x) {
    city::x = x;
}

/**
 * Mutator for a city's y coordinate
 * @param y
 */
void city::setY(int y) {
    city::y = y;
}

/**
 * Accessor to get x coordinate.
 *
 * @return x
 */
int city::getX() const {
    return x;
}

/**
 * Accessor to get y coordinate.
 *
 * @return y
 */
int city::getY() const {
    return y;
}

/**
 * Checks the range set for x and y coordinates.
 *
 * @param range
 */
void city::check_coordinate(int range)
{
    if(range < 0 || range > MAP_BOUNDARY) {
        throw invalid_argument("the range should be between [0, 1000]");
    }
}
