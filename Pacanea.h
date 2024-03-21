#ifndef OOP_PACANEA_H
#define OOP_PACANEA_H

#include <iostream>
#include <string>
#include <random>
#include "functii.h"

class Pacanea {
private:
    std::string tip; //monopoly, +doua mutari, +2resurse, nimic: esti prost
    std::vector<std::string> resurse;

    std::string give_me_pacanea() {
        int nr = random_number_generator();
        if (nr == 1) {
            std::string aux = "monopoly";
            return aux;
        } else if (nr == 2) {
            std::string aux = "+2 mutari";
            return aux;
        } else if (nr == 3) {
            std::string aux = "+2 resurse";
            return aux;
        } else {
            std::string aux = "nimic, ai bagat la pacanele degeaba asa ca esti prost";
            return aux;
        }
    }

public:

    const std::string &getTip() const {
        return tip;
    }

    friend std::ostream &operator<<(std::ostream &os, const Pacanea &pacanea) {
        os << "Ai pacaneaua " << pacanea.tip;
        return os;
    }

    Pacanea() {
        resurse.push_back("piatra");
        resurse.push_back("arma");
        resurse.push_back("apa");
        resurse.push_back("mancare");
        tip = give_me_pacanea();
    }
};

#endif //OOP_PACANEA_H
