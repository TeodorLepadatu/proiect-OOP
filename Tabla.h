#include "functii.h"
#include <iostream>
#include "Locatie.h"
#ifndef OOP_TABLA_H
#define OOP_TABLA_H
#include "Camp.h"

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
                int nr = dau_cu_zaru();
                m[i][j] = Camp(c, loc, nr, false);
            }
        }
    }

    void display() const {
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                std::cout << m[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};
#endif
