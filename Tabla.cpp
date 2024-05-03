#include "Tabla.h"

/*
    Camp &getCamp(int i, int j) {
        return m[i][j];
    }
    */
void Tabla::setCamp(int i, int j) {
    m[i][j].setOcupat();
}

void Tabla::resetCamp(int i, int j) {
    m[i][j].reset();
}

void Tabla::displaynr() const {
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            std::cout << m[i][j].getNumar() << " ";
        }
        std::cout << std::endl;
    }
}

/*
void Tabla::displaycolor() const {
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            std::cout << m[i][j].getCuloare() << " ";
        }
        std::cout << std::endl;
    }
}

void Tabla::displayocupat() const {
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            std::cout << m[i][j].isOcupat() << " ";
        }
        std::cout << std::endl;
    }
}
*/
