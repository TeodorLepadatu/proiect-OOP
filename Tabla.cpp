#include "Tabla.h"

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


void Tabla::displaycolor() const {
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            std::cout << m[i][j].getCuloare() << " ";
        }
        std::cout << std::endl;
    }
}

Camp Tabla::displayCamp(int i, int j) const {
    return m[i][j];
}
