//
// Created by veerd on 2018-11-19.
//

#pragma once
#include <iostream>
#include <list>
#include "city.hpp"

using namespace std;

class tour
{
private:
    list<city> cities_list = {};

public:
    tour();
    tour(list<city> cities_list);
    const list<city> &getCities_list() const;
    double getFitness() const;
};