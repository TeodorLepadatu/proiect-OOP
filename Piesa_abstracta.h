#ifndef OOP_PIESA_ABSTRACTA_H
#define OOP_PIESA_ABSTRACTA_H

#include <string>
#include <iostream>
#include <vector>
#include "Locatie.h"
#include "Tabla.h"

class Piesa {
protected:
    Piesa() {}
    int culoare;
    Locatie locatie;
    std::vector<std::string> resurse;
    std::string type;
public:

    // Copy constructor
    Piesa(const Piesa &other) : culoare(other.culoare), locatie(other.locatie), resurse(other.resurse) {}

    // Copy assignment operator
    Piesa &operator=(const Piesa &other) {
        if (this != &other) {
            culoare = other.culoare;
            locatie = other.locatie;
            resurse = other.resurse;
        }
        return *this;
    }

    virtual std::vector<Locatie> muta(Locatie const &locatie_, Piesa const &p) = 0;

    virtual ~Piesa() = default; // Virtual destructor

    enum tip {
        P, C, B, T, K
    };
protected:
    tip p_tip;
public:
    [[nodiscard]] tip getTip() const { return p_tip; };

    [[nodiscard]] int getCuloare() const {
        return culoare;
    }

    [[nodiscard]] const std::string &gettip() const {
        return type;
    }

    [[nodiscard]] const Locatie &getLocatie() const {
        return locatie;
    }

    void setLocatie(int linie, int coloana) {
        locatie.setLinie(linie);
        locatie.setColoana(coloana);
    }

    void setCuloare(const int &culoare_) {
        culoare = culoare_;
    }

    void setTip(const std::string &tip_) {
        if (tip_ == "P") {
            p_tip = P;
        } else if (tip_ == "C") {
            p_tip = C;
        } else if (tip_ == "B") {
            p_tip = B;
        } else if (tip_ == "T") {
            p_tip = T;
        } else if (tip_ == "K") {
            p_tip = K;
        }
    }

    void setType(const std::string &type_) {
        Piesa::type = type_;
    }

    [[nodiscard]] const std::string &getType() const {
        return type;
    }

    [[nodiscard]] const std::vector<std::string> &getResurse() const {
        return resurse;
    }
};

class Pion : public Piesa {
private:
    std::vector<Locatie> mutari_posibile;
public:
    Pion() : Piesa() {
        p_tip = Piesa::P;
        resurse.push_back("apa");
        resurse.push_back("mancare");
    }

    // Copy constructor
    Pion(const Pion &other) : Piesa(other), mutari_posibile(other.mutari_posibile) {}

    // Copy assignment operator
    Pion &operator=(const Pion &other) {
        if (this != &other) {
            Piesa::operator=(other);
            mutari_posibile = other.mutari_posibile;
        }
        return *this;
    }

    std::vector<Locatie> muta(Locatie const &locatie_, Piesa const &p) override;
};

class Cal : public Piesa {
    std::vector<Locatie> mutari_posibile;
public:
    Cal() : Piesa() {
        p_tip = Piesa::C;
        resurse.push_back("apa");
        resurse.push_back("mancare");
        resurse.push_back("arma");
    }

    // Copy constructor
    Cal(const Cal &other) : Piesa(other), mutari_posibile(other.mutari_posibile) {}

    // Copy assignment operator
    Cal &operator=(const Cal &other) {
        if (this != &other) {
            Piesa::operator=(other);
            mutari_posibile = other.mutari_posibile;
        }
        return *this;
    }

    std::vector<Locatie> muta(Locatie const &locatie_, Piesa const &p) override;
};

class Nebun : public Piesa {
private:
    std::vector<Locatie> mutari_posibile;
public:
    Nebun() : Piesa() {
        p_tip = Piesa::B;
        resurse.push_back("apa");
        resurse.push_back("mancare");
        resurse.push_back("arma");
    }

    // Copy constructor
    Nebun(const Nebun &other) : Piesa(other), mutari_posibile(other.mutari_posibile) {}

    // Copy assignment operator
    Nebun &operator=(const Nebun &other) {
        if (this != &other) {
            Piesa::operator=(other);
            mutari_posibile = other.mutari_posibile;
        }
        return *this;
    }

    std::vector<Locatie> muta(Locatie const &locatie_, Piesa const &p) override;
};

class Turn : public Piesa {
private:
    std::vector<Locatie> mutari_posibile;
public:
    Turn() : Piesa() {
        p_tip = Piesa::T;
        resurse.push_back("arma");
        resurse.push_back("piatra");
        resurse.push_back("apa");
        resurse.push_back("mancare");
    }

    // Copy constructor
    Turn(const Turn &other) : Piesa(other), mutari_posibile(other.mutari_posibile) {}

    // Copy assignment operator
    Turn &operator=(const Turn &other) {
        if (this != &other) {
            Piesa::operator=(other);
            mutari_posibile = other.mutari_posibile;
        }
        return *this;
    }

    std::vector<Locatie> muta(Locatie const &locatie_, Piesa const &p) override;
};

class Rege : public Piesa {
private:
    std::vector<Locatie> mutari_posibile;
public:
    Rege() : Piesa() {
        p_tip = Piesa::K;
        //resurse.push_back("arma");
        resurse.push_back("piatra");
        resurse.push_back("apa");
        resurse.push_back("mancare");
    }

    // Copy constructor
    Rege(const Rege &other) : Piesa(other), mutari_posibile(other.mutari_posibile) {}

    // Copy assignment operator
    Rege &operator=(const Rege &other) {
        if (this != &other) {
            Piesa::operator=(other);
            mutari_posibile = other.mutari_posibile;
        }
        return *this;
    }

    std::vector<Locatie> muta(Locatie const &locatie_, Piesa const &p) override;
};

#endif
