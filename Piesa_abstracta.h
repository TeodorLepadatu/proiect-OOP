
#ifndef OOP_PIESA_ABSTRACTA_H
#define OOP_PIESA_ABSTRACTA_H

#include <string>
#include <iostream>
#include <vector>
#include "Locatie.h"
#include "Tabla.h"

class Piesa {
protected:
    std::string tip;
    int culoare;
    Locatie locatie;
    std::vector<std::string> resurse;
public:
    Piesa() : culoare(0), locatie(0, 0) {}

    virtual std::vector<Locatie> muta(Locatie const &locatie_, Piesa const &p) = 0;

    /*
    friend std::ostream &operator<<(std::ostream &os, const Piesa &piesa) {
        os << "tip: " << piesa.tip << " culoare: " << piesa.culoare << " locatie: " << piesa.locatie;
        return os;
    }
    */
    [[nodiscard]] std::string gettip() const {
        return tip;
    }

    [[nodiscard]] int getculoare() const {
        return culoare;
    }

    [[nodiscard]] const Locatie &getLocatie() const {
        return locatie;
    }

    void setLocatie(int linie, int coloana) {
        locatie.setLinie(linie);
        locatie.setColoana(coloana);
    }

    void setCuloare(const int &culoare_) {
        Piesa::culoare = culoare_;
    }

    void setTip(const std::string &tip_) {
        Piesa::tip = tip_;
    }

};

class Pion : public Piesa {
private:
    std::vector<Locatie> mutari_posibile;
public:
    Pion() {
        tip = "P";
        resurse.push_back("apa");
        resurse.push_back("mancare");
    }

    std::vector<Locatie> muta(Locatie const &locatie_, Piesa const &p);
};

class Cal : public Piesa {
    std::vector<Locatie> mutari_posibile;
public:
    Cal() {
        tip = "C";
        resurse.push_back("apa");
        resurse.push_back("mancare");
        resurse.push_back("arma");
    }

    std::vector<Locatie> muta(Locatie const &locatie_, Piesa const &p) override;
};

class Nebun : public Piesa {
private:
    std::vector<Locatie> mutari_posibile;
public:
    Nebun() {
        tip = "B";
        resurse.push_back("apa");
        resurse.push_back("mancare");
        resurse.push_back("arma");
    }

    std::vector<Locatie> muta(Locatie const &locatie_, Piesa const &p) override;
};

class Turn : public Piesa {
private:
    std::vector<Locatie> mutari_posibile;
public:
    Turn() {
        tip = "R";
        resurse.push_back("arma");
        resurse.push_back("piatra");
        resurse.push_back("apa");
    }

    std::vector<Locatie> muta(Locatie const &locatie_, Piesa const &p) override;
};

class Rege : public Piesa {
private:
    std::vector<Locatie> mutari_posibile;
public:
    Rege() {
        tip = "K";
    }

    std::vector<Locatie> muta(Locatie const &locatie_, Piesa const &p) override;
};
#endif
