#include <iostream>
#include "city.hpp"
#include "tour.hpp"
#include "util.cpp"
#include "population.hpp"

int main()
{
    list<city> cities_list = generate_random_cities();
    list<tour> tours_list = generate_random_tours(cities_list);
    population *pop = new population(tours_list);

    return 0;
}