//
// Created by veerd on 2018-11-19.
//

#pragma once
#include <iostream>
#include <vector>
#include "city.hpp"

using namespace std;

class tour
{
private:
    int tour_id;
    vector<city> cities;

public:
    tour();
    tour(int tour_id, vector<city> cities);

    void add_city(city);
    void set_cities(const vector<city> &cities);

    int get_tour_id() const;
    vector<city> &get_cities();
    double get_fitness() const;
};