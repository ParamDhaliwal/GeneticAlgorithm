#include <iostream>
#include <vector>
#include "city.hpp"
#include "tour.hpp"
#include "population.hpp"
#include "genetic_algorithm.hpp"
#include "util.cpp"

int main()
{
    vector<city> cities = generate_random_cities();
    vector<tour> tours = generate_random_tours(cities);
    population *pop = new population(tours);

    genetic_algorithm * ga = new genetic_algorithm(pop);
    ga->genetic_algo();

    return 0;
}