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
    vector<city> cities_list;

public:
    tour();
    tour(int tour_id, vector<city> cities_list);

    void set_cities_list(const vector<city> &cities_list);

    int get_tour_id() const;
    vector<city> &get_cities_list();
    double get_fitness() const;
};