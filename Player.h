#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include <iostream>
#include <vector>
#include <memory>
#include "Piesa_abstracta.h"
#include "Pacanea.h"
class Player {
private:
    int nr{};
    Piesa *curr_piece;
    std::vector<Pacanea> inventar;
    int mutari_disponibile{};

public:
    Player(const Player &other) {
        switch (other.curr_piece->getTip()) {
            case Piesa::P:
                curr_piece = new Pion(*dynamic_cast<Pion *>(other.curr_piece));
                break;
            case Piesa::C:
                curr_piece = new Cal(*dynamic_cast<Cal *>(other.curr_piece));
                break;
            case Piesa::B:
                curr_piece = new Nebun(*dynamic_cast<Nebun *>(other.curr_piece));
                break;
            case Piesa::T:
                curr_piece = new Turn(*dynamic_cast<Turn *>(other.curr_piece));
                break;
            case Piesa::K:
                curr_piece = new Rege(*dynamic_cast<Rege *>(other.curr_piece));
                break;
            default:
                // eroare, caz lipsă!!!
                curr_piece = nullptr;
                break;
        }
    }
    [[nodiscard]] int getNr() const {
        return nr;
    }

    void setNr(int nr_) {
        Player::nr = nr_;
    }


    [[nodiscard]] const std::vector<Pacanea> &getInventar() const {
        return inventar;
    }

    [[nodiscard]] int getMutariDisponibile() const {
        return mutari_disponibile;
    }


};

#endif
