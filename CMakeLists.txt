cmake_minimum_required(VERSION 3.12)
project(GeneticAlgorithm)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

add_executable(GeneticAlgorithm main.cpp city.cpp constants.hpp tour.hpp tour.cpp population.hpp population.cpp util.cpp genetic_algorithm.hpp genetic_algorithm.cpp)