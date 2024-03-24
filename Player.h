#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include <iostream>
#include <vector>
#include "Piesa_abstracta.h"
#include "Pacanea.h"
class Player {
private:
    int nr;
    bool turn;
    Pion p1, p2, p3, p4;
    Cal c;
    Nebun n;
    Turn t;
    Rege r;
    std::vector<Pacanea> inventar;
    int mutari_disponibile;
public:
    Player() : nr(0), turn(false), p1(), p2(), p3(), p4(), c(), n(), t(), r(), mutari_disponibile(0) {}
    int getNr() const {
        return nr;
    }

    void setNr(int nr) {
        Player::nr = nr;
    }

    void setTurn(bool turn) {
        Player::turn = turn;
    }

    const std::vector<Pacanea> &getInventar() const {
        return inventar;
    }

    //Player(int nr, const Rege &r) : nr(nr), r(r) {}
    Pion getp1() const {
        return p1;
    }

    Pion getp2() const {
        return p2;
    }

    Pion getp3() const {
        return p3;
    }

    Pion getp4() const {
        return p4;
    }

    int getMutariDisponibile() const {
        return mutari_disponibile;
    }
    //void setPionLocation(int index, const Locatie &locatie) {
    //     if (index >= 0 && index < p.size()) {
    //        p[index].setLocatie(locatie);
    //    } else {
    //        std::cout << "Nu mai fi prost si muta pionul ca un om normal" << std::endl;
    //   }
    // }
};

#endif
