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
    int tour_id;
    list<city> cities_list;
public:

public:
    tour();
    tour(list<city> cities_list);
    void set_cities_list(const list<city> &cities_list);
    int get_tour_id() const;
    const list<city> &get_cities_list() const;
    double get_fitness() const;
};