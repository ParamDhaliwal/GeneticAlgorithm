//
// Created by veerd on 2018-11-23.
//

#pragma once

#include "population.hpp"

class genetic_algorithm {

private:
    population *popl;
    double base_distance;

public:
    genetic_algorithm();
    genetic_algorithm(population *popl);
    const population &getPopl() const;
    void genetic_algo();
};