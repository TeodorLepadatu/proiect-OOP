
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
    Piesa() : tip(""), culoare(0), locatie(0, 0) {}

    friend std::ostream &operator<<(std::ostream &os, const Piesa &piesa) {
        os << "tip: " << piesa.tip << " culoare: " << piesa.culoare << " locatie: " << piesa.locatie;
        return os;
    }

    std::string gettip() const {
        return tip;
    }

    int getculoare() const {
        return culoare;
    }

    const Locatie &getLocatie() const {
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

    std::vector<Locatie> muta_pion(Locatie const &locatie_, Piesa const &p) {
        std::vector<Locatie> mutari_posibile;
        int i = locatie_.getLinie();
        int j = locatie_.getColoana();
        mutari_posibile.clear();
        if (p.getculoare() == 1) {
            Locatie x(i + 1, j);
            mutari_posibile.push_back(x);
        } else if (p.getculoare() == 2) {
            Locatie x(i, j - 1);
            mutari_posibile.push_back(x);
        } else if (p.getculoare() == 3) {
            Locatie x(i - 1, j);
            mutari_posibile.push_back(x);
        } else {
            Locatie x(i, j + 1);
            mutari_posibile.push_back(x);
        }
        return mutari_posibile;
    }

    std::vector<Locatie> muta_cal(Locatie const &locatie_) {
        std::vector<Locatie> mutari_posibile;
        mutari_posibile.clear();
        int i = locatie_.getLinie();
        int j = locatie_.getColoana();
        if (i == 1) {
            if (j == 1) {
                Locatie x(2, 3);
                mutari_posibile.push_back(x);
                x.setLinie(3);
                x.setColoana(2);
                mutari_posibile.push_back(x);
            } else if (j == 8) {
                Locatie x(2, 6);
                mutari_posibile.push_back(x);
                x.setLinie(3);
                x.setColoana(7);
                mutari_posibile.push_back(x);
            } else if (j == 2) {
                Locatie x(3, 1);
                mutari_posibile.push_back(x);
                x.setLinie(3);
                x.setColoana(3);
                mutari_posibile.push_back(x);
                x.setLinie(2);
                x.setColoana(4);
                mutari_posibile.push_back(x);
            } else if (j == 7) {
                Locatie x(3, 8);
                mutari_posibile.push_back(x);
                x.setLinie(3);
                x.setColoana(6);
                mutari_posibile.push_back(x);
                x.setLinie(2);
                x.setColoana(5);
                mutari_posibile.push_back(x);
            } else {
                Locatie x(2, j - 2);
                mutari_posibile.push_back(x);
                x.setLinie(3);
                x.setColoana(j - 1);
                mutari_posibile.push_back(x);
                x.setLinie(3);
                x.setColoana(j + 1);
                mutari_posibile.push_back(x);
                x.setLinie(2);
                x.setColoana(j + 2);
                mutari_posibile.push_back(x);
            }
        } else if (i == 2) {
            if (j == 1) {
                Locatie x(4, 2);
                mutari_posibile.push_back(x);
                x.setLinie(3);
                x.setColoana(3);
                mutari_posibile.push_back(x);
                x.setLinie(1);
                x.setColoana(3);
                mutari_posibile.push_back(x);
            } else if (j == 2) {
                Locatie x(4, 1);
                mutari_posibile.push_back(x);
                x.setLinie(4);
                x.setColoana(3);
                mutari_posibile.push_back(x);
                x.setLinie(3);
                x.setColoana(4);
                mutari_posibile.push_back(x);
                x.setLinie(1);
                x.setColoana(4);
                mutari_posibile.push_back(x);
            } else if (j == 7) {
                Locatie x(4, 8);
                mutari_posibile.push_back(x);
                x.setLinie(4);
                x.setColoana(6);
                mutari_posibile.push_back(x);
                x.setLinie(3);
                x.setColoana(5);
                mutari_posibile.push_back(x);
                x.setLinie(1);
                x.setColoana(5);
                mutari_posibile.push_back(x);
            } else if (j == 8) {
                Locatie x(4, 7);
                mutari_posibile.push_back(x);
                x.setLinie(3);
                x.setColoana(6);
                mutari_posibile.push_back(x);
                x.setLinie(1);
                x.setColoana(6);
                mutari_posibile.push_back(x);
            } else {
                Locatie x(3, j - 2);
                mutari_posibile.push_back(x);
                x.setLinie(4);
                x.setColoana(j - 1);
                mutari_posibile.push_back(x);
                x.setLinie(4);
                x.setColoana(j + 1);
                mutari_posibile.push_back(x);
                x.setLinie(3);
                x.setColoana(j + 2);
                mutari_posibile.push_back(x);
                x.setLinie(1);
                x.setColoana(j + 2);
                mutari_posibile.push_back(x);
                x.setLinie(1);
                x.setColoana(j - 2);
                mutari_posibile.push_back(x);
            }
        } else if (i == 7) {
            if (j == 1) {
                Locatie x(5, 2);
                mutari_posibile.push_back(x);
                x.setLinie(6);
                x.setColoana(3);
                mutari_posibile.push_back(x);
                x.setLinie(8);
                x.setColoana(3);
                mutari_posibile.push_back(x);
            } else if (j == 2) {
                Locatie x(5, 1);
                mutari_posibile.push_back(x);
                x.setLinie(5);
                x.setColoana(3);
                mutari_posibile.push_back(x);
                x.setLinie(6);
                x.setColoana(4);
                mutari_posibile.push_back(x);
                x.setLinie(8);
                x.setColoana(4);
                mutari_posibile.push_back(x);
            } else if (j == 7) {
                Locatie x(5, 8);
                mutari_posibile.push_back(x);
                x.setLinie(5);
                x.setColoana(6);
                mutari_posibile.push_back(x);
                x.setLinie(6);
                x.setColoana(5);
                mutari_posibile.push_back(x);
                x.setLinie(8);
                x.setColoana(5);
                mutari_posibile.push_back(x);
            } else if (j == 8) {
                Locatie x(5, 7);
                mutari_posibile.push_back(x);
                x.setLinie(6);
                x.setColoana(6);
                mutari_posibile.push_back(x);
                x.setLinie(8);
                x.setColoana(6);
                mutari_posibile.push_back(x);
            } else {
                Locatie x(6, j - 2);
                mutari_posibile.push_back(x);
                x.setLinie(5);
                x.setColoana(j - 1);
                mutari_posibile.push_back(x);
                x.setLinie(5);
                x.setColoana(j + 1);
                mutari_posibile.push_back(x);
                x.setLinie(6);
                x.setColoana(j + 2);
                mutari_posibile.push_back(x);
                x.setLinie(8);
                x.setColoana(j + 2);
                mutari_posibile.push_back(x);
                x.setLinie(8);
                x.setColoana(j - 2);
                mutari_posibile.push_back(x);
            }
        } else if (i == 8) {
            if (j == 1) {
                Locatie x(7, 3);
                mutari_posibile.push_back(x);
                x.setLinie(6);
                x.setColoana(2);
                mutari_posibile.push_back(x);
            } else if (j == 8) {
                Locatie x(7, 6);
                mutari_posibile.push_back(x);
                x.setLinie(6);
                x.setColoana(7);
                mutari_posibile.push_back(x);
            } else if (j == 2) {
                Locatie x(6, 1);
                mutari_posibile.push_back(x);
                x.setLinie(6);
                x.setColoana(3);
                mutari_posibile.push_back(x);
                x.setLinie(7);
                x.setColoana(4);
                mutari_posibile.push_back(x);
            } else if (j == 7) {
                Locatie x(6, 8);
                mutari_posibile.push_back(x);
                x.setLinie(6);
                x.setColoana(6);
                mutari_posibile.push_back(x);
                x.setLinie(7);
                x.setColoana(5);
                mutari_posibile.push_back(x);
            } else {
                Locatie x(7, j - 2);
                mutari_posibile.push_back(x);
                x.setLinie(6);
                x.setColoana(j - 1);
                mutari_posibile.push_back(x);
                x.setLinie(6);
                x.setColoana(j + 1);
                mutari_posibile.push_back(x);
                x.setLinie(7);
                x.setColoana(j + 2);
                mutari_posibile.push_back(x);
            }
        } else {
            Locatie x(i + 1, j - 2);
            mutari_posibile.push_back(x);
            x.setLinie(i + 2);
            x.setColoana(j - 1);
            mutari_posibile.push_back(x);
            x.setLinie(i + 2);
            x.setColoana(j + 1);
            mutari_posibile.push_back(x);
            x.setLinie(i + 1);
            x.setColoana(j + 2);
            mutari_posibile.push_back(x);
            x.setLinie(i - 1);
            x.setColoana(j + 2);
            mutari_posibile.push_back(x);
            x.setLinie(i - 2);
            x.setColoana(j + 1);
            mutari_posibile.push_back(x);
            x.setLinie(i - 2);
            x.setColoana(j - 1);
            mutari_posibile.push_back(x);
            x.setLinie(i - 1);
            x.setColoana(j - 2);
            mutari_posibile.push_back(x);
        }
        return mutari_posibile;
    }

    std::vector<Locatie> muta_nebun(Locatie const &locatie_) {
        std::vector<Locatie> mutari_posibile;
        int i = locatie_.getLinie();
        int j = locatie_.getColoana();
        mutari_posibile.clear();
        for (int i1 = 1; i1 <= 8; i1++) {
            for (int j1 = 1; j1 <= 8; j1++) {
                if (abs(i - i1) == abs(j - j1) && !(i == i1 && j == j1)) {
                    Locatie x(i1, j1);
                    mutari_posibile.push_back(x);
                }
            }
        }
        return mutari_posibile;
    }

    std::vector<Locatie> muta_turn(Locatie const &locatie_) {
        std::vector<Locatie> mutari_posibile;
        int i = locatie_.getLinie();
        int j = locatie_.getColoana();
        mutari_posibile.clear();
        for (int i1 = 1; i1 <= 8; i1++) {
            for (int j1 = 1; j1 <= 8; j1++) {
                if (i1 == i || j1 == j) {
                    Locatie x(i1, j1);
                    mutari_posibile.push_back(x);
                }
            }
        }
        return mutari_posibile;
    }


    std::vector<Locatie> muta_rege(Locatie const &locatie_) {
        std::vector<Locatie> mutari_posibile;
        int i = locatie_.getLinie();
        int j = locatie_.getColoana();
        mutari_posibile.clear();
        if (i == 1) {
            if (j == 1) {
                Locatie x(2, 1);
                mutari_posibile.push_back(x);
                x.setLinie(2);
                x.setColoana(2);
                mutari_posibile.push_back(x);
                x.setLinie(1);
                x.setColoana(2);
                mutari_posibile.push_back(x);
            } else if (j == 8) {
                Locatie x(2, 8);
                mutari_posibile.push_back(x);
                x.setLinie(2);
                x.setColoana(7);
                mutari_posibile.push_back(x);
                x.setLinie(1);
                x.setColoana(7);
                mutari_posibile.push_back(x);
            } else {
                Locatie x(1, j - 1);
                mutari_posibile.push_back(x);
                x.setLinie(2);
                x.setColoana(j - 1);
                mutari_posibile.push_back(x);
                x.setLinie(2);
                x.setColoana(j);
                mutari_posibile.push_back(x);
                x.setLinie(2);
                x.setColoana(j + 1);
                mutari_posibile.push_back(x);
                x.setLinie(1);
                x.setColoana(j + 1);
                mutari_posibile.push_back(x);
            }
        } else if (i == 8) {
            if (j == 1) {
                Locatie x(7, 1);
                mutari_posibile.push_back(x);
                x.setLinie(7);
                x.setColoana(2);
                mutari_posibile.push_back(x);
                x.setLinie(8);
                x.setColoana(2);
                mutari_posibile.push_back(x);
            } else if (j == 8) {
                Locatie x(7, 8);
                mutari_posibile.push_back(x);
                x.setLinie(7);
                x.setColoana(7);
                mutari_posibile.push_back(x);
                x.setLinie(8);
                x.setColoana(7);
                mutari_posibile.push_back(x);
            } else {
                Locatie x(8, j - 1);
                mutari_posibile.push_back(x);
                x.setLinie(7);
                x.setColoana(j - 1);
                mutari_posibile.push_back(x);
                x.setLinie(7);
                x.setColoana(j);
                mutari_posibile.push_back(x);
                x.setLinie(7);
                x.setColoana(j + 1);
                mutari_posibile.push_back(x);
                x.setLinie(8);
                x.setColoana(j + 1);
                mutari_posibile.push_back(x);
            }
        }
        return mutari_posibile;
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

};

class Turn : public Piesa {
private:
    std::vector<Locatie> mutari_posibile;
public:
    Turn() {
        tip = "R";
        resurse.push_back("arma");
        resurse.push_back("piatra");
    }

};

class Rege : public Piesa {
private:
    std::vector<Locatie> mutari_posibile;
public:
    Rege() {
        tip = "K";
    }

};
#endif
