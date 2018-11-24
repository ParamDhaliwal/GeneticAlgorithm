//
// Created by veerd on 2018-11-18.
//

#pragma once
#include <iostream>

using namespace std;

class city
{
private:
    int city_id;
    int x;
    int y;

public:
    city();
    city(int city_id, int x, int y);
    void check_coordinate(int range);
};