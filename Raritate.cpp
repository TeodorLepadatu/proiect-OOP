#include <iostream>
#include "Raritate.h"

template<>
Raritate<Pacanea>::Raritate(int random_value) {
    if (random_value == 1) {
        bonus = PacaneaFactory::createRandomPacanea();
    } else {
        throw raritate_error();
    }
}


template<>
Raritate<int>::Raritate(int random_value) {
    if (random_value == 2) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 4);
        bonus = dis(gen);
    } else {
        throw raritate_error();
    }
}


template
class Raritate<Pacanea>;

template
class Raritate<int>;
