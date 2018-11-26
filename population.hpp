//
// Created by veerd on 2018-11-23.
//

#pragma once

#include "tour.hpp"
#include <list>

class population {

private:
    list<tour> tours;

public:
    population();
    population(const list<tour> &tours);
    const list<tour> &getTours() const;
};