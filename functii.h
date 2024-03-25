#ifndef OOP_FUNCTII_H
#define OOP_FUNCTII_H

#include <random>
#include <iostream>
#include "Piesa_abstracta.h"
int dau_cu_zaru() {
    std::random_device rd;
    std::mt19937 gen(rd()); //random number generator
    std::uniform_int_distribution<> dis(1, 6);
    int roll1 = dis(gen);
    int roll2 = dis(gen);
    return roll1 + roll2;
}

int random_number_generator() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 4);
    return dis(gen);
}

void you_dumb() {
    std::cout << "You are just stupid" << std::endl;
}

void printboard(std::string board[][9]) {
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++)
            std::cout << board[i][j] << " ";
        std::cout << std::endl;
    }
}


#endif
