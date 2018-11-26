//
// Created by veerd on 2018-11-23.
//

#pragma once

#include "tour.hpp"
#include <vector>

class population {

private:
    vector<tour> tours;

public:
    population();
    population(vector<tour> &tours);
    vector<tour> * get_tours();
};