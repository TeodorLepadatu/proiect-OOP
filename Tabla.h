#ifndef OOP_TABLA_H
#define OOP_TABLA_H

#include <iostream>
#include "Camp.h"
#include <random>
#include <SFML/Graphics.hpp>
//#include "functii.h"


class Tabla {   ///singleton
private:
    Camp m[9][9];
    Tabla() {
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                std::string c;
                if ((i + j) % 4 == 0)
                    c = "WATER";
                else if ((i + j) % 4 == 1)
                    c = "FOOD";
                else if ((i + j) % 4 == 2)
                    c = "STONE";
                else
                    c = "WEAPON";
                Locatie loc(i, j);
                std::random_device rd;
                std::mt19937 gen(rd()); //random number generator
                std::uniform_int_distribution<> dis(1, 6);
                int roll1 = dis(gen);
                int roll2 = dis(gen);
                int nr = roll1 + roll2;
                m[i][j] = Camp(c, loc, nr, false, false);
            }
        }
    }

public:

    Tabla(const Tabla &) = delete;

    Tabla &operator=(const Tabla &) = delete;

    static Tabla &get_tabla() {
        static Tabla tabla;
        return tabla;
    }

    void setCamp(int i, int j);

    void resetCamp(int i, int j);

    void displaynr() const;

    void displaycolor() const;

    void displayocupat();
    [[nodiscard]] Camp displayCamp(int i, int j) const;

    friend std::ostream &operator<<(std::ostream &os, const Tabla &tabla) {
        os << "m: " << tabla.m;
        return os;
    }
};

#endif
