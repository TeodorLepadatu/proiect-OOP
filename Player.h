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
    Player() : curr_piece(nullptr) {} // Initialize curr_piece to nullptr in the default constructor

    // Destructor to deallocate memory properly
    ~Player() {
        delete curr_piece;
    }

    Player(const Player &other) : nr(other.nr), inventar(other.inventar), mutari_disponibile(other.mutari_disponibile) {
        // Properly handle deep copy of curr_piece
        if (other.curr_piece) {
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
                    curr_piece = nullptr;
                    break;
            }
        } else {
            curr_piece = nullptr;
        }
    }

    Player &operator=(const Player &other) {
        if (this != &other) {
            // Properly handle deep copy of curr_piece
            delete curr_piece;
            if (other.curr_piece) {
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
                        curr_piece = nullptr;
                        break;
                }
            } else {
                curr_piece = nullptr;
            }
            // Copy other members
            nr = other.nr;
            inventar = other.inventar;
            mutari_disponibile = other.mutari_disponibile;
        }
        return *this;
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

    Player(int nr, const std::vector<Pacanea> &inventar, int mutariDisponibile) : nr(nr), inventar(inventar),
                                                                                  mutari_disponibile(
                                                                                          mutariDisponibile) {}

    void setCurrPiece(Piesa *currPiece) {
        curr_piece = currPiece;
    }

    Piesa *getCurrPiece() const {
        return curr_piece;
    }
};
#endif
