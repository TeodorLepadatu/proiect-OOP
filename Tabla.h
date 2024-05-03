#ifndef OOP_TABLA_H
#define OOP_TABLA_H

#include <iostream>
#include "Camp.h"
#include <random>
//#include "functii.h"


class Tabla {
private:
    Camp m[9][9];  // Maximum number of squares
public:
    Tabla() {
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                std::string c;
                if ((i + j) % 4 == 0)
                    c = "apa";
                else if ((i + j) % 4 == 1)
                    c = "mancare";
                else if ((i + j) % 4 == 2)
                    c = "piatra";
                else
                    c = "arma";
                Locatie loc(i, j);
                std::random_device rd;
                std::mt19937 gen(rd()); //random number generator
                std::uniform_int_distribution<> dis(1, 6);
                int roll1 = dis(gen);
                int roll2 = dis(gen);
                int nr = roll1 + roll2;
                m[i][j] = Camp(c, loc, nr, false);
            }
        }
    }

    /*
    Camp &getCamp(int i, int j);
    */
    void setCamp(int i, int j);

    void resetCamp(int i, int j);

    void displaynr() const;

    /*
    void displaycolor() const;

    void displayocupat() const;
    */
    friend std::ostream &operator<<(std::ostream &os, const Tabla &tabla) {
        os << "m: " << tabla.m;
        return os;
    }
};

#endif
