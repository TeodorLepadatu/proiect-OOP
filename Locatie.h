
#ifndef OOP_LOCATIE_H
#define OOP_LOCATIE_H

#include <iostream>

class Locatie {
private:
    int linie;
    int coloana;
public:
    Locatie() {
        linie = 0;
        coloana = 0;
    }
    Locatie(int linie_, int coloana_) : linie{linie_}, coloana{coloana_} {
        //std::cout<<"constr init"<<std::endl;
    }

    Locatie(const Locatie &other) : linie{other.linie}, coloana{other.coloana} {
        //std::cout << "constr copiere" << std::endl;
    }

    Locatie &operator=(const Locatie &other) {
        if (this != &other) { // Check for self-assignment
            linie = other.linie;
            coloana = other.coloana;
        }
        return *this;
    }

    [[nodiscard]] int getLinie() const {
        return linie;
    }

    [[nodiscard]] int getColoana() const {
        return coloana;
    }

    bool operator==(const Locatie &other) const {
        return linie == other.linie && coloana == other.coloana;
    }

    bool operator!=(const Locatie &other) const {
        return !(other == *this);
    }

    friend std::ostream &operator<<(std::ostream &os, const Locatie &locatie) {
        os << "line: " << locatie.linie << " column: " << locatie.coloana;
        return os;
    }

    void setLinie(int linie_) {
        Locatie::linie = linie_;
    }

    void setColoana(int coloana_) {
        Locatie::coloana = coloana_;
    }

    ~Locatie() = default;
};


#endif
