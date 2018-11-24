//
// Created by veerd on 2018-11-23.
//

#pragma once

#include "population.hpp"

class genetic_algorithm {

private:
    population *popl;

public:
    const population &getPopl() const;

    genetic_algorithm();

    void genetic_algo();

};