#ifndef OOP_TABLA_H
#define OOP_TABLA_H

#include <iostream>
#include "Camp.h"
#include <random>
//#include "functii.h"

int dau_cu_zaru1() {
    std::random_device rd;
    std::mt19937 gen(rd()); //random number generator
    std::uniform_int_distribution<> dis(1, 6);
    int roll1 = dis(gen);
    int roll2 = dis(gen);
    return roll1 + roll2;
}

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
                int nr = dau_cu_zaru1();
                m[i][j] = Camp(c, loc, nr, false);
            }
        }
    }

    /*
    Camp &getCamp(int i, int j) {
        return m[i][j];
    }
    */
    void setCamp(int i, int j) {
        m[i][j].setOcupat();
    }

    void resetCamp(int i, int j) {
        m[i][j].reset();
    }
    void displaynr() const {
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                std::cout << m[i][j].getNumar() << " ";
            }
            std::cout << std::endl;
        }
    }

    /*
    void displaycolor() const {
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                std::cout << m[i][j].getCuloare() << " ";
            }
            std::cout << std::endl;
        }
    }

    void displayocupat() const {
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                std::cout << m[i][j].isOcupat() << " ";
            }
            std::cout << std::endl;
        }
    }
    */
    friend std::ostream &operator<<(std::ostream &os, const Tabla &tabla) {
        os << "m: " << tabla.m;
        return os;
    }
};

#endif
