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

std::vector<Locatie> muta_pion(Locatie &locatie, Piesa p) {
    std::vector<Locatie> mutari_posibile;
    int i = locatie.getLinie();
    int j = locatie.getColoana();
    mutari_posibile.clear();

    if (p.getculoare() == 1) {
        Locatie x(i + 1, j);
        mutari_posibile.push_back(x);
    } else if (p.getculoare() == 2) {
        Locatie x(i, j - 1);
        mutari_posibile.push_back(x);
    } else if (p.getculoare() == 3) {
        Locatie x(i - 1, j);
        mutari_posibile.push_back(x);
    } else {
        Locatie x(i, j + 1);
        mutari_posibile.push_back(x);
    }
    return mutari_posibile;
}

std::vector<Locatie> muta_cal(Locatie &locatie, Piesa p) {
    std::vector<Locatie> mutari_posibile;
    mutari_posibile.clear();
    int i = locatie.getLinie();
    int j = locatie.getColoana();
    if (i == 1) {
        if (j == 1) {
            Locatie x(2, 3);
            mutari_posibile.push_back(x);
            x.setLinie(3);
            x.setColoana(2);
            mutari_posibile.push_back(x);
        } else if (j == 8) {
            Locatie x(2, 6);
            mutari_posibile.push_back(x);
            x.setLinie(3);
            x.setColoana(7);
            mutari_posibile.push_back(x);
        } else if (j == 2) {
            Locatie x(3, 1);
            mutari_posibile.push_back(x);
            x.setLinie(3);
            x.setColoana(3);
            mutari_posibile.push_back(x);
            x.setLinie(2);
            x.setColoana(4);
            mutari_posibile.push_back(x);
        } else if (j == 7) {
            Locatie x(3, 8);
            mutari_posibile.push_back(x);
            x.setLinie(3);
            x.setColoana(6);
            mutari_posibile.push_back(x);
            x.setLinie(2);
            x.setColoana(5);
            mutari_posibile.push_back(x);
        } else {
            Locatie x(2, j - 2);
            mutari_posibile.push_back(x);
            x.setLinie(3);
            x.setColoana(j - 1);
            mutari_posibile.push_back(x);
            x.setLinie(3);
            x.setColoana(j + 1);
            mutari_posibile.push_back(x);
            x.setLinie(2);
            x.setColoana(j + 2);
            mutari_posibile.push_back(x);
        }
    } else if (i == 2) {
        if (j == 1) {
            Locatie x(4, 2);
            mutari_posibile.push_back(x);
            x.setLinie(3);
            x.setColoana(3);
            mutari_posibile.push_back(x);
            x.setLinie(1);
            x.setColoana(3);
            mutari_posibile.push_back(x);
        } else if (j == 2) {
            Locatie x(4, 1);
            mutari_posibile.push_back(x);
            x.setLinie(4);
            x.setColoana(3);
            mutari_posibile.push_back(x);
            x.setLinie(3);
            x.setColoana(4);
            mutari_posibile.push_back(x);
            x.setLinie(1);
            x.setColoana(4);
            mutari_posibile.push_back(x);
        } else if (j == 7) {
            Locatie x(4, 8);
            mutari_posibile.push_back(x);
            x.setLinie(4);
            x.setColoana(6);
            mutari_posibile.push_back(x);
            x.setLinie(3);
            x.setColoana(5);
            mutari_posibile.push_back(x);
            x.setLinie(1);
            x.setColoana(5);
            mutari_posibile.push_back(x);
        } else if (j == 8) {
            Locatie x(4, 7);
            mutari_posibile.push_back(x);
            x.setLinie(3);
            x.setColoana(6);
            mutari_posibile.push_back(x);
            x.setLinie(1);
            x.setColoana(6);
            mutari_posibile.push_back(x);
        } else {
            Locatie x(3, j - 2);
            mutari_posibile.push_back(x);
            x.setLinie(4);
            x.setColoana(j - 1);
            mutari_posibile.push_back(x);
            x.setLinie(4);
            x.setColoana(j + 1);
            mutari_posibile.push_back(x);
            x.setLinie(3);
            x.setColoana(j + 2);
            mutari_posibile.push_back(x);
            x.setLinie(1);
            x.setColoana(j + 2);
            mutari_posibile.push_back(x);
            x.setLinie(1);
            x.setColoana(j - 2);
            mutari_posibile.push_back(x);
        }
    } else if (i == 7) {
        if (j == 1) {
            Locatie x(5, 2);
            mutari_posibile.push_back(x);
            x.setLinie(6);
            x.setColoana(3);
            mutari_posibile.push_back(x);
            x.setLinie(8);
            x.setColoana(3);
            mutari_posibile.push_back(x);
        } else if (j == 2) {
            Locatie x(5, 1);
            mutari_posibile.push_back(x);
            x.setLinie(5);
            x.setColoana(3);
            mutari_posibile.push_back(x);
            x.setLinie(6);
            x.setColoana(4);
            mutari_posibile.push_back(x);
            x.setLinie(8);
            x.setColoana(4);
            mutari_posibile.push_back(x);
        } else if (j == 7) {
            Locatie x(5, 8);
            mutari_posibile.push_back(x);
            x.setLinie(5);
            x.setColoana(6);
            mutari_posibile.push_back(x);
            x.setLinie(6);
            x.setColoana(5);
            mutari_posibile.push_back(x);
            x.setLinie(8);
            x.setColoana(5);
            mutari_posibile.push_back(x);
        } else if (j == 8) {
            Locatie x(5, 7);
            mutari_posibile.push_back(x);
            x.setLinie(6);
            x.setColoana(6);
            mutari_posibile.push_back(x);
            x.setLinie(8);
            x.setColoana(6);
            mutari_posibile.push_back(x);
        } else {
            Locatie x(6, j - 2);
            mutari_posibile.push_back(x);
            x.setLinie(5);
            x.setColoana(j - 1);
            mutari_posibile.push_back(x);
            x.setLinie(5);
            x.setColoana(j + 1);
            mutari_posibile.push_back(x);
            x.setLinie(6);
            x.setColoana(j + 2);
            mutari_posibile.push_back(x);
            x.setLinie(8);
            x.setColoana(j + 2);
            mutari_posibile.push_back(x);
            x.setLinie(8);
            x.setColoana(j - 2);
            mutari_posibile.push_back(x);
        }
    } else if (i == 8) {
        if (j == 1) {
            Locatie x(7, 3);
            mutari_posibile.push_back(x);
            x.setLinie(6);
            x.setColoana(2);
            mutari_posibile.push_back(x);
        } else if (j == 8) {
            Locatie x(7, 6);
            mutari_posibile.push_back(x);
            x.setLinie(6);
            x.setColoana(7);
            mutari_posibile.push_back(x);
        } else if (j == 2) {
            Locatie x(6, 1);
            mutari_posibile.push_back(x);
            x.setLinie(6);
            x.setColoana(3);
            mutari_posibile.push_back(x);
            x.setLinie(7);
            x.setColoana(4);
            mutari_posibile.push_back(x);
        } else if (j == 7) {
            Locatie x(6, 8);
            mutari_posibile.push_back(x);
            x.setLinie(6);
            x.setColoana(6);
            mutari_posibile.push_back(x);
            x.setLinie(7);
            x.setColoana(5);
            mutari_posibile.push_back(x);
        } else {
            Locatie x(7, j - 2);
            mutari_posibile.push_back(x);
            x.setLinie(6);
            x.setColoana(j - 1);
            mutari_posibile.push_back(x);
            x.setLinie(6);
            x.setColoana(j + 1);
            mutari_posibile.push_back(x);
            x.setLinie(7);
            x.setColoana(j + 2);
            mutari_posibile.push_back(x);
        }
    } else {
        Locatie x(i + 1, j - 2);
        mutari_posibile.push_back(x);
        x.setLinie(i + 2);
        x.setColoana(j - 1);
        mutari_posibile.push_back(x);
        x.setLinie(i + 2);
        x.setColoana(j + 1);
        mutari_posibile.push_back(x);
        x.setLinie(i + 1);
        x.setColoana(j + 2);
        mutari_posibile.push_back(x);
        x.setLinie(i - 1);
        x.setColoana(j + 2);
        mutari_posibile.push_back(x);
        x.setLinie(i - 2);
        x.setColoana(j + 1);
        mutari_posibile.push_back(x);
        x.setLinie(i - 2);
        x.setColoana(j - 1);
        mutari_posibile.push_back(x);
        x.setLinie(i - 1);
        x.setColoana(j - 2);
        mutari_posibile.push_back(x);
    }
    return mutari_posibile;
}

std::vector<Locatie> muta_nebun(Locatie &locatie, Piesa p) {
    std::vector<Locatie> mutari_posibile;
    int i = locatie.getLinie();
    int j = locatie.getColoana();
    mutari_posibile.clear();
    for (int i1 = 1; i1 <= 8; i1++) {
        for (int j1 = 1; j1 <= 8; j1++) {
            if (abs(i - i1) == abs(j - j1) && !(i == i1 && j == j1)) {
                Locatie x(i1, j1);
                mutari_posibile.push_back(x);
            }
        }
    }
    return mutari_posibile;
}

std::vector<Locatie> muta_turn(Locatie &locatie, Piesa p) {
    std::vector<Locatie> mutari_posibile;
    int i = locatie.getLinie();
    int j = locatie.getColoana();
    mutari_posibile.clear();
    for (int i1 = 1; i1 <= 8; i1++) {
        for (int j1 = 1; j1 <= 8; j1++) {
            if (i1 == i || j1 == j) {
                Locatie x(i1, j1);
                mutari_posibile.push_back(x);
            }
        }
    }
    return mutari_posibile;
}

std::vector<Locatie> muta_rege(Locatie &locatie, Piesa p) {
    std::vector<Locatie> mutari_posibile;
    int i = locatie.getLinie();
    int j = locatie.getColoana();
    mutari_posibile.clear();
    if (i == 1) {
        if (j == 1) {
            Locatie x(2, 1);
            mutari_posibile.push_back(x);
            x.setLinie(2);
            x.setColoana(2);
            mutari_posibile.push_back(x);
            x.setLinie(1);
            x.setColoana(2);
            mutari_posibile.push_back(x);
        } else if (j == 8) {
            Locatie x(2, 8);
            mutari_posibile.push_back(x);
            x.setLinie(2);
            x.setColoana(7);
            mutari_posibile.push_back(x);
            x.setLinie(1);
            x.setColoana(7);
            mutari_posibile.push_back(x);
        } else {
            Locatie x(1, j - 1);
            mutari_posibile.push_back(x);
            x.setLinie(2);
            x.setColoana(j - 1);
            mutari_posibile.push_back(x);
            x.setLinie(2);
            x.setColoana(j);
            mutari_posibile.push_back(x);
            x.setLinie(2);
            x.setColoana(j + 1);
            mutari_posibile.push_back(x);
            x.setLinie(1);
            x.setColoana(j + 1);
            mutari_posibile.push_back(x);
        }
    } else if (i == 8) {
        if (j == 1) {
            Locatie x(7, 1);
            mutari_posibile.push_back(x);
            x.setLinie(7);
            x.setColoana(2);
            mutari_posibile.push_back(x);
            x.setLinie(8);
            x.setColoana(2);
            mutari_posibile.push_back(x);
        } else if (j == 8) {
            Locatie x(7, 8);
            mutari_posibile.push_back(x);
            x.setLinie(7);
            x.setColoana(7);
            mutari_posibile.push_back(x);
            x.setLinie(8);
            x.setColoana(7);
            mutari_posibile.push_back(x);
        } else {
            Locatie x(8, j - 1);
            mutari_posibile.push_back(x);
            x.setLinie(7);
            x.setColoana(j - 1);
            mutari_posibile.push_back(x);
            x.setLinie(7);
            x.setColoana(j);
            mutari_posibile.push_back(x);
            x.setLinie(7);
            x.setColoana(j + 1);
            mutari_posibile.push_back(x);
            x.setLinie(8);
            x.setColoana(j + 1);
            mutari_posibile.push_back(x);
        }
    }
    return mutari_posibile;
}
#endif
