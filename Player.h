#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include <iostream>
#include <vector>
#include "Piesa_abstracta.h"
#include "Pacanea.h"
class Player {
private:
    int nr;
    //bool yourmove;
    Pion p1, p2, p3, p4;
    Cal c;
    Nebun n;
    Turn t;
    Rege r;
    std::vector<Pacanea> inventar;
    int mutari_disponibile;
public:
    Player() : nr(0), p1(), p2(), p3(), p4(), c(), n(), t(), r(), mutari_disponibile(0) {}
    int getNr() const {
        return nr;
    }

    void setNr(int nr_) {
        Player::nr = nr_;
    }


    const std::vector<Pacanea> &getInventar() const {
        return inventar;
    }

    int getMutariDisponibile() const {
        return mutari_disponibile;
    }

    friend std::ostream &operator<<(std::ostream &os, const Player &player) {
        os << "nr: " << player.nr << " p1: " << player.p1 << " p2: " << player.p2 << " p3: " << player.p3 << " p4: "
           << player.p4 << " c: " << player.c << " n: " << player.n << " t: " << player.t << " r: " << player.r
           << " inventar: " << " mutari_disponibile: " << player.mutari_disponibile;
        return os;
    }
};

#endif
