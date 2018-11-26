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
    void set_city_id(int city_id);
    void set_x(int x);
    void set_y(int y);

    int get_city_id() const;
    int get_x() const;
    int get_y() const;
};