//
// Created by veerd on 2018-11-18.
//

#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>

using namespace std;

class city
{
private:
    int city_id;
    int x, y;

public:
    city(int name, int x_coordinate, int y_coordinate);
    void check_coordinate(int range);
};