#include <iostream>
#include "city.hpp"
#include "tour.hpp"
#include "util.cpp"
#include "population.hpp"

int main()
{
    vector<city> cities_list = generate_random_cities();
    vector<tour> tours_list = generate_random_tours(cities_list);
    population *pop = new population(tours_list);

    return 0;
}