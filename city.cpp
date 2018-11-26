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
/**
 * Sets city's id.
 * @param city_id
 */
void city::set_city_id(int city_id) {
    city::city_id = city_id;
}

/**
 * Sets city's x coordinate.
 *
 * @param x
 */
void city::set_x(int x) {
    city::x = x;
}

/**
 * Sets city's y coordinate
 * @param y
 */
void city::set_y(int y) {
    city::y = y;
}

/**
 * Gets city's id.
 *
 * @return city_id
 */
int city::get_city_id() const {
    return city_id;
}

/**
 * Gets x coordinate.
 *
 * @return x
 */
int city::get_x() const {
    return x;
}

/**
 * Gets y coordinate.
 *
 * @return y
 */
int city::get_y() const {
    return y;
}