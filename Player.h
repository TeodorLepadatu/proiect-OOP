
#include <iostream>
#include "Piesa_abstracta.h"
#include "Pacanea.h"
#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

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
public:
    int getNr() const {
        return nr;
    }

    void setTurn(bool turn) {
        Player::turn = turn;
    }

    const std::vector<Pacanea> &getInventar() const {
        return inventar;
    }
};

#endif
